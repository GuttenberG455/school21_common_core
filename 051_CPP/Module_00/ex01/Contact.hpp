#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	int id;
	static std::string	fields_name[5];
	std::string			info[5];

	enum Field {
		FirstName = 0,
		LastName,
		Nickname,
		PhoneNumber,
		DarkestSecret
	};	

public:
	Contact();
	virtual ~Contact();
	
	bool set_info(int id);
	void display_row();
	void display_contact();
};

#endif