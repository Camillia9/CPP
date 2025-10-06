#include "SedProcessor.hpp"

int main(int ac, char **av) {
	if (ac != 4) {
		std::cout  << "Usage: " << av[0] << " <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	SedProcessor sed(av[2], av[3]);
	if (!sed.processFile(av[1])) {
    	std::cout << "Erreur de traitement" << std::endl;
    	return 1;
	}
	return 0;
}
