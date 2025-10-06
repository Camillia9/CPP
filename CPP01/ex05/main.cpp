#include "Harl.hpp"

int main() {
    Harl harl;
    
    std::cout << "=== Test des différents niveaux ===" << std::endl;
    
    std::cout << "Test DEBUG: ";
    harl.complain("DEBUG");
    
    std::cout << "Test INFO: ";
    harl.complain("INFO");
    
    std::cout << "Test WARNING: ";
    harl.complain("WARNING");
    
    std::cout << "Test ERROR: ";
    harl.complain("ERROR");
    
    std::cout << "\n=== Test niveau inexistant ===" << std::endl;
    std::cout << "Test INVALID: ";
    harl.complain("INVALID");
    
    std::cout << "\n=== Test case sensitivity ===" << std::endl;
    std::cout << "Test debug (minuscules): ";
    harl.complain("debug");
    
    return 0;
}