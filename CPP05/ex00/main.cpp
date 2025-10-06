#include "Bureaucrat.hpp"

int main () {
{
	std::cout << "~~~ Test Constructeur default ~~~" << std::endl;
	try {
		Bureaucrat employe;
		std::cout << employe << std::endl;
		employe.downGrade();
		std::cout << employe << std::endl;
		employe.upGrade();
		std::cout << employe << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Test constructeur parametre ~~~" << std::endl;
	try {
		Bureaucrat Bob("Bob", 50);
		std::cout << Bob << std::endl;
		Bob.downGrade();
		std::cout << Bob << std::endl;
		Bob.upGrade();
		std::cout << Bob << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Erreur Grade trop bas ~~~" << std::endl;
	try {
		Bureaucrat Jules("Jules", 150);
		std::cout << Jules << std::endl;
		Jules.downGrade();
		std::cout << Jules << std::endl;
		Jules.upGrade();
		std::cout << Jules << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Erreur Grade trop haut ~~~" << std::endl;
	try {
		Bureaucrat Jack("Jack", 0);
		std::cout << Jack << std::endl;
		Jack.upGrade();
		std::cout << Jack << std::endl;
		Jack.downGrade();
		std::cout << Jack << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Erreur Grade invalide 1 ~~~" << std::endl;
	try {
		Bureaucrat Poule("Poule", 0);
		std::cout << Poule << std::endl;
		Poule.upGrade();
		std::cout << Poule << std::endl;
		Poule.downGrade();
		std::cout << Poule << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Erreur Grade invalide 2 ~~~" << std::endl;
	try {
		Bureaucrat Lion("Lion", 151);
		std::cout << Lion << std::endl;
		Lion.upGrade();
		std::cout << Lion << std::endl;
		Lion.downGrade();
		std::cout << Lion << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Test constructeur de copie ~~~" << std::endl;
	try {
		Bureaucrat Original("Original",71);
		Bureaucrat Copie(Original);
		std::cout << Original << std::endl;
		std::cout << Copie << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Test operateur d'assignation ~~~" << std::endl;
	try {
		Bureaucrat Tim("Tim", 50);
		Bureaucrat Gob("Gob", 80);
		std::cout << "Avant:" << std::endl;
		std::cout << Tim << std::endl;
		std::cout << Gob << std::endl;
		Tim = Gob;
		std::cout << "Apres:" << std::endl;
		std::cout << Tim << std::endl;
		std::cout << Gob << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}

	return 0;

}