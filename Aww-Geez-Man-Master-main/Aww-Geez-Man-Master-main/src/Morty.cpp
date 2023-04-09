#include "Morty.hpp"

args parse_args(int argc, char ** argv) {
  char String[50];
  args data;
  int arg;
  data.step = 1;
  data.valid = true;
  
  for (int j = 1; j < (argc); j++) {
    
    if (std::sscanf(argv[j], "--start=%d", &arg)) { //chack back
      data.start = arg;
    } else if (std::sscanf(argv[j], "--step=%d", &arg)) {
      data.step = arg;
    } else if (std::sscanf(argv[j], "--stop=%d", &arg)) {
      data.stop = arg;
    } else if (std::sscanf(argv[j], "--dimension=%s", String)) {
      cout << String << endl;
      if (std::strcmp("Z286", String) == 0) {
        data.dim = dimension::Z286;
      } else if (std::strcmp("C137", String) == 0) {
        data.dim = dimension::C137;
      } else {
        data.valid = false;
        data.dim = dimension::UNK;
        break;
      }
    } else {
      data.valid = false;
    }
  }
    return data;
  }
  
namespace C137 {
  void Morty(int v, int b, int d) {
    for (int i = v; i < b + 1; i = i + d) {
       if ((i % 3) == 0) {
      cout << i << ":" << " Aww" << endl;
    } else if ((i % 5) == 0) {
      cout << i << ":" << " Geez" << endl;
    } else if ((i%15) == 0) {
      cout << i << ":" <<  "Aww Geez Man" << endl;
    }
  }
}
  void Morty(int v, int b) {

    Morty (v, b, 1);
  }
}
namespace Z286 {
  void Morty(int v, int b, int d) {
    for (int i = v; i < b + 1; i = i + d) {
       if ((i % 3) == 0) {
      cout << i << ":" << " wwA" << endl;
    } else if ((i % 5) == 0) {
      cout << i << ":" << " zeeG" << endl;
    } else if ((i%15) == 0) {
      cout << i << ":" <<  "naM zeeG wwA" << endl;
    }
    }
  }

  void Morty(int v, int b) {
     Morty (v, b, 1);
  }
}
