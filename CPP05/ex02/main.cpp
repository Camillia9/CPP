#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main () {

	srand(time(NULL)); // Pour avoir une sequence de nombre differentes a chaque execution
	
	std::cout << "\n--- Test simple ShrubberyCreationForm ---" << std::endl;
	try {
		Bureaucrat bob("Bob", 100);
		ShrubberyCreationForm shrub("jardin");
		
		std::cout << bob;
		std::cout << shrub;
		
		bob.signForm(shrub);
		bob.executeForm(shrub);
		std::cout << shrub;
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Test Grade trop bas pour signer ---" << std::endl;
	try {
		Bureaucrat alice("Alice", 150);
		ShrubberyCreationForm shrub2("parc");
		
		std::cout << alice;
		std::cout << shrub2;
		
		alice.signForm(shrub2);
		alice.executeForm(shrub2);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Grade trop bas pour exécuter ---" << std::endl;
	try {
		Bureaucrat chef("Chef", 140);
		Bureaucrat stagiaire("Stagiaire", 145);
		ShrubberyCreationForm shrub3("foret");
		
		std::cout << chef;
		std::cout << stagiaire;
		std::cout << shrub3;
		
		chef.signForm(shrub3);
		stagiaire.executeForm(shrub3);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	std::cout << "\n--- Test simple RobotomyRequestForm ---" << std::endl;
	try {
		Bureaucrat paul("Paul", 40);
		RobotomyRequestForm robot("Bender");
		
		std::cout << paul;
		std::cout << robot;
		
		paul.signForm(robot);
		paul.executeForm(robot);
		
		// Essayer plusieurs fois pour voir le 50% de chance
		std::cout << "\n--- Deuxième tentative ---" << std::endl;
		paul.executeForm(robot);
		
		std::cout << "\n--- Troisième tentative ---" << std::endl;
		paul.executeForm(robot);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Grade trop bas pour executer ---" << std::endl;
	try {
		Bureaucrat junior("Junior", 50);
		RobotomyRequestForm robot2("Wall-E");
		
		std::cout << junior;
		std::cout << robot2;
		
		junior.signForm(robot2);  // Peut signer (50 < 72)
		junior.executeForm(robot2);  // Ne peut pas exécuter (50 > 45)
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	
	std::cout << "\n--- Test simple PresidentialPardonForm ---" << std::endl;
	try {
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president;
		std::cout << pardon;
		
		president.signForm(pardon);
		president.executeForm(pardon);
		} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
		std::cout << "\n--- Test grade trop bas---" << std::endl;
	try {
		Bureaucrat president("President", 50);
		PresidentialPardonForm pardon("Arthur Dent");
		
		std::cout << president;
		std::cout << pardon;
		
		president.signForm(pardon);
		president.executeForm(pardon);
	} catch (std::exception &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
	return 0;
}