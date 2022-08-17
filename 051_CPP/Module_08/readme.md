# Module 08
[Subject](https://cdn.intra.42.fr/pdf/pdf/52156/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_08.pdf)

***100/100 SUCCESS***

---
## Project topics:
Templated containers, iterators, algorithms

## List of exercises:
* ### ex00: Easy find

Write a function template *easyfind* that accepts a type T. It takes two parameters.
The first one has type T and the second one is an integer.

Assuming T is a container of integers, this function has to find the first occurrence
of the second parameter in the first parameter.

If no occurrence is found, you can either throw an exception or return an error value
of your choice. 



* ### ex01: Span

Develop a **Span** class that can store a maximum of N integers. N is an unsigned int
variable and will be the only parameter passed to the constructor.

This class will have a member function called *addNumber()* to add a single number
to the **Span**. It will be used in order to fill it. Any attempt to add a new element if there
are already N elements stored should throw an exception.
Next, implement two member functions: **shortestSpan()** and **longestSpan()**

They will respectively find out the shortest span or the longest span (or distance, if
you prefer) between all the numbers stored, and return it. If there are no numbers stored,
or only one, no span can be found. Thus, throw an exception.

Of course, you will write your own tests and they will be way more thorough than the
ones below. Test your **Span** at least with a minimum of 10 000 numbers. More would be
even better.



* ### ex02: Mutated abomination

The *std::stack container* is very nice. Unfortunately, it is one of the only STL Containers that is NOT iterable. That’s too bad.
You have to make the *std::stack container* iterable.

Write a **MutantStack** class. It will be implemented in terms of a *std::stack*.
It will offer all its member functions, plus an additional feature: *iterators*.
