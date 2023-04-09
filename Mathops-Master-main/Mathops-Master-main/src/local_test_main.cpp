#include <iostream>
#include <cmath>
#include <valarray>

#include "MathOps.hpp"

// Declare a function which accepts a std::valarray of some type
// denoted by the template parameter 'T' to print the values of that array
// e.g., [1, 2, 3]
template<typename T>
void print_valarray(const std::valarray<T>& arr) {
  std::cout << "[";
  for (unsigned int i = 0; i != (arr.size()-1); ++i) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[arr.size()-1]<< "]";
}

int main() {
  // Below is an example of how the MathOps class will be tested. The default
  // constructor should be add and when do_operation is called 
  MathOps add_opr;
  std::cout << "1 + 5 = " << add_opr.do_operation(1, 5) << std::endl;

  // and another example where the operation is explicitly provided via the
  // constructor method
  MathOps sub_opr(ops::subtract);
  std::cout << "1 - 5 = " << sub_opr.do_operation(1, 5) << std::endl;

#if defined EXTRA_CREDIT
  // The extra credit takes a template parameter for the type of
  // values to operate on
  MathOps<int> opr2(ops::subtract);
  std::cout << "1 - 5 = " << opr2.do_operation(1, 5) << std::endl;

  MathOps<float> opr3(ops::multiply);
  std::cout << "pi * 5 = " << opr3.do_operation(M_PI, 5) << std::endl;

  // See the std::valarray documentation on cplusplus.com or cppreference.com
  // Ponder: why does this not work with std::vector?? Try it and see what the
  // compiler throws as an error then see if you can google your way to a solution.
  // We'll discuss why in lecture shortly.
  typedef std::valarray<float> varr;
  varr a1 = {1, 2, 3, 4, 5};
  varr a2 = {10, 11, 12, 13, 14};

  MathOps<varr> opr4(ops::divide);
  auto a3 = opr4.do_operation(a2, a1);
  print_valarray(a2);
  std::cout << " divided by ";
  print_valarray(a1);
  std::cout << " equals ";
  print_valarray(a3);
  std::cout << std::endl;
#endif
  
  
  return 0;
}
