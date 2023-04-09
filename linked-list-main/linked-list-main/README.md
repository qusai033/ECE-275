# ECE 275 Project 1: Linked List 
> Fun with pointers!!  
 
 ![Gary Come Home](https://memegenerator.net/img/instances/68293172.jpg)
 
Project 1 will see students creating a singly linked list. 
 
## Useful Reading:
- General Linked Lists:
	- [Wikibooks Linked List (C example)](https://en.wikibooks.org/wiki/Data_Structures/LinkedLists)
	- [Wikibooks Linked List](https://en.wikibooks.org/wiki/A-level_Computing/OCR/Unit_1.4.2_Data_Structures#Linked_List)
	- [Comp Sci Linked List](https://computersciencewiki.org/index.php/Linked_list)
	- [Templates Tutorial](https://www.cplusplus.com/doc/oldtutorial/templates/)
	- [ISO C++ Templates FAQ](https://isocpp.org/wiki/faq/templates)
- Useful Tools: 
	- [Microsoft Visual Studio Debugger](https://docs.microsoft.com/en-us/visualstudio/debugger/?view=vs-2019)
	- [Apple XCode Debugging Tools](https://developer.apple.com/library/archive/documentation/DeveloperTools/Conceptual/debugging_with_xcode/chapters/debugging_tools.html)
	- [GNU Debugger (UMichigan Tutorial)](https://web.eecs.umich.edu/~sugih/pointers/gdbQS.html)
	- [GNU Debugger Documentation/Tutorial](https://sourceware.org/gdb/current/onlinedocs/gdb/index.html#SEC_Contents)
	- [Valgrind Quickstart Guide (memory leak detector)](https://www.valgrind.org/docs/manual/quick-start.html)
	- [Memory leak detection Visual Studio](https://stackoverflow.com/questions/4790564/finding-memory-leaks-in-a-c-application-with-visual-studio)

## Linked List Requirements:
### Namespace:
The `List` class **shall** be declared within namespace `ECE275Lib::containers`

### Datatype/Composition:
- The `List` class **shall** be constructable with an arbitrary C++ datatype. Hint: The `List` class will be declared as `List<T> l` where `T` is an arbitrary data type. This may be accomplished through a template!!
- The `List` class **shall** be comprised of a user-defined type `Node` where the `Node` may similarly be constructed given an arbitrary data type, i.e., `Node<T>`. The `Node` class/struct **shall** point to the next node in the list 
  (Hint: declare as `Node<T>* next`, i.e., `Node<T>::next` should be of type `Node<T>*` and should hold the memory location of the next `Node` in the list). The `Node` type **shall** return the "next" node given a member function `Node<T>* get_next(void)`. 
- The `List` **shall** be null-terminated, i.e., the last `Node` will set it's "next" to `nullptr`


### Construction:
- The `List` class **shall** be constructable with a default constructor. This **shall** set the head of the list to `nullptr` and the list's size to 0.
- The `List` class **shall** be constructable with a parameterized constructor accepting an `unsigned int` type which denotes the length of the list. 
  This **shall** construct N `Node`s in the list where N is the input parameter. The last `Node` in the `List` **shall** always point to `nullptr` (the list is *always* NULL-terminated).

### Access:
- The `List` class **shall** provide access to the memory location of the head, i.e., the first node in the linked list, through a member function `List<T>::front()`
- The `List` class **shall** provide access to the memory location of the tail, i.e., the last node in the linked list, through a member function `List<T>::back()`
- The `List` class **shall** provide access to the i<sup>th</sup> element through a member function `List<T>::at(i)` which returns type `T` where `i` is of type `unsigned int` and the return value is the value stored in the *i* <sup>th</sup> node
- The `List` class **shall** provide a setting function to the i <sup>th</sup> element through a member function `List<T>::assign(i, d)` which returns type `void` where `i` is of type `unsigned int` and `d` is of type `T`. 
  The function shall assign the data stored in the  i<sup>th</sup> element of the list to be the value `d`. 
- The `List` **shall** return the length of the list as an unsigned integer through a member function `List<T>::size()` which accepts no input.

### Mutation:
- The `List` class **shall** remove one node in the list through a member function `List<T>::remove(unsigned int i`) where `i` denotes the index of the `Node` to remove. 
  The list's size must be updated accordingly. 
- The `List` class **shall** remove multiple nodes in the list through a member function `List<T>::remove(unsigned int s, unsigned int e`) where `s` denotes the starting index of the `Node` to remove and `e` denotes the ending index of the `Node` to remove. 
  The list's size must be updated accordingly. 
- The `List` **shall** insert an element at index `i` through a member function `List<T>::insert(unsigned int i, T d)` where `i` is the index of the new element to be inserted, e.g., the list before insertion may look like `[HEAD] (index 0) A --> (index 1) B --> (index 2) C --> nullptr` and the list after `List<T>::insert(1, N)` where `N` represents the data stored in the new `Node` will look like `[HEAD] (index 0) A --> (index 1) N --> (index 2) B --> (index 3) C --> nullptr`
- The `List` **shall** insert a separate `List` starting at index `i` through a member function `List<T>::insert(unsigned int i, List<T>& other)` (note the necessity to pass by reference!! Alternatively, students may chose to define a copy constructor for their `List` class). 
  E.g., the list before insertion of another list may look like `[HEAD] (index 0) A --> (index 1) B --> (index 2) C --> nullptr` and the list after `List<T>::insert(1, other)` where `other` may look like `[HEAD] (index 0) Z --> (index 1) Y --> nullptr` will look like `[HEAD] (index 0) A --> (index 1) Z --> (index 2) Y --> (index 3) B --> (index 4) C --> nullptr` 


## Testing Framework:
### Requirements:
- General:
	- Student code may ***NOT*** include any C++ STL sequence containers. The inclusion of any disallowed header will result in zero credit as simply wrapping a library class does not satisfy the requirement to construct a linked list. Test name: "RequirementsTester"
	- Note that this is checked via the Clang compiler which dumps an Abstract Syntax Tree to a formatted output which is then `grep`ped through and it is impossible to circumvent this requirement!
- List class:
	- The `List` class will be tested using the method names as defined above
	- The tester will compare each element of the solution and student list and will print a formatted table with both values of the list with a marking `__fail__` at each row (corresponding to the index) where the tester and solution differ. 
		Note that the tester output will be given via the test artifacts as a file. 
		To view the results of each test download the file and open in your browser
	- Each test will be run for various data types types, e.g., `List<unsigned int> l`. Note that proper use of the C++ template can provide this functionality without further effort on the part of the student, i.e., you should not have to do anything special to prepare for generic data types
	- There are 4 separate tests run:
		- test\_case\_construction: tests the default and parameterized constructors
		- test\_case\_push_back: tests the `push_back` method to create a list
		- test\_case\_individual_ops: tests the `insert` and `remove` methods for single elements
		- test\_case\_multiple_ops: tests the `insert` and `remove` methods for removing multiple elements and inserting a whole list

### Grading:
Scores are calculated upon each tester run. Please see the tests weight and final score in the results file. Note that if your program experiences a segmentation fault subsequent tests will not run and will result in a score of 0 for those tests! A warning will be issued when compiling scores. 

## Development Tips:
1. Draw with pen and paper the layout of the linked list so that you have a concrete reference.
2. Draw an actual picture for the `List` operations. It is useful to draw each operation and label using the variable names you intend to use in your code. 
3. Leverage member helper functions. Hint: The solution file includes a private helper function `List<T>::traverse(unsigned int i)` which returns a pointer to the i <sup>th</sup> `Node<T>` in the list. 
   Operations which are common between 2 or more functions are usually a good candidate to be placed into a helper function. 
4. Design a flowchart for each operation. This may help identify good candidates for a helper function. 
5. Run, test, and re-test *locally* so that you can leverage your local debugger!! It's so much easier to track down errors locally then to leverage the tester. 
   You are encouraged to write your own "tests" which might test your `List` class against the `std::list` (or any other sequence container) to ensure that the described operations will most likely not experience a segmentation fault in the tester. 


## Extra Credit:
For 0.25 points extra credit applied to this project score, prove that your program has no memory leaks (Hint: I would do this with the Valgrind tool linked above and mentioned briefly in class). 
Provide a **typed** report in PDF form via email to the instructor (and ensure you get a response back that your submission was recorded) detailing your methodology, tests performed, and results.
Include code *inline to the report*, i.e., place nicely formatted code snippets into the document, with proper explanations. 
You may reach out to the instructor beforehand for guidance and recommendations but this is __extra credit__ and, as such, is up to the student to figure out on their own. 
