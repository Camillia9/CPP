#ifndef PHONE_BOOK
#define PHONE_BOOK

#include "Contact.hpp"

class PhoneBook {
private:
	Contact contacts[8];
	int nbContact;
	
public:
	PhoneBook();
	void Add();
	void Search();
};

#endif