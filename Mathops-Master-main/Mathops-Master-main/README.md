# ECE 275 Homework 3: MathOps

## Program Requirements
You are to provide a class definition for the `MathOps` class which performs some mathematical
operation on two values. 
The mathematical operation is defined as a scoped enumeration `ops` (recall from Homework 2)
with values `add`, `subtract`, `multiply`, and `divide`. 

### MathOps
- Constructor:
The `MathOps` class *shall* be default constructible with the default operation being `ops::add`.
The `MathOps` class *shall* also be constructible with an `ops`-type argument which denotes
the operation to be taken when the `do_operation` method is called. 

- Operation:
The `MathOps` class *shall* have a method `do_operation` which accepts two `double`-type parameters. 
The parameters, in order, are the left- and right-hand side of the operation, e.g., 
`do_operation(1.0, 2.0)` is `1 + 2` assuming the operation is `ops::add`.
The function should return the result of the operation as a `double` type. 

## Examples and hint
Please see the example source file in the `src` directory for how the `MathOps` class 
will be tested (and for examples in the extra credit!). 
*Please* utilize this file to test the code locally before pushing up to GitLab as this can 
drastically help with confusing compiler messages. 

As a hint: the `do_operation` method should `switch` on the operation and return the
corresponding result, e.g., `case ops::add: return (lhs + rhs)` where `lhs` and `rhs` are the 
inputs to the function *in order*. 

## Testing
The `MathOps` class is subject to unit testing. 
There are 5 tests which test the functionality of the `MathOps` class constructed (a) default, 
(b) with `ops::add`, (c) with `ops::subtract`, (d) with `ops::multiply`, 
and (e) with `ops::divide`. 
For each test case there are 2 random values given to perform the operation.

Each test is weighted as `1/5` the total score.

## Extra Credit
For extra credit equal up to 100% extra, i.e., a score of `2.0` out of `1.0`, implement
the `MathOps` class as a templated class to operate on `T`-type inputs to `MathOps::do_operation`
and return type `T` where the template parameter (herein denoted as `T`) is default to `double`. 

**Important:** to attempt the extra credit define `EXTRA_CREDIT` in the MathOps.hpp file. You 
should see a message at compile-time that extra credit is being compiled. 
Please attempt without any extra credit before working towards the extra credit as the 
rule still stands that code which does not compile receives a score of 0!
