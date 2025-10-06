#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap(){
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
	std::cout << "Default constructor DiamondTrap is called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name){
	//DiamondTrap::_name = name;        // DiamondTrap's _name
	//ClapTrap::_name = name + "_clap"; // ClapTrap's _name
	this->_name = name;
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 30;
	std::cout << "Default constructor DiamondTrap is called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : FragTrap(other), ScavTrap(other) {
	std::cout << "Copy constructor DiamondTrap is called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	std::cout << "Copy assignement operator DiamondTrap is called" << std::endl;
	if (this != &other) {
		FragTrap::operator=(other);
		ScavTrap::operator=(other);
		this->_name = other._name;
	}
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "Destructor DiamondTrap is called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
	std::cout << std::endl << "Je suis " << this->_name << " et mon ClapTRap s'appelle " << ClapTrap::_name << std::endl << std::endl;
}