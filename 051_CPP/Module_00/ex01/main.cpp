#include <iostream>
#include "PhoneBook.hpp"
using namespace std;

int main()
{
	PhoneBook phonebook;
	std::string command;
	while (1)
	{
		std::cout << "(´• ω •) ";
		std::getline(std::cin, command);
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "Bye" << std::endl;
			break;
		}
	}
	return 0;
}