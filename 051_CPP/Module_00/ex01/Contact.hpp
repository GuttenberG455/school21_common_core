#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
private:
	int id;
	static std::string	fields_name[11];
	std::string			informations[11];

	enum Field {
		FirstName = 0,
		LastName,
		Nickname,
		Login,
		Address,
		Email,
		Phone,
		Birthday,
		FavoriteMeal,
		UnderwearColor,
		Secret
	};	
public:
	Contact();
	virtual ~Contact();
	
	bool set_info(int id);
	void display_header();
	void display();
};

#endif