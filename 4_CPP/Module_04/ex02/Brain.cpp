
#include "Brain.hpp"

Brain::Brain() {
    for (int i = 0; i < 100; i++)
        _ideas[i] = "Default Idea: Plenty of beer and vobla";
    std::cout << "Default brain was created" << std::endl;
}

Brain::Brain(std::string type)
{
    for (size_t i = 0; i < 100; i++)
    {
        if (type == "Cat")
            this->_ideas[i] = "Catty Idea: Wanna sleep 18 hours instead of 16";
        else if (type == "Dog")
            this->_ideas[i] = "Doge Idea: Throw that ball and I will catch it";
        else
            this->_ideas[i] = "Default Idea: Plenty of beer and vobla";
    }
    std::cout << "New " << type << " Brain was created!\n";
}

Brain::Brain(const Brain &old) {
    for (int i = 0; i < 100; i++)
        _ideas[i]=old._ideas[i];
    std::cout << "Brain was cloned" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain was destroyed" << std::endl;
}

Brain &Brain::operator=(const Brain &old) {
    for (int i = 0; i < 100; i++)
        _ideas[i]=old._ideas[i];
    std::cout << "Brain was copied" << std::endl;
    return (*this);
}

void Brain::setIdea(const std::string idea) {
    _ideas[0] = idea;
}

std::string Brain::getIdea() {
    return (_ideas[0]);
}