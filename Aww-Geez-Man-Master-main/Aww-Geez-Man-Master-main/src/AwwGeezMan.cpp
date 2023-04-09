
#include "Morty.hpp"


 int main(int agc, char** agv) {
  
  // std::cout << agc;
  // std::cout << agv[0];
  args data2;
  data2.dim = dimension::UNK;
  data2 = parse_args(agc, agv);
  if (data2.valid == true) {
  // std::cout << q <<endl;
  if (data2.dim == dimension::C137) {
    cout << "Morty C137 says:" << endl;
    C137::Morty(data2.start,data2.stop,data2.step);

  } else if (data2.dim == dimension::Z286) {
    cout << "Morty Z286 says:" << endl;
    Z286::Morty(data2.start,data2.stop,data2.step);
  }
  }
  else {
    return 0;
  }

  return 0;
}
