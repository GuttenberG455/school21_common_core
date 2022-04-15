#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact	contacts[8];
	int		amount;

public:
	PhoneBook();
	virtual ~PhoneBook();
	
	void	show_startup(void);
	void	add_contact(void);
	void	search_contact(void);
	void	display_contact_table(void);
};

#endif