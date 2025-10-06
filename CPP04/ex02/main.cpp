#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() {
    std::cout << "--- TEST 1: Constructeurs par défaut ---" << std::endl;
    {
        std::cout << "Création d'un Dog:" << std::endl;
        Dog chien;
        std::cout << "Type: " << chien.getType() << std::endl;
        chien.makeSound();
        std::cout << std::endl;
        
        std::cout << "Création d'un Cat:" << std::endl;
        Cat chat;
        std::cout << "Type: " << chat.getType() << std::endl;
        chat.makeSound();
        std::cout << std::endl;

        //std::cout << "Création d'un Animal" << std::endl;
        //Animal animal;
        //std::cout << "Type: " << animal.getType() << std::endl;
        //animal.makeSound();
        //std::cout << std::endl;
    }

    std::cout << "--- TEST 2: Tableau d'animaux ---" << std::endl;
    {
        const int NB_ANIMAUX = 3;
        Animal* zoo[NB_ANIMAUX];
        
        std::cout << "Création du zoo:" << std::endl;
        zoo[0] = new Dog();
        zoo[1] = new Cat();
        zoo[2] = new Dog(); 
        //zoo[3] = new Cat();
        
        std::cout << "\nLe zoo fait du bruit:" << std::endl;
        for (int i = 0; i < NB_ANIMAUX; i++) {
            std::cout << "Animal " << i << ": ";
            zoo[i]->makeSound();
        }
        
        std::cout << "\nFermeture du zoo:" << std::endl;
        for (int i = 0; i < NB_ANIMAUX; i++) {
            delete zoo[i];
        }
    }
    std::cout << "\n--- Fin des Tests---" << std::endl;
    return 0;
}