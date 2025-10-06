#include "Weapon.hpp"

class HumanB {
private:
	std::string name;
	Weapon* weapon;

public:
	HumanB(const std::string& n);
	void attack();
	void setWeapon(Weapon *w);
	
};