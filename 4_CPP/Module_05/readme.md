# Module 05
[Subject](https://cdn.intra.42.fr/pdf/pdf/52160/en.subject.pdf)

[Checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_4_cpp_module_05.pdf)

***100/100 SUCCESS***

---
## Project topics:
Repetition and Exceptions

## List of exercises:
* ### ex00: Mommy, when I grow up, I want to be a bureaucrat!

First, start by the smallest cog in this vast bureaucratic machine: the **Bureaucrat**.
A Bureaucrat must have:
-	A constant *name*.
-	And a *grade* that ranges from 1 (highest possible grade) to 150 (lowest possible
grade).

Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception:
either a *Bureaucrat::GradeTooHighException* or a *Bureaucrat::GradeTooLowException*.

You will provide getters for both these attributes: *getName()* and *getGrade()*. 
Implement also two member functions to increment or decrement the bureaucrat grade. If
the grade is out of range, both of them will throw the same exceptions as the constructor.

You will implement an overload of the insertion («) operator to print something.

* ### ex01: Form up, maggots!

Now that you have bureaucrats, let’s give them something to do. What better activity
could there be than the one of filling out a stack of forms?

Then, let’s make a **Form** class. It has:
-	A constant *name*.
-	A boolean indicating whether it *is signed* (at construction, it’s not).
-	A constant *grade* required *to sign* it.
-	And a constant *grade* required *to execute* it.

All these attributes are private, not protected.

The grades of the **Form** follow the same rules that apply to the **Bureaucrat**. Thus,
the following exceptions will be thrown if a form grade is out of bounds:
*Form::GradeTooHighException* and *Form::GradeTooLowException*.

Same as before, write getters for all attributes and an overload of the insertion («)
operator that prints all the form’s informations.

Add also a *beSigned()* member function to the **Form** that takes a **Bureaucrat** as
parameter. It changes the *form status* to signed if the bureaucrat’s grade is high enough
(higher or egal to the required one). Remember, grade 1 is higher than grade 2.
If the grade is too low, throw a *Form::GradeTooLowException*.

Lastly, add a *signForm()* member function to the **Bureaucrat**. If the form got signed,
it will print something.

* ### ex02: No, you need form 28B, not 28C...

Since you now have basic forms, it’s time to make a few more that actually do something.
In all cases, the base class Form must be an abstract class. Keep in mind the form’s
attributes need to remain private and that they are in the base class.

Add the following concrete classes:
-	**ShrubberyCreationForm**: Required grades: sign 145, exec 137
Create a file <target>_shrubbery in the working directory, and writes ASCII trees
inside it.
-	**RobotomyRequestForm**: Required grades: sign 72, exec 45
Makes some drilling noises. Then, informs that <target> has been robotomized
successfully 50% of the time. Otherwise, informs that the robotomy failed.
-	**PresidentialPardonForm**: Required grades: sign 25, exec 5
Informs that <target> has been pardoned by Zaphod Beeblebrox.


All of them take only one parameter in their constructor: the target of the form.

Now, add the *execute(Bureaucrat const & executor) const* member function to
the base form and implement a function to execute the form’s action of the concrete
classes. You have to check that the form is signed and that the grade of the bureaucrat
attempting to execute the form is high enough. Otherwise, throw an appropriate exception.
Whether you want to check the requirements in every concrete class or in the base
class is up to you.

Lastly, add the *executeForm(Form const & form)* member function to the **Bureaucrat**. It must attempt to execute the form. If it’s successful, print something.


* ### ex03: At least this beats coffee-making

In this exercise, you have to implement
the **Intern class**. The intern has no name, no grade, no unique characteristics. The only
thing the bureaucrats care about is that they do their job.

However, the intern has one important capacity: the *makeForm()* function. It takes
two strings. The first one is the name of a form and the second one is the target of the
form. It return a pointer to a **Form** object (whose name is the one passed as parameter)
whose target will be initialized to the second parameter. You must avoid unreadable and ugly solutions like using a if/elseif/else forest. 
It will print something.
