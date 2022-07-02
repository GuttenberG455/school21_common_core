# Module 02
[Subject](https://cdn.intra.42.fr/pdf/pdf/52150/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_02.pdf)

***100/100 SUCCESS***

---
## Project topics:
Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form

## List of exercises:
* ### ex00: My First Class in Orthodox Canonical Form

Create a class in Orthodox Canonical Form that represents a fixed-point number:
Private members:
- An integer to store the fixed-point number value.
- A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.
Public members:
- A default constructor that initializes the fixed-point number value to 0.
- A copy constructor.
- A copy assignment operator overload.
- A destructor.
- A member function *int getRawBits( void ) const;* that returns the raw value of the fixed-point value.
- A member function *void setRawBits( int const raw );* that sets the raw value of the fixed-point number.


* ### ex01: Towards a more useful fixed-point number class

The previous exercise was a good start but our class is pretty useless. It can only represent the value 0.0.
Add the following public constructors and public member functions to your class:
- A constructor that takes a constant integer as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
- A constructor that takes a constant floating-point number as a parameter.
It converts it to the corresponding fixed-point value. The fractional bits value is
initialized to 8 like in exercise 00.
- A member function *float toFloat( void ) const;*
that converts the fixed-point value to a floating-point value.
- A member function *int toInt( void ) const;*
that converts the fixed-point value to an integer value.
And add the following function to the Fixed class files:
- An overload of the insertion («) operator that inserts a floating-point representation
of the fixed-point number into the output stream object passed as parameter.


* ### ex02:  Now we’re talking

Add public member functions to your class to overload the following operators:
- The 6 comparison operators: >, <, >=, <=, == and !=.
- The 4 arithmetic operators: +, -, *, and /.
- The 4 increment/decrement (pre-increment and post-increment, pre-decrement and
post-decrement) operators, that will increase or decrease the fixed-point value.
Add these four public overloaded member functions to your class:
• A static member function min that takes as parameters two references on fixed-point
numbers, and returns a reference to the smallest one.
• A static member function min that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the smallest one.
• A static member function max that takes as parameters two references on fixed-point
numbers, and returns a reference to the greatest one.
• A static member function max that takes as parameters two references to constant
fixed-point numbers, and returns a reference to the greatest one.


* ### ex03: BSP

Let’s start by creating the class Point in Orthodox Canonical Form that represents
a 2D point: </br>
Private members:
- A Fixed const attribute x.
- A Fixed const attribute y.
- Anything else useful.
Public members:
- A default constructor that initializes x and y to 0.
- A constructor that takes as parameters two constant floating-point numbers.
It initializes x and y with those parameters. </br>
- A copy constructor.
- A copy assignment operator overload.
- A destructor.
- Anything else useful.
To conclude, implement the following function in the appropriate file:
*bool bsp( Point const a, Point const b, Point const c, Point const point);*
- a, b, c: The vertices of our beloved triangle.
- point: The point to check.
- Returns: True if the point is inside the triangle. False otherwise.
Thus, if the point is a vertex or on edge, it will return False.

