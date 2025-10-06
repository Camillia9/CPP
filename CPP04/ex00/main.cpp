#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() {
	std::cout << "---Constructeur Animal---" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << std::endl;

	std::cout << "---Constructeur WrongAnimal---" << std::endl;
	const WrongAnimal* beta = new WrongAnimal();
	const WrongAnimal* k = new WrongCat();
	std::cout << std::endl;


	std::cout << "j = " << j->getType() << std::endl;
	std::cout << "i = "<< i->getType() << std::endl;
	std::cout << "meta = "<< meta->getType() << std::endl;
	std::cout << "k = "<< k->getType() << std::endl;
	std::cout << "beta = "<< beta->getType() << std::endl;
	std::cout << std::endl;
	
	std::cout << "j = ";
	j->makeSound();
	std::cout << "i = ";
	i->makeSound();
	std::cout << "meta = ";
	meta->makeSound();
	
	std::cout << "k = ";
	k->makeSound();
	std::cout << "beta = ";
	beta->makeSound();
	std::cout << std::endl;

	std::cout << "---Destructeur Animal---" << std::endl;
	delete meta;
	delete j;
	delete i;
	std::cout << std::endl;
	std::cout << "---Destructeur WrongAnimal---" << std::endl;
	delete beta;
	delete k;
	std::cout << std::endl;

	return 0;
}


//int main() {

//	Animal* zoo[3];
//    zoo[0] = new Dog();
//    zoo[1] = new Cat();
//    zoo[2] = new Animal();
    
//	for (int i = 0; i < 3; i++) {
//        zoo[i]->makeSound();
//	}
//	for (int i = 0; i < 3; i++) {
//    	delete zoo[i];
//	}
//}
