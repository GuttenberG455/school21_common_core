
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal *animals[10];

    std::cout << "CREATING" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();

        std::cout << std::endl;
    }

    std::cout << "\nGETTING IDEAS\n";

    Cat *catty = new Cat();
    Dog *doge = new Dog();

    std::cout << catty->getBrain()->getIdea() << std::endl;
    std::cout << doge->getBrain()->getIdea() << std::endl;

    catty->getBrain()->setIdea("New Cat idea: I want some delicious food!");
    std::cout << catty->getBrain()->getIdea() << std::endl;

    delete catty;
    delete doge;

    std::cout << std::endl;
    std::cout << "DELETING" << std::endl;
    for (size_t i = 0; i < 10; i++)
    {
        delete animals[i];
        std::cout <<  std::endl;
    }

//    Animal animal; // Animal is abstract class, this code doesn't work

    return 0;
}