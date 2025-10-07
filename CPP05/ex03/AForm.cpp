#include "AForm.hpp"

AForm::AForm() : _name("default"), _gradeToSign(75), _gradeToExecute(75) {
	std::cout << "Default constructor Form is called" << std::endl;
	_signed = false;
}

AForm::AForm(std::string n, int gSign, int gExec) : _name(n), _gradeToSign(gSign), _gradeToExecute(gExec) {
	std::cout << "Default constructor Form is called" << std::endl;
	_signed = false;
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	_signed = other._signed;
	std::cout << "Copy constructor Form is called" << std::endl;
}

AForm& AForm::operator=(const AForm& other) {
	std::cout << "Copy assignement operator Form is called" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

AForm::~AForm() {
	std::cout << "Destructor Form is called" << std::endl;
}

std::string AForm::getName()const {
	return _name;
}

int AForm::getGradeToSign()const {
	return _gradeToSign;
}

int AForm::getGradeToExec()const {
	return _gradeToExecute;
}

bool AForm::getIsSigned()const {
	return _signed;
}

std::string AForm::statut()const {
	if (_signed == true)
		return ("Signé");
	else
		return ("Pas signé");
}

void AForm::beSigned(Bureaucrat const &b) {
	if (_signed == true) {
		throw::AForm::FormAlreadySignedException();
	}
	if (b.getGrade() <= _gradeToSign) {
		_signed = true;
	} else {
		throw AForm::GradeTooLowException();
	}
}

void AForm::execute(Bureaucrat const& executor)const {
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	this->executeAction();
}

const char* AForm::GradeTooHighException::what()const throw() {
		return "Grade too high.";
}

const char* AForm::GradeTooLowException::what()const throw() {
	return "Grade too low.";
}

const char* AForm::FormAlreadySignedException::what()const throw() {
	return "Formulaire deja signe.";
}

const char* AForm::FormNotSignedException::what()const throw() {
	return "Formulaire non signe.";
}

std::ostream& operator<<(std::ostream& os, const AForm& f) {
	os << "Formulaire: " << f.getName() << ", statut: " << f.statut() <<  ", grade requis pour le signer: " << f.getGradeToSign() << ", grade requis pour l'executer: " << f.getGradeToExec() << "." << std::endl;
	return os;
}