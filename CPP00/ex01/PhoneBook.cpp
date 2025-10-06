#include "PhoneBook.hpp"
#include <limits>

PhoneBook::PhoneBook() {
	nbContact = 0;
}

std::string tronquer(std::string texte, long  int longueur) {
	if (texte.length() > longueur) {
		return texte.substr(0, longueur - 1) + ".";
	}
	return texte;
}

void PhoneBook::Add() {
	Contact NewContact;
	std::string tmp;

	std::cout << "===Creation d'un nouveau contact===" << std::endl;
	do {
	std::cout << "Prenom : ";
	std::getline(std::cin, tmp);
	} while (tmp.empty());
	NewContact.setPrenom(tmp);
	do {	
	std::cout << "Nom : ";
	std::getline(std::cin, tmp);
	} while (tmp.empty());
	NewContact.setNom(tmp);
	do {
	std::cout << "Surnom : ";
	std::getline(std::cin, tmp);
	} while (tmp.empty());
	NewContact.setSurnom(tmp);
	do {
	std::cout << "DarkSecret : ";
	std::getline(std::cin, tmp);
	} while (tmp.empty());
	NewContact.setDarksecret(tmp);
	do {
	std::cout << "Numero de telephone : ";
	std::getline(std::cin, tmp);
	} while (tmp.empty());
	NewContact.setTelephone(tmp);
	if (nbContact < 2) {
		contacts[nbContact] = NewContact;
		nbContact++;
	} else {
		std::cout << "Repertoire plein -> Contact le plus ancien remplace" << std::endl;
		for(int i = 0; i < 1; i++) {
			contacts[i] = contacts[i + 1];
		}
		contacts[1] = NewContact;
	}
	std::cout << "===Nouveau Contact ajoute===" << std::endl;
}

void PhoneBook::Search() {
	if (nbContact == 0) {
		std::cout << "Repertoire vide. Ajoute des contacts avec ADD." << std::endl;
		return;
	}
	std::cout << "|" << std::setw(10) << "Index";
	std::cout << "|" << std::setw(10) << "First Name";
	std::cout << "|" << std::setw(10) << "Last Name";
	std::cout << "|" << std::setw(10) << "Nickname" << "|" << std::endl;
	
	for (int i = 0; i < nbContact; i++) {
		std::cout << "|" << std::setw(10) << i;
		std::cout << "|" << std::setw(10) << tronquer(contacts[i].getPrenom(), 10);
		std::cout << "|" << std::setw(10) << tronquer(contacts[i].getNom(), 10);
		std::cout << "|" << std::setw(10) << tronquer(contacts[i].getSurnom(), 10) << "|" << std::endl; 
	}
	int idx;
	std::cout << "Veuillez entrez l'index du contact a afiche" << std::endl;
	std:: cin >> idx;
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Erreur. Entrez un nombre entier" << std::endl;
		return;
	}
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore le /n qui reste dans le buffer et qui met un message erreur
	if (idx >= 0 && idx <= nbContact - 1) {
		std::cout << "Prenom : " << contacts[idx].getPrenom() << std::endl;
		std::cout << "Nom : " << contacts[idx].getNom() << std::endl;
		std::cout << "Surnom : " << contacts[idx].getSurnom() << std::endl;
		std::cout << "Dark Secret : " << contacts[idx].getDarksecret() << std::endl;
		std::cout << "Numero de telephone : " << contacts[idx].getTelephone() << std::endl;
	} else {
		std::cout << "Erreur. Index incorrect." << std::endl;
	}
}