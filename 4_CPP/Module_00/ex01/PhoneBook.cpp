#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->_amount = 0;
	this->_oldest_id = 0;
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
	if (this->_amount == 8)
	{
		if (_oldest_id == 8)
			_oldest_id = 0;
		std::cout << "☎️ Contact #" << _oldest_id + 1 << " would be replaced by a new one" << std::endl;
		if (this->_contacts[this->_oldest_id].set_info(this->_oldest_id + 1))
			this->_oldest_id++;
	}
	else if (this->_contacts[this->_oldest_id].set_info(this->_oldest_id + 1))
	{
		this->_amount++;
		this->_oldest_id++;
	}
}

void PhoneBook::display_contact_table(void)
{
	std::cout << "|-------------------------------------------|" << std::endl;
	std::cout << "|     Index|First Name| Last Name|  Nickname|" << std::endl;
	std::cout << "|-------------------------------------------|" << std::endl;
	for (int i = 0; i < std::min(this->_amount, 8); i++)
		this->_contacts[i].display_row();
	std::cout << "|-------------------------------------------|" << std::endl;
}

void PhoneBook::search_contact(void)
{
	int	index;

	if (this->_amount == 0)
		std::cout << "☎️ Storage is empty! Add a contact before searching." << std::endl;
	else
	{
		this->display_contact_table();
		std::cout << "☎️ Enter Index to display info or dial 0 to Exit\n~";
		while (!(std::cin >> index) || (index < 0 || index > std::min(this->_amount, 8)))
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "☎️ Invalid Index\n~";
		}
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (index > 0)
			this->_contacts[index - 1].display_contact();
	}
}

/*

Функция

istream& istream::ignore(streamsize n = 1, int delim = EOF);

определенная в классе istream, извлекает из потока символы и отбрасывает их. 
Причем она так поступает либо с n символами, либо со всеми символами, пока в потоке не встретится символ, заданный параметром delim.

В нашем случае мы стремимся отбросить максимальное число символов, которое может содержать поток, до первого перевода строки включительно.


*/