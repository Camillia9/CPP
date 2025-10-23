#include "Span.hpp"

int main() {
	Span sp;
	std::cout << "~~~ TEST SIMPLE ~~~" << std::endl;
	try {
		sp.addNumber(4);
		sp.addNumber(7);
		sp.addNumber(2);
		sp.afficher();
		std::cout<< std::endl;
		int shortest = sp.shortestSpan();
		std::cout<< std::endl;
		std::cout << "ShortestSpan = " << shortest << std::endl;
		int longuest = sp.longestSpan();
		std::cout << "LonguestSpan = " << longuest << std::endl;
	} catch (std::exception& e) {
		std::cerr << "Exception attrapee" << std::endl;
	}
}