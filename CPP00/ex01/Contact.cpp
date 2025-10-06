#include "Contact.hpp"

Contact::Contact() {

}

Contact::Contact(std::string p, std::string n,	std::string s, std::string d, std::string t) {
	prenom = p;
	nom = n;
	surnom = s;
	darksecret = d;
	telephone = t;
}

std::string Contact::getPrenom() {
	return prenom;
}

std::string Contact::getNom() {
	return nom;
}

std::string Contact::getSurnom() {
	return surnom;
}

std::string Contact::getDarksecret() {
	return darksecret;
}

std::string Contact::getTelephone() {
	return telephone;
}

void Contact::setPrenom(std::string p) {
	prenom = p;
}

void Contact::setNom(std::string n) {
	nom = n;
}

void Contact::setSurnom(std::string s) {
	surnom = s;
}

void Contact::setDarksecret(std::string d) {
	darksecret = d;
}

void Contact::setTelephone(std::string t) {
	telephone = t;
}