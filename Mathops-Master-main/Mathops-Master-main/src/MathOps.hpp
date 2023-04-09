#ifndef MATH_OP_H_
#define MATH_OP_H_
#include <iostream>
#include <cmath>
#include <valarray>

#define EXTRA_CREDIT

enum class ops {add, subtract, multiply, divide};
template<class T = double>
class MathOps{
public:
  //mathOps():to_do(_to_do){}
  MathOps(){
    to_do = ops::add;
  }
MathOps(ops _to_do){
  to_do = _to_do;
}

T do_operation(T lhs, T rhs){
  switch(to_do){
    case ops::add: return (lhs + rhs);
    case ops::subtract: return (lhs - rhs);
    case ops::multiply: return (lhs * rhs);
    case ops::divide: return (lhs/rhs);
  }
}
private:
ops to_do;
};

#endif
