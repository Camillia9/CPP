#include "ScavTrap.hpp"

int main() {
	ScavTrap Liam("Liam");
	ScavTrap Thor("Thor");
	ClapTrap Bob("Bob");
	ClapTrap Jules("Jules");
	Bob.attack("Jules");
	Jules.beRepaired(5);
	//Jules.guardgate();
	Liam.attack("Thor");
	Thor.beRepaired(60);
	Thor.guardGate();
	return 0;
}