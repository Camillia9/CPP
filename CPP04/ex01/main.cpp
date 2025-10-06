#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"
#include "WrongCat.hpp"

//int main() {
//	std::cout << "---Constructeur Animal---" << std::endl;
//	const Animal* meta = new Animal();
//	const Animal* j = new Dog();
//	const Animal* i = new Cat();
//	std::cout << std::endl;

//	std::cout << "---Constructeur WrongAnimal---" << std::endl;
//	const WrongAnimal* beta = new WrongAnimal();
//	const WrongAnimal* k = new WrongCat();
//	std::cout << std::endl;


//	std::cout << "j = " << j->getType() << std::endl;
//	std::cout << "i = "<< i->getType() << std::endl;
//	std::cout << "meta = "<< meta->getType() << std::endl;
//	std::cout << "k = "<< k->getType() << std::endl;
//	std::cout << "beta = "<< beta->getType() << std::endl;
//	std::cout << std::endl;
	
//	std::cout << "j = ";
//	j->makeSound();
//	std::cout << "i = ";
//	i->makeSound();
//	std::cout << "meta = ";
//	meta->makeSound();
	
//	std::cout << "k = ";
//	k->makeSound();
//	std::cout << "beta = ";
//	beta->makeSound();
//	std::cout << std::endl;

//	std::cout << "---Destructeur Animal---" << std::endl;
//	delete meta;
//	delete j;
//	delete i;
//	std::cout << std::endl;
//	std::cout << "---Destructeur WrongAnimal---" << std::endl;
//	delete beta;
//	delete k;
//	std::cout << std::endl;

//	return 0;
//}


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
    }

    std::cout << "\n--- TEST 2: Polymorphisme avec Brain ---" << std::endl;
    {
        Animal* animaux[4];
        animaux[0] = new Dog();
        animaux[1] = new Cat();
        animaux[2] = new Dog();
        animaux[3] = new Animal();
        
        std::cout << "\nTest polymorphisme:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "Animal " << i << " (" << animaux[i]->getType() << "): ";
            animaux[i]->makeSound();
        }
        
        std::cout << "\nSuppression des animaux:" << std::endl;
        for (int i = 0; i < 4; i++) {
            delete animaux[i];
        }
    }
    std::cout << std::endl;

    std::cout << "--- TEST 3: Tableau d'animaux ---" << std::endl;
    {
        const int NB_ANIMAUX = 4; // On teste avec 4 pour pas encombrer
        Animal* zoo[NB_ANIMAUX];
        
        std::cout << "Création du zoo:" << std::endl;
        zoo[0] = new Dog();
        zoo[1] = new Cat();
        zoo[2] = new Dog(); 
        zoo[3] = new Cat();
        
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