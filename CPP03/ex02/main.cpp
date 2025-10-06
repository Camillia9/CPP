#include "FragTrap.hpp"

int main() {
    ClapTrap basic("Basic");
    ScavTrap guardian("Guardian"); 
    FragTrap fighter("Fighter");
    
    basic.attack("target");
    guardian.attack("target");
    fighter.attack("target");
    fighter.beRepaired(1);
    
    guardian.guardGate();
    fighter.highFivesGuys();
    
    return 0;
}