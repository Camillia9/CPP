#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal() {
	_type = "WrongCat";
	std::cout << "Default constructeur WrongCat is called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other) {
	std::cout << "Copy constructeur WrongCat is called" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "Copy assignement operator WrongCat is called" << std::endl;
	if (this != &other)
		WrongAnimal::operator=(other);
	return *this;
}

WrongCat::~WrongCat() {
	std::cout << "Destructor WrongWrongCat is called" << std::endl;
}

void WrongCat::makeSound(void)const {
	std::cout << "MIAMIA" << std::endl;
}

std::string WrongCat::getType()const {
	return _type;
}
