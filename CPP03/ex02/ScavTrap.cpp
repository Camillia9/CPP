#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "Default constructor ScavTrap is called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_HitPoints = 100;
	_EnergyPoints = 50;
	_AttackDamage = 20;
	std::cout << "Default constructor ScavTrap is called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "Copy constructor ScavTrap is called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "Copy assignement operator ScavTrap is called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "Destructor ScavTrap is called" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	std::cout << "PV de " << _name << " : " << _HitPoints << std::endl;
	if (_EnergyPoints < 0) {
		std::cout << "Erreur: Nombres negatifs" << std::endl; 
	} else if (_HitPoints == 0) {
		std::cout << _name << " est décédé" << std::endl;
	} else if (_EnergyPoints > 0) {
		_EnergyPoints--;
		std::cout << _name << " bombarde " << target << ":" << std::endl;
		std::cout << "  - "<< target << " a perdu " << _AttackDamage << " points de degats" << std::endl;
		std::cout << "  - "<< _name << " a perdu 1 point d'energie" << std::endl;
	} else {
		std::cout << _name << " est trop faible pour combattre" << std::endl;
	}
	std::cout << std::endl;
}

void ScavTrap::guardGate() {
	std::cout << _name << " est maintenant gardien de porte" << std::endl << std::endl;
}