#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name(), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "Default constructor ClapTrap is called" << std::endl;
}

ClapTrap::ClapTrap(std::string n) : _name(n), _HitPoints(10), _EnergyPoints(10), _AttackDamage(0) {
	std::cout << "Default constructor ClapTrap is called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) : _name(other._name), _HitPoints(other._HitPoints), _EnergyPoints(other._EnergyPoints), _AttackDamage(other._AttackDamage) {
	std::cout << "Copy constructor ClapTrap is called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "Copy assignment operator ClapTrap is called" << std::endl;
    if (this != &other) {  // Éviter l'auto-affectation
        _name = other._name;
        _HitPoints = other._HitPoints;
        _EnergyPoints = other._EnergyPoints;
        _AttackDamage = other._AttackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap() {
	std::cout << "Destructor ClapTrap is called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "PV de " << _name << " : " << _HitPoints << std::endl;
	if (_EnergyPoints < 0) {
		std::cout << "Erreur: Nombres negatifs" << std::endl; 
	} else if (_HitPoints == 0) {
		std::cout << _name << " est mort donc n'attaque pas" << std::endl;
	} else if (_EnergyPoints > 0) {
		_EnergyPoints--;
		std::cout << _name << " attaque " << target << ":" << std::endl;
		std::cout << "  - "<< target << " a perdu " << _AttackDamage << " points de degats" << std::endl;
		std::cout << "  - "<< _name << " a perdu 1 point d'energie" << std::endl;
	} else {
		std::cout << _name << " n'as plus de force pour combattre" << std::endl;
	}
	std::cout << std::endl;
}

void ClapTrap::takeDamage(int amount) {
	if (amount < 0) {
		std::cout << "Erreur: Nombres negatifs" << std::endl;
		return;
	}
	std::cout << "PV de " << _name << " : " << _HitPoints << std::endl;
	std::cout << "Dégâts infligés à " << _name << " : " << amount << std::endl;
	if (_HitPoints > amount) {
		_HitPoints -= amount;
		std::cout << _name << " a perdu " << amount << " points de vie" << std::endl;
		std::cout << "il lui reste donc: " << _HitPoints << " points de vie" << std::endl;
	} else if (_HitPoints == 0 ){
		std::cout << _name << " est deja mort" << std::endl;
	} else {
		std::cout << _name << " meurt sur le coup" << std::endl;
		_HitPoints = 0;
	}
	std::cout << std::endl;
}

void ClapTrap::beRepaired(int amount) {
	if (amount < 0) {
		std::cout << "Erreur: Nombres negatifs" << std::endl;
		return;
	}
	std::cout << "PV de " << _name << " : " << _HitPoints << std::endl;
	std::cout << "PE de " << _name << " : " << _EnergyPoints << std::endl;
	if (_HitPoints == 0) {
		std::cout << _name << " est deja mort, impossible de le sauver" << std::endl;
	} else if (_EnergyPoints == 0) {
		std::cout << _name << " n'a plus d'energie pour se regenerer" << std::endl;
	} else {
		_EnergyPoints -= 1;
		_HitPoints += amount;
		std::cout << _name << " a augmente ses points de vie de " << amount << " points" << std::endl;
		std::cout << "il a donc: " << _HitPoints << " points de vie" << std::endl;
		std::cout << "et il lui reste donc " << _EnergyPoints << " points d'energies" << std::endl;

	}
	std::cout << std::endl;
}
