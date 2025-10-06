#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(42) {
	std::cout << "Default constructor Bureaucrat is called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string n, int g) : _name(n) {
	std::cout << "Default constructor Bureaucrat is called" << std::endl;
	_grade = g;
	if (g < 1)
		throw GradeTooHighException();
	else if (g > 150)
		throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name) {
	_grade = other._grade;
	std::cout << "Copy Constructor Bureaucrat is called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other ) {
	std::cout << "Copy assignement operator Bureaucrat is called" << std::endl;
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Destructor Bureaucrat is called" << std::endl;
}

std::string Bureaucrat::getName()const {
	return _name;
}

int Bureaucrat::getGrade()const {
	return _grade;
}

void Bureaucrat::upGrade() {
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	else
		_grade--;
}

void Bureaucrat::downGrade() {
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	else
		_grade++;
}

const char* Bureaucrat::GradeTooHighException::what()const throw() {
		return "Erreur: Grade inferieur a 1";
}

const char* Bureaucrat::GradeTooLowException::what()const throw() {
	return "Erreur: Grade superieur a 150";
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
	os << b.getName() << " bureaucrat, grade: " << b.getGrade() << "." << std::endl;
	return os;
}