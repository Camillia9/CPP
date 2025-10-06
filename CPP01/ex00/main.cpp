#include "zombie.hpp"

int main() {
	Zombie Zombie1("Bob");
	Zombie1.announce();
	randomChump("Hector");
	Zombie *nzombie = newZombie("Jack");
	nzombie->announce();
	delete nzombie;
}