#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	std::cout << "Default constructeur Cat is called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	std::cout << "Copy constructeur Cat is called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Copy assignement operator Cat is called" << std::endl;
	if (this != &other)
		Animal::operator=(other);
	return *this;
}

Cat::~Cat() {
	std::cout << "Destructor Cat is called" << std::endl;
}

void Cat::makeSound(void)const {
	std::cout << "MIAOUU" << std::endl;
}

std::string Cat::getType()const {
	return _type;
}