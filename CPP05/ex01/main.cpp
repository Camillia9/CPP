#include "Bureaucrat.hpp"
#include "Form.hpp"

int main () {
{
	std::cout << "~~~ Test Constructeur default ~~~" << std::endl;
	try {
		Bureaucrat employe;
		Form Formulaire;
		std::cout << employe << std::endl;
		std::cout << Formulaire << std::endl;
		std::cout << employe.getName() << " tente de signer le Formulaire... " << std::endl;
		employe.signForm(Formulaire);
		std::cout << Formulaire << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Erreur: "<< e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Test constructeur parametre ~~~" << std::endl;
	try {
		Bureaucrat employe("Bob", 50);
		Form Formulaire("Vacances", 50, 50);
		std::cout << employe << std::endl;
		std::cout << Formulaire << std::endl;
		std::cout << employe.getName() << " tente de signer le Formulaire... " << std::endl;
		employe.signForm(Formulaire);
		std::cout << Formulaire << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Erreur: " << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Erreur Grade to Sign ~~~" << std::endl;
	try {
		Bureaucrat employe("Jules", 51);
		Form Formulaire("Conge", 50, 159);
		std::cout << employe << std::endl;
		std::cout << Formulaire << std::endl;
		std::cout << employe.getName() << " tente de signer le Formulaire... " << std::endl;
		employe.signForm(Formulaire);
		std::cout << Formulaire << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Erreur: " << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Signer un formulaire 2 fois ~~~" << std::endl;
		Bureaucrat employe("Jack", 40);
		Form Formulaire("Sondage cafe gratuit", 50, 0);
		std::cout << employe << std::endl;
		std::cout << Formulaire << std::endl;
		std::cout << employe.getName() << " tente de signer le Formulaire... " << std::endl;
		employe.signForm(Formulaire);
		std::cout << Formulaire << std::endl;
		employe.signForm(Formulaire);
		std::cout << Formulaire << std::endl;
}
{
	std::cout << "\n~~~ Test operateur d'assignation ~~~" << std::endl;
	try {
		Form Form1("Demission", 50, 0);
		Form Form2("Test", 70, 0);
		Bureaucrat employe("Dany", 1);
		std::cout << "Avant:" << std::endl;
		employe.signForm(Form1);
		std::cout << Form1 << std::endl;
		std::cout << Form2 << std::endl;
		Form2 = Form1;
		std::cout << "Apres:" << std::endl;
		std::cout << Form1 << std::endl;
		std::cout << Form2 << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
{
	std::cout << "\n~~~ Test constructeur de copie ~~~" << std::endl;
	try {
		Form Original("Affectation",71, 0);
		Form Copie(Original);
		std::cout << Original << std::endl;
		std::cout << Copie << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
}
	return 0;
}