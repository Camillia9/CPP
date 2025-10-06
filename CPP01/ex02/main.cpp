#include <iostream>
#include <string>

int main() {

	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;
	
	std::cout << "Adresse mémoire de la string string: " << &string << std::endl;
	std::cout << "Adresse mémoire détenue par stringPTR: " << stringPTR << std::endl;
	std::cout << "Adresse mémoire détenue par stringREF: " << &stringREF << std::endl;

	std::cout << "Valeur string: " << string << std::endl;
	std::cout << "Valeur pointée par stringPTR: " << *stringPTR << std::endl;
	std::cout << "Valeur pointée par stringREF.: " << stringREF << std::endl;

}