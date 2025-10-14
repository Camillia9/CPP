#include "Base.hpp"
#include "fonctions.hpp"

int main () {
    static bool initialized = false;
    if (!initialized) {
        srand(time(NULL));
        initialized = true;
    }
    for (int i = 0; i < 5; i++) {
        std::cout << "\n=== Test " << i + 1 << " ===" << std::endl;
        
        Base* obj = generate();
        
        std::cout << "Identify with pointer: ";
        identify(obj);
        
        std::cout << "Identify with reference: ";
        identify(*obj);
        
        delete obj;
    }
    return 0;
}


