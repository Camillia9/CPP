#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Default constructor Brain is called" << std::endl;
	// Ici le tableau de 100 idees est automatiquement rempli de string vides.
}

Brain::Brain(const Brain& other) {
	std::cout << "Copy constructor Brain is called" << std::endl;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = other._ideas[i];
	}
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Copy assignement operator Brain is called" << std::endl;
	if (this != &other) {
		for (int i = 0; i < 100; i++) {
			_ideas[i] = other._ideas[i];
		}
	}
	return *this;
}

Brain::~Brain() {
	std::cout << "Destructor Brain is called" << std::endl;
}