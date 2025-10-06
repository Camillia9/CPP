#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45), _target("default") {
	std::cout << "Default constructor RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("Robotomy", 72, 45), _target(target) {
	std::cout << "Default constructor Parametric RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm("Robotomy", 72, 45), _target(other._target) {
	std::cout << "Copy constructor RobotomyRequestForm is called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	std::cout << "Copy assignement operator RobotomyRequestForm is called" << std::endl;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "Deconstructor RobotomyRequestForm is called" << std::endl;
}

void RobotomyRequestForm::executeAction()const {
	std::cout << "Robotomie en action..." << std::endl;
	std::cout << "BZZZZZZZ * VRRRRRR" << std::endl;
	if (rand() % 2 == 0) {
		std::cout << _target << " a été robotomisé avec succès !" << std::endl;
	} else {
		std::cout << "La robotomie de " << _target << " a échoué." << std::endl;
	}
}