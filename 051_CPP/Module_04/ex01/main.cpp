
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    Animal *animals[20];

    std::cout << "CREATING" << std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        if (i % 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
        std::cout <<  std::endl;
    }

    std::cout << "\nGETTING IDEAS\n";

    for (size_t i = 0; i < 20; i++)
    {
        // Todo Output of ideas
    }

    std::cout << std::endl;
    std::cout << "DELETING" << std::endl;
    for (size_t i = 0; i < 20; i++)
    {
        delete animals[i];
        std::cout <<  std::endl;
    }
    return 0;
}