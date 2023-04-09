# ECE 275 Homework 1: The Personal Space Show!!

Welcome to the Personal Space Show!!


> One: Personal Space
> 
> Two: Personal Space
>
> Three: Stay out of my personal space
> 
> Four: Keep away from my personal space
> 
> Five: Get outta dat personal space
> 
> Six: Stay away from my personal space
> 
> Seven: Keep away from dat personal space
> 
> Eight: Personal space
> 
> Nine: Personal space

Homework 1: "Personal Space" will test your ability to:

* Write and compile a simple C++ program
* Recieve and parse command line arguments
* Perform basic control flow and loops (as discussed in ECE 175)

## Program Requirements
You are to write a program to the following specifications:

1. Your program *shall* recieve an unknown number of command line arguments.
2. Your program *shall* print a greeting and the appropriate statement from Mr. Phillip Jacobs (the host of "The Personal Space Show") for each command line argument given an interger command line argument. E.g., if the command line argument is "1", print "One: Personal Space". E.g., if the command line argument is "7", print "Seven: Keep away from dat personal space". 
3. Your program *shall* print "N: Number not recognized" where N is some integer outside of [1, 9]. E.g., if the command line argument is "101", print "101: Number not recognized". 

Below see two examples. Note that line starting with "#" should not be printed in your program and are there only to provide human and machine readable information. 

An example with one command line argument:

```
# Command arguments: 6
# Solution:
Welcome to the Personal Space Show!!

Six: Stay away from my personal space
```

Another example with multiple command line arguments:

```
# Command arguments: 1 2 3 4 5 6 7 8 9
# Solution:
Welcome to the Personal Space Show!!

One: Personal space
Two: Personal space
Three: Stay out of my personal space
Four: Keep away from my personal space
Five: Get outta dat personal space
Six: Stay away from my personal space
Seven: Keep away from dat personal space
Eight: Personal space
Nine: Personal space
```

## Writing Your Program
The GitLab repository is populated with the following directory structure:

```
.
├── .gitlab-ci.yml
├── CMakeLists.txt
├── README.md
└── src
    ├── CMakeLists.txt
    └── PersonalSpace.cpp
```
You do NOT need to edit *anything* except for ```PersonalSpace.cpp```. Please do NOT edit the CMakeLists.txt file. 

### A brief note on command line arguments:
If you have some program who's binary executable is named 'program' then you can execute the program using the ```./program``` command. In this example, ```argc``` would be one because the name of the executable is always the 0<sup>th</sup> command line argument. Therefore, ```*(argv)``` would be equal to "program". If the program was called as ```./program first second third``` then ```argc``` would be equal to 4 and, e.g., ```*(argv + 2)``` would equal "second". 

### Convert type `char*` to type `int`
Command line arguments are given as type `char*` where the i<sup>th</sup> command line argument is accesed as `char* ith_arg = *(argv + i)`. It may be useful to use a `switch` statement which requires integer type input. To convert between type `char*` and type `int` see [the `std::atoi( )` function](https://en.cppreference.com/w/cpp/string/byte/atoi)

### Incrimental Buildup
Breaking this task into chunks, there are some main things you want to accomplish:

- [ ] Loop over the number of command lines given (using a ```for``` or ```while``` or ```do``` loop) and parse the i<sup>th</sup> command line argument. To test this, print it back out to the console
- [ ] Print the appropriate statement from Mr. Jacobs given the interger number. This can be accomplished using an ```if```-```else if```-```else``` statement or a ```switch``` statement. 

## Useful Outside Materials
- [Control flow tutorial] (http://www.cplusplus.com/doc/tutorial/control/)
- [Parsing command line arguments] (http://www.cplusplus.com/articles/DEN36Up4/)

## Testing Your Program
The program will be tested using the autograder system as discussed in class. This assignment will only be graded using the output comparison tools. Each test will generate an "artifact" which contains your results score and a zip file. Output comparisons which do not pass will be given as an HTML file. 
