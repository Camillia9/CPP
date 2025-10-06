#include "Form.hpp"

Form::Form() : _name("default"), _gradeToSign(75), _gradeToExecute(75) {
	std::cout << "Default constructor Form is called" << std::endl;
}

Form::Form(std::string n, int gSign, int gExec) : _name(n), _gradeToSign(gSign), _gradeToExecute(gExec) {
	std::cout << "Default constructor Form is called" << std::endl;
	if (_gradeToSign < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& other) : _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	_signed = other._signed;
	std::cout << "Copy constructor Form is called" << std::endl;
}

Form& Form::operator=(const Form& other) {
	std::cout << "Copy assignement operator Form is called" << std::endl;
	if (this != &other) {
		_signed = other._signed;
	}
	return *this;
}

Form::~Form() {
	std::cout << "Destructor Form is called" << std::endl;
}

std::string Form::getName()const {
	return _name;
}

int Form::getGradeToSign()const {
	return _gradeToSign;
}

bool Form::getIsSigned()const {
	return _signed;
}

std::string Form::statut()const {
	if (_signed == true)
		return ("Signé");
	else
		return ("pas signé");
}

void Form::beSigned(Bureaucrat const &b) {
	if (_signed == true) {
		throw::Form::FormAlreadySignedException();
	}
	if (b.getGrade() <= _gradeToSign) {
		_signed = true;
	} else {
		throw Form::GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what()const throw() {
		return "Grade too high.";
}

const char* Form::GradeTooLowException::what()const throw() {
	return "Grade too low.";
}

const char* Form::FormAlreadySignedException::what()const throw() {
	return "Formulaire deja signe.";
}

std::ostream& operator<<(std::ostream& os, const Form& f) {
	os << "Formulaire: " << f.getName() << ", statut: " << f.statut() <<  ", grade requis pour le signer: " << f.getGradeToSign() << "." << std::endl;
	return os;
}