#include <iostream>
#include "PhoneBook.hpp"
using namespace std;

int main()
{
	PhoneBook phonebook;
	std::string command;
	phonebook.show_startup();
	while (1)
	{
		std::cout << "(´• ω •) ";
		std::getline(std::cin, command);
		if (std::cin.bad() || std::cin.eof())
		{
			std::cerr << "\n(x ω x`) EOF error" << std::endl;
			break;
		}
		if (command == "ADD")
			phonebook.add_contact();
		else if (command == "SEARCH")
			phonebook.search_contact();
		else if (command == "EXIT")
		{
			std::cout << "(• ω •`) Bye" << std::endl;
			break;
		}
	}
	return 0;
}