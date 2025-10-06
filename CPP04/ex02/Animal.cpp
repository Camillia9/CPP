#include "Animal.hpp"

Animal::Animal() {
	_type = "Animal";
	std::cout << "Default constucteur Animal is called" << std::endl;
}

Animal::Animal(const Animal& other) {
	_type = other._type;
	std::cout << "Copy constructor Animal is called" << std::endl;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Copy assignement operator Animal is called" << std::endl;
	if (this != &other)
		_type = other._type;
	return *this;
}

Animal::~Animal() {
	std::cout << "Destructor Animal is called" << std::endl;
}

//void Animal::makeSound()const {
//	std::cout << "Bruit d'animal" << std::endl;
//}

std::string Animal::getType()const {
	return _type;
}