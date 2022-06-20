#include "Contact.hpp"

std::string Contact::_fields_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->_info[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_info(int id)
{
	std::string lines[5];
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "☎️ " << Contact::_fields_name[i] << ":\n>";
		std::getline(std::cin, lines[i]);
		if (lines[i].length() == 0)
		{
			std::cout << "☎️ A contact can’t have empty fields! Contact has not been saved" << std::endl;
			return (false);
		}
	}
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->_info[i] = lines[i];
	this->_id = id;
	std::cout << "☎️ Contact added !" << std::endl;
	return (true);
}

void Contact::display_row()
{
	std::cout << "|" << std::setw(10) << this->_id;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->_info[i].length() > 10)
			std::cout << this->_info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->_info[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::display_contact(void)
{
	std::cout << "☎️ Contact [" << this->_id << "]" << std::endl;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << Contact::_fields_name[i] << ": ";
		std::cout << this->_info[i] << std::endl;
	}
}