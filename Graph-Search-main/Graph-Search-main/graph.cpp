// c++ STL containers
#include <vector>
#include <map>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>
// LEMON
#include "lemon/smart_graph.h"
#include "lemon/dijkstra.h"


std::istream& get_input_handle(const int ac, std::ifstream& fhandle, const char* fname) {
  if (ac == 4) {
    fhandle.open(fname);
    assert(fhandle.is_open());
    return fhandle;
  }
  else {
    return std::cin;
   
    }
}

struct Arc
{
    std::string sourceID;
    std::string targetID;
    int cost;
};

int main (int argc, char** argv)
{
// std::cout << "hello world\n";


  //instantiate directed smart graph
  lemon::SmartDigraph g;
  
  //instantiate a LEMON map of arc costs
  lemon::SmartDigraph::ArcMap<int> costMap(g);  // for arc costs

  lemon::SmartDigraph::NodeMap<std::string> nodeMap(g);


  std::ifstream inp_fhandle;
  std::istream& fhandle = get_input_handle(argc, inp_fhandle, argv[1]);
  std::string file_line;

  std::map<std::string, int> nodes;
  std::map<std::string, int> temp_map;
  std::vector<Arc> arcs; //for edges

  int i = 0;
  std::string node1, node2, dummy;
  int weight;
  while(std::getline(fhandle, file_line)) {
      // std::cout << "Line " << i << ": " << file_line << std::endl;
      // i++;
    std::istringstream ss (file_line);
    // ss >> dummy;
    ss >> node1;
    ss >> node2;
    ss >> weight;

    // check if the new nodes exists before 
    if ( temp_map.find(node1) == temp_map.end()) {
      // not found
      temp_map.insert(std::make_pair(node1,i));
      i++;
    } 

    if ( temp_map.find(node2) == temp_map.end()) {
      // not found
      temp_map.insert(std::make_pair(node2,i));
      i++;
    } 

    // now lets add the edges (arcs)
    Arc temp = {"", "", -1};
    temp.sourceID = node1;
    temp.targetID = node2;
    temp.cost = weight;

    arcs.push_back(temp);
  }


  //"-----------------------------------------------------------------------------------------"

  std::map<std::string, int>::iterator it;
  int j;
  for (it = temp_map.begin(), j =0; it != temp_map.end(); it++, j++){

      // std::cout << it->first << "----" << it->second << std::endl;
      nodes.insert(std::make_pair(it->first,j));

  }


  //populate graph
  //nodes first
  lemon::SmartDigraph::Node currentNode;
  for (auto nodesIter = nodes.begin(); nodesIter != nodes.end(); ++nodesIter)
  {
      std::string key = nodesIter->first;
      // std::cout << "key: "<< key << "\n";
      currentNode = g.addNode();
      nodeMap[currentNode] = key;
      // nodeMap[key]
  }


  //then the arcs with the costs through the cost map
  lemon::SmartDigraph::Arc currentArc;
  for (auto arcsIter = arcs.begin(); arcsIter != arcs.end(); ++arcsIter)
  {
      int sourceIndex = nodes.at(arcsIter->sourceID);
      int targetIndex = nodes.at(arcsIter->targetID);
  
      lemon::SmartDigraph::Node sourceNode = g.nodeFromId(sourceIndex);
      lemon::SmartDigraph::Node targetNode = g.nodeFromId(targetIndex);
  
      currentArc = g.addArc(sourceNode, targetNode);
      costMap[currentArc] = arcsIter->cost;
  }


  std::string Snode = argv[2];
  std::string Enode = argv[3];

  lemon::SmartDigraph::Node startN = g.nodeFromId( nodes.at(Snode) );
  lemon::SmartDigraph::Node endN = g.nodeFromId( nodes.at(Enode) );

    // defining the type of the Dijkstra Class
  using SptSolver = lemon::Dijkstra<lemon::SmartDigraph, lemon::SmartDigraph::ArcMap<int>>;
  
  SptSolver spt(g, costMap); // object of type Dijkstra class

  int reachable = spt.run(startN, endN);

  if (reachable)
  {

    std::vector<lemon::SmartDigraph::Node> path;
    for (lemon::SmartDigraph::Node v = endN; v != startN; v = spt.predNode(v))
    {
      if (v != lemon::INVALID && spt.reached(v)) //special LEMON node constant
      {
         path.push_back(v);
        //  std::cout << "traversing: " << nodeMap[endN] << "\n";
      }
    }
    path.push_back(startN);

    int cost = spt.dist(endN);

    //print out the path with reverse iterator
    std::cout << cost << ":";
    for (auto p = path.rbegin(); p != path.rend(); ++p)
        std::cout << " "<< nodeMap[*p];

    std::cout << std::endl;
  }
  else {
    std::cout << "No path exists from " << Snode << " to " << Enode << "\n";
  }

  arcs.clear(); // clear the arc vector
  return 0;
}
