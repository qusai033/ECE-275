# ECE 275 Homework 2: Aww Geez Man

> Aww Geez Man, what if there was a Morty in another dimension who said everything backwards?


## Program Requirements
You are to write a program to the following specifications:

1. Your program *shall* receive command line arguments. The possible arguments are, ***in no particular order***:
 - "--start={int}"
 - "--stop={int}"
 - "--step={int}"
 - "--dimension={str}"
 
 where "{int}" denotes an integer parameter and "{str}" denotes a string parameter. Your program *shall* receive these arguments in any order, `e.g., ./AwwGeezMan --step=2 --stop=10 --start=1 --dimension=C137`. Note that the option "--step" is optional and, if not provided, is assumed to be 1.
 
2. Your program *shall* define a struct type
	
	```c++
	struct args {
	  dimension dim;
	  int start, stop, step;
	  bool valid;
	};
	```
	
which holds the integer values for start, stop, and step along with an enumeration value for the dimension and a flag to tell if the arguments are valid or not. 
Note that the enumeration is given as `enum class dimension {UNK = -1, C137, Z286};`. 
This is a "[scoped enumeration](https://www.learncpp.com/cpp-tutorial/scoped-enumerations-enum-classes/)" which is a C++ feature not found in C. 
_Please review the scoped enumeration outside of class._
	
3. The program argument *shall* be parsed via a function declared as `args parse_args(int, char**);` which receives the number of program arguments and a pointer to character pointers which hold the program arguments as supplied to `main(int, char**)` and returns the struct type `args`. If the arguments provided to the function are not valid (i.e., if there are not enough arguments or if there are unrecognized arguments) then `args::valid` should be set to `false` otherwise set to `true`. 

4. Your program *shall* utilize the command line arguments to print the following:
	- Print out the phrase "Morty {dimension} says:" based on being either in the C137 dimension or the Z286 dimension, e.g., "Morty C137 says:"
	- Then loop from `start` to `stop` (inclusively) in steps of `step` (based on the command line arguments) and, at each loop iteration `i`, you *shall* print "{i}: {phrase}" where "phrase" is determined by
		- if `i` is a multiple of 15 phrase is "Aww Geez Man"
		- if `i` is a multiple of 5 phrase is "Geez"
		- if `i` is a multiple of 3 phrase is "Aww"
	- If the dimension argument is C137 then you *shall* print these phrases normally. If the dimension argument is Z286 you *shall* print these phrases in reverse. 

5. Your program *shall* perform the printing operation via a pair of overloaded functions residing in two different namespace. You must declare functions `Morty` which returns `void` and accepts either 2 or 3 `int`-type arguments in both the namespace `C137` and `Z286`. These would be called, e.g., `C137::Morty(start, stop, step)`. Note that the order of parameters does not matter as the unit-tests (see below) do not meaningfully call these functions. 

	
## Example Program Output
Given the program call `./AwwGeezMan --start=1 --stop=20 --dimension=C137` your program should output

```
Morty C137 says:
1: 
2: 
3: Aww
4: 
5: Geez
6: Aww
7: 
8: 
9: Aww
10: Geez
11: 
12: Aww
13: 
14: 
15: Aww Geez Man
16: 
17: 
18: Aww
19: 
20: Geez
```

Given the program call `./AwwGeezMan --start=10 --stop=30 --dimension=Z286` your program should output

```
Morty Z286 says:
10: zeeG
11: 
12: wwA
13: 
14: 
15: naM zeeG wwA
16: 
17: 
18: wwA
19: 
20: zeeG
21: wwA
22: 
23: 
24: wwA
25: zeeG
26: 
27: wwA
28: 
29: 
30: naM zeeG wwA
``` 

Given the program call `./AwwGeezMan --step=2 --start=10 --stop=30 --dimension=C137` your program should output

```
Morty C137 says:
10: Geez
12: Aww
14: 
16: 
18: Aww
20: Geez
22: 
24: Aww
26: 
28: 
30: Aww Geez Man
```

## Assignment Tests
### C++ Unit Tests:
I will programmatically test the function `args parse_args(int, char**)` via a suite of unit tests. These tests construct arguments (either hardcoded or randomly being both valid and invalid) and test

1.  If the arguments passed are valid (e.g., `./AwwGeezMan --dimension=Z286 --start=1 --stop=25`) that `args::valid` is set `true` and that the members in the struct match the arguments passed. 
2. If the arguments are invalid then test that `args::valid` is set to `false`

Please note that the unit tests makes a compile-time check (by simply trying to compile the required `Morty` functions) to ensure that you have declared the correct functions in the correct namespaces. The unit test does not actually call these functions in any meaningful way. 

### Output Comparison Tests:
I will also programmatically test your program's text output (disregarding changes in whitespace, e.g., you add 2 spaces instead of 1 or a trailing space). You will receive the diff-ed file so that you can identify where your program does not match the solution. 

Note that for the output comparison test I will not provide your program with invalid arguments. 

## Grading:
There are a total of 4 unit-tests and 1 output comparison test. Each test is graded on a binary 1/0 score and your final score is computed out of 1 (i.e,. a 75% is 0.75) based on how many of the 5 total tests you pass. Note that code that does not compile receives no credit! I will take your highest score. Note that you will be given your score in a text file after each grader run. 
