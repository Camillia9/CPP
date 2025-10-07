#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
private: 
	AForm* createShrubbery(std::string target);
	AForm* createRobotomy(std::string target);
	AForm* createPresidential(std::string target);

public:
	Intern();
	Intern(const Intern& other);
	Intern& operator=(const Intern& other);
	~Intern();
	AForm* makeForm(std::string nameForm, std::string targetForm);
};

#endif
