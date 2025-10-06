#include "HZombie.hpp"

HZombie *zombieHorde(int N, std::string name) {
	HZombie *horde = new HZombie[N];
	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].announce();
	}
	return horde;
}