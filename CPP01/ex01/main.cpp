#include "HZombie.hpp"

int main() {
	HZombie *nzombie = zombieHorde(10, "Bob");
	delete[]nzombie;
}