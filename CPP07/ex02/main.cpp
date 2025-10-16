#include "Array.hpp"

int main() {
	std::cout << "\n~~~ TEST tableau vide ~~~\n";
	Array<int> empty;
    std::cout << "Taille du tableau: " << empty.size() << std::endl;
    
	std::cout << "\n~~~ TEST tableau rempli ~~~\n";
    Array<int> numbers(5);
    std::cout << "Taille du tableau: " << numbers.size() << std::endl;

	// Remplissage du tableau
	for (unsigned int i = 0; i < numbers.size(); i++)
		numbers[i] = i * 10;

	std::cout << "Tableau numbers: ";
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "[" << numbers[i] << "]";
	std::cout << std::endl;

	std::cout << "\n~~~ TEST constructeur de copie ~~~\n";

	Array<int>copy(numbers);
	std::cout << "Copy : ";
	for (unsigned int i = 0; i < copy.size(); i++)
 		std::cout << "[" << copy[i] << "]";
	std::cout << std::endl;

	std::cout << "Modif de copy: " << std::endl;
	for (unsigned int i = 0; i < copy.size(); i++)
		copy[i] = 42;
	for (unsigned int i = 0; i < copy.size(); i++)
 		std::cout << "[" << copy[i] << "]";
	std::cout << std::endl;

	std::cout << "Original: " << std::endl;
	for (unsigned int i = 0; i < numbers.size(); i++)
		std::cout << "[" << numbers[i] << "]";
	std::cout << std::endl;

	// Opreateur d'assignantions 
	std::cout << "\n ~~~ TEST Operateur assignation = ~~~\n";
	Array<int> num(3);
	num[0] = 7;
	num[1] = 77;
	num[2] = 777;

	std::cout << "Creation du nouveau tableau num: " << std::endl;
	std::cout << "num.size: " << num.size() << std::endl;
	for (unsigned int i = 0; i < num.size(); i++)
		std::cout << "[" << num[i] << "]";
	std::cout << std::endl;

	// Assigner numbers a num
	num = numbers;

	std::cout << "Apres assigantion: " << std::endl;
	std::cout << "num.size: " << num.size() << std::endl;
	std::cout << "nouveau num: ";
	for (unsigned int i = 0; i < num.size(); i++)
		std::cout << "[" << num[i] << "]";
	std::cout << std::endl;

	std::cout << "\n ~~~ TEST Exception ~~~\n";
	try {
		std::cout << numbers[100] << std::endl;
	} catch (std::exception& e) {
		std::cout << "Exception attrape !" << std::endl;
	}

	std::cout << "\n ~~~ TEST avec string ~~~\n";
	Array<std::string>words(3);
	words[0] = "Hey";
	words[1] = "Ciao";
	words[2] = "Flash";

	for (unsigned i = 0; i < words.size(); i++) 
		std::cout << "[" << words[i] << "]";
	std::cout << std::endl;
	
	return 0;
}