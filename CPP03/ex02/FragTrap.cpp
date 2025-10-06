#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "Default constructor FragTrap is called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_HitPoints = 100;
	_EnergyPoints = 100;
	_AttackDamage = 30;
	std::cout << "Default constructor FragTrap is called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor FragTrap is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "Copy assignement operator FragTrap is called" << std::endl;
	if (this != &other) {
		FragTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "Destructor FragTrap is called" << std::endl;
}

void FragTrap::highFivesGuys() {
	std::cout << _name << " demande un hight-five" << std::endl << std::endl;
}