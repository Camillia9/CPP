#include "zombie.hpp"

void randomChump( std::string name ) {
	Zombie tmpZomb(name);
	tmpZomb.announce();
}
