# Module 03
[Subject](https://cdn.intra.42.fr/pdf/pdf/52158/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_03.pdf)

***100/100 SUCCESS***

---
## Project topics:
Inheritance

## List of exercises:
* ### ex00: Aaaaand... OPEN!

First, you have to implement a class!
It will be called **ClapTrap** and will have the following private attributes initialized to the values specified in brackets:
-  Name, which is passed as parameter to a constructor
-  Hit points (10), represent the health of the **ClapTrap**
-  Energy points (10)
-  Attack damage (0)

Add the following public member functions so the **ClapTrap** looks more realistic:
-  *void attack(const std::string& target);*
-  *void takeDamage(unsigned int amount);*
-  *void beRepaired(unsigned int amount);*

When ClapTrack attacks, it causes its target to lose attack damage hit points.
When ClapTrap repairs itself, it gets amount hit points back. Attacking and repairing
cost 1 energy point each. Of course, ClapTrap can’t do anything if it has no hit points
or energy points left.


* ### ex01: Serena, my love

Because you can never have enough ClapTraps, you will now create a derived robot.

It will be named **ScavTrap** and will inherit the constructors and destructor from **ClapTrap**. However, its constructors, destructor and attack() will print different messages.
Note that proper construction/destruction chaining must be shown in your tests.

When a **ScavTrap** is created, the program starts by building a **ClapTrap**. Destruction is
in reverse order. Why?
**ScavTrap** will use the attributes of **ClapTrap** and must initialize them to:
-   Name, which is passed as parameter to a constructor
-   Hit points (100), represent the health of the **ClapTrap**
-   Energy points (50)
-   Attack damage (20)

**ScavTrap** will also have its own special capacity:
-	*void guardGate();*

This member function will display a message informing that ScavTrap is now in Gate keeper mode.


* ### ex02: Repetitive work

Now, implement a **FragTrap** class that inherits from **ClapTrap**. It is very similar to
**ScavTrap**. However, its construction and destruction messages must be different. Proper
construction/destruction chaining must be shown in your tests. When a **FragTrap** is
created, the program starts by building a **ClapTrap**. Destruction is in reverse order.

Same things for the attributes, but with different values this time:
-   Name, which is passed as parameter to a constructor
-   Hit points (100), represent the health of the **ClapTrap**
-   Energy points (100)
-   Attack damage (30)

**FragTrap** has a special capacity too:	
-	*void highFivesGuys(void);*
This member function displays a positive high fives request on the standard output.

* ### ex03: Now it’s weird!

In this exercise, you will create a monster: a ClapTrap that’s half FragTrap, half ScavTrap. It will be named **DiamondTrap**, and it will inherit from both the **FragTrap** AND the **ScavTrap**. This is so risky!
The **DiamondTrap** class will have a name private attribute. Give to this attribute
exactly the same variable’s name (not talking about the robot’s name here) than the one in the **ClapTrap** base class.


Its attributes and member functions will be picked from either one of its parent classes:
-   Name, which is passed as parameter to a constructor
-   ClapTrap::name (parameter of the constructor + "_clap_name" suffix)
-   Hit points (FragTrap)
-   Energy points (ScavTrap)
-   Attack damage (FragTrap)
-   attack() (Scavtrap)

In addition to the special functions of both its parent classes, **DiamondTrap** will have
its own special capacity:
-	*void whoAmI();*

This member function will display both its name and its **ClapTrap** name.
Of course, the **ClapTrap** subobject of the **DiamondTrap** will be created once, and only once. Yes, there’s a trick.