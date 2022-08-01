# Module 01
[Subject](https://cdn.intra.42.fr/pdf/pdf/52149/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_01.pdf)

***100/100 SUCCESS***

---
## Project topics:
Memory allocation, pointers to members, references, switch statement

## List of exercises:
* ### ex00: BraiiiiiiinnnzzzZ
First, implement a **Zombie** class. It has a string private attribute *name*. Add a member function *void announce( void );* to the Zombie class. Zombies announce themselves as follows: </br>

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

Implement a *Weapon* class that has:
- A private attribute *type*, which is a string.
- A *getType()* member function that returns a const reference to type.
- A *setType()* member function that sets type using the new one passed as parameter.
	
Now, create two classes: *HumanA* and *HumanB*. They both have a Weapon and a
name. They also have a member function *attack()* that displays (of course, without the
angle brackets):

`<name> attacks with their <weapon type>`

HumanA and HumanB are almost the same except for these two tiny details:
- While HumanA takes the Weapon in its constructor, HumanB doesn’t.
- HumanB may not always have a Weapon, whereas HumanA will always be armed.

* ### ex04: Sed is for losers

Create a program that takes three parameters in the following order: a **filename** and two strings, **s1** and **s2**.
It will open the file <filename> and copies its content into a new file <filename>.replace, replacing every occurrence of s1 with s2.

* ### ex05: Harl 2.0

You have to create a *Harl* class with the following private member functions:
- void debug( void );
- void info( void );
- void warning( void );
- void error( void );

Harl also has a public member function that calls the four member functions above
depending on the level passed as parameter:
`void complain( std::string level );`

The goal of this exercise is to use pointers to member functions. Harl has to complain without using a forest of if/else if/else. 

* ### ex06: Harl filter

Create a program that takes as parameter one of the four levels. It will display all
messages from this level and above. You must use, the switch statement in this exercise.

