#ifndef HZombie_HPP
#define HZombie_HPP

#include <iostream>
#include <string>

class HZombie {
private:
	std::string name;

public:
	HZombie();
	HZombie(std::string n);
	~HZombie();
	void announce(void);
	void setName(std::string n);
};

HZombie *zombieHorde(int N, std::string name);

#endif