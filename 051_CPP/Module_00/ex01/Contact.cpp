#include "Contact.hpp"

std::string Contact::fields_name[5] = {
	"First Name",
	"Last Name",
	"Nickname",
	"Phone",
	"Darkest Secret"
};

Contact::Contact()
{
	for (int i = FirstName; i <= DarkestSecret; i++)
		this->info[i] = std::string();
}

Contact::~Contact()
{
}

bool Contact::set_info(int id)
{
	this->id = id;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << "☎️ " << Contact::fields_name[i] << ":\n>";
		std::getline(std::cin, this->info[i]);
	}
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		if (this->info[i].length() == 0)
		{
			std::cout << "☎️ A contact can’t have empty fields! Contact has not been saved" << std::endl;
			return (false);
		}
	}
	std::cout << "☎️ Contact added !" << std::endl;
	return (true);
}

void Contact::display_row()
{
	std::cout << "|" << std::setw(10) << this->id;
	for (int i = FirstName; i <= Nickname; i++)
	{
		std::cout << "|";
		if (this->info[i].length() > 10)
			std::cout << this->info[i].substr(0, 9) << ".";
		else
			std::cout << std::setw(10) << this->info[i];
	}
	std::cout << "|" << std::endl;
}

void Contact::display_contact(void)
{
	std::cout << "☎️ Contact [" << this->id << "]" << std::endl;
	for (int i = FirstName; i <= DarkestSecret; i++)
	{
		std::cout << Contact::fields_name[i] << ": ";
		std::cout << this->info[i] << std::endl;
	}
}