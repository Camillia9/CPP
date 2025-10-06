#include "DiamondTrap.hpp"

int main() {
	DiamondTrap Kiki("Kiki");
	DiamondTrap Lolo("Lolo");
	Kiki.whoAmI();
	Lolo.attack("Kiki");
	return 0;
}