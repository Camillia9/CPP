#include "Intern.hpp"

Intern::Intern() {
	std::cout << "Default constructor Intern is called" << std::endl;
}

Intern::Intern(const Intern& other) {
	(void)other;
	std::cout << "Copy constructor Intern is called" << std::endl;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	std::cout << "Copy assignement operator Intern is called" << std::endl;
	return *this;
}

Intern::~Intern() {
	std::cout << "Destructor Intern is called" << std::endl;
}

AForm *Intern::createShrubbery(std::string target) {
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target) {
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string target) {
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(std::string nameForm, std::string targetForm) {
	// Tableau des formulaires possibles:
	std::string formName[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	// Tableau de pointeurs
	AForm* (Intern::*formCreators[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPresidential
	};
	// Chercher le bon Formulaire
	for (int i = 0; i < 3; i++) {
		if (nameForm == formName[i]) {
			std::cout << "Intern creates " << nameForm << std::endl;
			return (this->*formCreators[i])(targetForm);
		}
	}
	std::cerr << "Erreur Form '" << nameForm << "' n'existe pas" << std::endl;
	return NULL;
	
}



