#include "Span.hpp"

int main() {
srand(time(NULL));
{
	Span sp;
	std::cout << "~~~ TEST SIMPLE ~~~" << std::endl;
	try {
		sp.addNumber(4);
		sp.addNumber(7);
		sp.addNumber(2);
		sp.afficher();
		int shortest = sp.shortestSpan();
		std::cout<< std::endl;
		std::cout << "ShortestSpan = " << shortest << std::endl;
		int longuest = sp.longestSpan();
		std::cout << "LonguestSpan = " << longuest << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception attrapee" << std::endl;
	}
}
{
	std::cout << "\n~~~ TEST MORE NUMBERS ~~~" << std::endl;
	Span sp;
	try {
		std::vector<int> vec;
		for (int i = 0; i < 100000; ++i) {
    	// vec.push_back(i);
    	vec.push_back(rand() % 500000);
		}
		sp.addMoreNumbers(vec.begin(), vec.end());
		// sp.afficher();
		std::cout << std::endl;
		int longuest = sp.longestSpan();
		int shortest = sp.shortestSpan();
		std::cout << "LonguestSPan: " << longuest << std::endl;
		std::cout << "ShortestSpan: " << shortest << std::endl;

	} catch(std::exception& e) {
		std::cerr << "Erreur attrapee" << std::endl;
	}
}
}