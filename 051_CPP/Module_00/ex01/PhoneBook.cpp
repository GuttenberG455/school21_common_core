#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->amount = 0;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::show_startup(void)
{
	std::cout << "Welcome to IPhoneBook ZV edition ☎️" << std::endl;
	std::cout << "Commands: ADD, SEARCH, EXIT" << std::endl;
}

void PhoneBook::add_contact(void)
{
	if (this->amount == 8)
		std::cout << "☎️ The storage is full!" << std::endl;
	else if (this->contacts[this->amount].set_info(this->amount + 1))
		this->amount++;
}

void PhoneBook::display_contact_table(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < this->amount; i++)
		this->contacts[i].display_row();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::search_contact(void)
{
	int	index;

	if (this->amount == 0)
		std::cout << "☎️ Storage is empty! Add a contact before searching." << std::endl;
	else
	{
		this->display_contact_table();
		std::cout << "☎️ Enter Index to display info or dial 0 to Exit\n~";
		while (!(std::cin >> index) || (index < 0 || index > this->amount))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "☎️ Invalid Index\n~";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->contacts[index - 1].display_contact();
	}
}