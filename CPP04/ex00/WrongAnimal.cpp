#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	_type = "WrongAnimal";
	std::cout << "Default constructor WrongAnimal is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	_type = other._type;
	std::cout << "Copy constructor WrongAnimal is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "Copy assignement operator WrongAnimal is called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "Destructor WrongAnimal is called" << std::endl;
}

void WrongAnimal::makeSound()const {
	std::cout << "un faux animal parle" << std::endl;
}

std::string WrongAnimal::getType()const {
	return _type;
}