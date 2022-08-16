# Module 07
[Subject](https://cdn.intra.42.fr/pdf/pdf/52144/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_07.pdf)

***100/100 SUCCESS***

---
## Project topics:
C++ templates

## List of exercises:
* ### ex00: Start with a few functions

Implement the following function templates:
- *swap*: Swaps the values of two given arguments. Does not return anything.
- *min*: Compares the two values passed in its arguments and returns the smallest
one. If the two of them are equal, then it returns the second one.
- *max*: Compares the two values passed in its arguments and returns the greatest one.
If the two of them are equal, then it returns the second one.

These functions can be called with any type of argument. The only requirement is
that the two arguments must have the same type and must support all the comparison
operators.


* ### ex01: Iter

Implement a function template *iter* that takes 3 parameters and returns nothing:
- The first parameter is the address of an array.
- The second one is the length of the array.
- The third one is a function that will be call on every element of the array.

Your iter function template must work with any type of array. The third parameter
can be an instantiated function template.


* ### ex02: Array

Develop a class template **Array** that contains elements of type *T* and that implements
the following behavior and functions:
- Construction with no parameter: Creates an empty array.
- Construction with an unsigned int n as a parameter: Creates an array of n elements
initialized by default.
- Construction by copy and assignment operator. In both cases, modifying either the
original array or its copy after copying musn’t affect the other array.
- You MUST use the operator new[] to allocate memory. Preventive allocation is forbidden. Your program must never access nonallocated memory.
- Elements can be accessed through the subscript operator: [ ].
- When accessing an element with the [ ] operator, if its index is out of bounds, an
std::exception is thrown.
- A member function size() that returns the number of elements in the array. This
member function takes no parameter and musn’t modify the current instance.
