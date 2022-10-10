#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	_contacts[8];
	int		_amount;
	int		_oldest_id;

public:
	PhoneBook();
	virtual ~PhoneBook();
	
	void	show_startup(void);
	void	add_contact(void);
	void	search_contact(void);
	void	display_contact_table(void);
};

#endif