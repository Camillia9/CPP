#include "HumanB.hpp"

HumanB::HumanB(const std::string& n) : name(n), weapon(NULL) {

}

void HumanB::attack() {
	if (weapon != NULL) {
		std::cout << name << " attack with their " << weapon->getType() << std::endl;
	} else {
		std::cout << "don't attack " << std::endl;
	}
}

void HumanB::setWeapon(Weapon* w) {
	weapon = w;
}

