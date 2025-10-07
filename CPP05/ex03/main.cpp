#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

    Intern stagiaire;
    AForm* form1 = NULL;
    AForm* form2 = NULL;
    AForm* form3 = NULL;

{
    std::cout << "--- TEST 1: Intern crée des formulaires ---" << std::endl;
    
    try {
        form1 = stagiaire.makeForm("shrubbery creation", "jardin");
        std::cout << *form1 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
    
    try {
        form2 = stagiaire.makeForm("robotomy request", "Bender");
        std::cout << *form2 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
    
    try {
        form3 = stagiaire.makeForm("presidential pardon", "Arthur Dent");
        std::cout << *form3 << std::endl;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
}
{
    std::cout << "\n--- TEST 2: Formulaire inexistant ---" << std::endl;
    
    AForm* form3 = NULL;
    try {
        form3 = stagiaire.makeForm("vacation request", "Bob");
    } catch (std::exception &e) {
        std::cerr << "Erreur capturée: " << e.what() << std::endl;
    }
}
{
    std::cout << "\n--- TEST 3: RobotomyRequestForm ---" << std::endl;
    
    try {
        Bureaucrat david("David", 1);
        std::cout << david << std::endl;
        
        AForm* robotForm = stagiaire.makeForm("robotomy request", "Marvin");
        
        david.signForm(*robotForm);
        std::cout << *robotForm << std::endl;
        
        // Teste plusieurs fois pour voir le résultat aléatoire
        std::cout << "\nTentative 1:" << std::endl;
        david.executeForm(*robotForm);
        
        std::cout << "\nTentative 2:" << std::endl;
        david.executeForm(*robotForm);
        
        std::cout << "\nTentative 3:" << std::endl;
        david.executeForm(*robotForm);
        
    	delete robotForm;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
}
{
    std::cout << "\n--- TEST 4: PresidentialPardonForm - Exécution sans signature ---" << std::endl;
    
    try {
        Bureaucrat eve("Eve", 1);
        std::cout << eve << std::endl;
        
        if (form3) {
            eve.executeForm(*form3);
        }
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
}
{
    std::cout << "\n--- TEST 5: Test complet ---" << std::endl;
    
    try {
        Intern newIntern;
        Bureaucrat superBoss("Super Boss", 1);
        
        std::cout << superBoss << std::endl;
        
        // Créer plusieurs formulaires
        AForm* f1 = newIntern.makeForm("shrubbery creation", "home");
        AForm* f2 = newIntern.makeForm("robotomy request", "R2D2");
        AForm* f3 = newIntern.makeForm("presidential pardon", "Ford Prefect");
        
        std::cout << "\n~~~ Signature de tous les formulaires ~~~" << std::endl;
        superBoss.signForm(*f1);
        superBoss.signForm(*f2);
        superBoss.signForm(*f3);
        
        std::cout << "\n~~~ Exécution de tous les formulaires ~~~" << std::endl;
        superBoss.executeForm(*f1);
		std::cout << std::endl;
        superBoss.executeForm(*f2);
		std::cout << std::endl;
        superBoss.executeForm(*f3);
		std::cout << std::endl;
        
        delete f1;
        delete f2;
        delete f3;
    } catch (std::exception &e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }
}
{
    std::cout << "\n--- NETTOYAGE ---" << std::endl;
    
    delete form1;
    delete form2;
    delete form3;
} 
    return 0;
}