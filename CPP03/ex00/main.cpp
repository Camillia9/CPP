#include "ClapTrap.hpp"

int main() {
	ClapTrap Bob("Bob");
	ClapTrap Jules("Jules");
	Bob.attack("Jules");
	Jules.takeDamage(5);
	Jules.beRepaired(3);
	Bob.takeDamage(15);
	Bob.attack("Jules");
	return 0;
}