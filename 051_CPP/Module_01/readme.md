# Module 01
[Subject](https://cdn.intra.42.fr/pdf/pdf/52149/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_01.pdf)

***100/100 SUCCESS***

---
## Project topics:
Memory allocation, pointers to members, references, switch statement

## List of exercises:
* ### ex00: BraiiiiiiinnnzzzZ
First, implement a *Zombie* class. It has a string private attribute *name*. Add a member function *void announce( void );* to the Zombie class. Zombies announce themselves as follows: </br>

	<name>: BraiiiiiiinnnzzzZ...

Then, implement the two following functions:
- Zombie* newZombie( std::string name );

It creates a zombie, name it, and return it so you can use it outside of the function
scope.
- void randomChump( std::string name );

It creates a zombie, name it, and the zombie announces itself. Zombies must be destroyed when you don’t need them anymore. The destructor must print a message with the name of the zombie for debugging purposes.

* ### ex01: Moar brainz!
Time to create a horde of Zombies! Implement the following function in the appropriate file:

Zombie* zombieHorde( int N, std::string name );

It must allocate N Zombie objects in a single allocation. Then, it has to initialize the zombies, giving each one of them the name passed as parameter. The function returns a pointer to the first zombie.

* ### ex02: HI THIS IS BRAIN

Write a program that contains:
- A string variable initialized to "HI THIS IS BRAIN".
- *stringPTR*: A pointer to the string.
- *stringREF*: A reference to the string. </br>
Our program has to print:
- The memory address of the string variable.
- The memory address held by *stringPTR*.
- The memory address held by *stringREF*. </br>
And then:
- The value of the string variable.
- The value pointed to by *stringPTR*.
- The value pointed to by *stringREF*.

* ### ex03: Unnecessary violence

* ### ex04: Sed is for losers

* ### ex05: Harl 2.0

* ### ex06: Harl filter

