#include "PhoneBook.hpp"

int main() {
	Contact contact1;
	PhoneBook repertoire;
	std::string commande;

	std::cout << "Repertoire ouvert :" << std::endl;
	std::cout << "tapez 'ADD' pour ajouter un contact" << std::endl;
	std::cout << "tapez 'SEARCH' pour verifier le repertoire" << std::endl;
	std::cout << "tapez 'EXIT' pour sortir du repertoire" << std::endl;

	while(1) {
		std::cout << "> ";
		if (!std::getline(std::cin, commande)){ // Gerer le CTRL-D
			std::cout << "^D" << std::endl;
			break;
		} 
		if (commande == "ADD") {
			repertoire.Add();
		} else if (commande == "SEARCH") {
			repertoire.Search();
		} else if (commande == "EXIT") {
			return 0;
		} else {
			std::cout << "Commande inconnu, veuillez reessayer" << std::endl;
			std::cout << "Tapez ADD, SEARCH ou EXIT" << std::endl;
		}
	}
	return 0;
}