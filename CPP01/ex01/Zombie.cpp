#include "HZombie.hpp"

HZombie::HZombie() {

}

HZombie::HZombie(std::string n) {
	name = n;
}

HZombie::~HZombie() {
	std::cout << name << " is detroyed" << std::endl;
}

void HZombie::setName(std::string n) {
	name = n;
}

void HZombie::announce() {
	std::cout << name << ":BraiiiiiinnzzzZ..." << std::endl;
}