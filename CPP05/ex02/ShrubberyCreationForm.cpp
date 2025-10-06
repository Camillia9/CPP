#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("Default", 145, 137), _target("default") {
	std::cout << "Default constructor ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("Shruberry", 145, 137), _target(target) {
	std::cout << "Default constructor Parametric ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm("Shruberry", 145, 137), _target(other._target) {
	std::cout << "Copy constructor ShrubberyCreationForm is called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	std::cout << "Copy assignement operator ShrubberyCreationForm is called" << std::endl;
	if (this != &other) {
		_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "Deconstructor ShrubberyCreationForm is called" << std::endl;
}

void ShrubberyCreationForm::executeAction()const {
	std::cout << "Creation de l'arbre..." << std::endl;
	
	std::string filename = _target + "_shrubbery";
	std::ofstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Erreur: impossible de cree le fichier " << filename << std::endl;
		return;
	}
	file << "       ###" << std::endl;
	file << "      #o###" << std::endl;
	file << "    #####o###" << std::endl;
	file << "   #o#\\#|#/###" << std::endl;
	file << "    ###\\|/#o#" << std::endl;
	file << "     # }|{  #" << std::endl;
	file << "       }|{" << std::endl;

	file.close();
	std::cout << "Arbre cree dans " << filename << std::endl;

}