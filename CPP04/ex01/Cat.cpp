#include "Cat.hpp"

Cat::Cat() : Animal() {
	_type = "Cat";
	_brain = new Brain();
	std::cout << "Default constructeur Cat is called" << std::endl;
}

Cat::Cat(const Cat& other) : Animal(other) {
	_brain = new Brain(*(other._brain));
	std::cout << "Copy constructeur Cat is called" << std::endl;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Copy assignement operator Cat is called" << std::endl;
	if (this != &other) {
		Animal::operator=(other);
		delete _brain;
		_brain = new Brain(*(other._brain));
	}
	return *this;
}

Cat::~Cat() {
	delete _brain;
	std::cout << "Destructor Cat is called" << std::endl;
}

void Cat::makeSound(void)const {
	std::cout << "MIAOUU" << std::endl;
}

std::string Cat::getType()const {
	return _type;
}