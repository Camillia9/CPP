#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5), _target("default") {
	std::cout << "Default constructor PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("Presidential", 25, 5), _target(target) {
	std::cout << "Default constructor Parametric PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) : AForm("Presidential", 25, 5), _target(other._target) {
	std::cout << "Copy constructor PresidentialPardonForm is called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	std::cout << "Copy assignement operator PresidentialPardonForm is called" << std::endl;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "Deconstructor PresidentialPardonForm is called" << std::endl;
}

void PresidentialPardonForm::executeAction()const {
	std::cout << _target << " demande pardon..." << std::endl;
	std::cout << _target << " a été gracié par Zaphod Beeblebrox." << std::endl;
}
