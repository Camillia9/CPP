#include "Dog.hpp"

Dog::Dog() : Animal() {
	_type = "Dog";
	std::cout << "Default constructeur Dog is called" << std::endl;
}

Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Copy constructeur Dog is called" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Copy assignement operator Dog is called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Dog::~Dog() {
	std::cout << "Destructor Dog is called" << std::endl;
}

void Dog::makeSound()const {
	std::cout << "WOOOF" << std::endl;
}

std::string Dog::getType()const {
	return _type;
}


