#include "BitcoinExchange.hpp"

int main(int ac, char **av) {
	(void)av;
	if (ac != 2) {
        std::cout << "Erreur arguments !" << std::endl;
		return 0;
    }
    
    BitcoinExchange exchange;
	exchange.loadData();
    // Charger data.csv -> Stocker les prix dans un conteneur
	// Lire input.txt -> Pour chaque ligne, appeller la fonction de calcul
	// Calculer -> Chercher le prix correspondant a la date, multiplie par la quantite
	// Validation -> Vérifie que les donnees sont correctes (format, plage de valeurs...)
    
    return 0;
}