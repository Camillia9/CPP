#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact {
private:
	std::string prenom;
	std::string nom;
	std::string surnom;
	std::string darksecret;
	std::string telephone;

public:
	Contact();
	Contact(std::string p, std::string n,	std::string s, std::string d, std::string t);
	
	// Getters
	std::string getPrenom();
	std::string getNom();
	std::string getSurnom();
	std::string getDarksecret();
	std::string getTelephone();

	// Setters
    void setPrenom(std::string p);
    void setNom(std::string n);
    void setSurnom(std::string s);
    void setDarksecret(std::string d);
    void setTelephone(std::string t);
};

#endif