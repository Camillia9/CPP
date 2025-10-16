#include "easyfind.hpp"

int main () {

	std::cout << "~~~ TEST avec vecteur ~~~~\n";
	int array[] = {1, 2, 3, 4, 5};
	std::vector<int> vec(array, array + 5);

	try {
		std::vector<int>::iterator it = easyfind(vec, 5);
		std::cout << "Iterator trouve: " << *it << std::endl;
	} catch (const ValeurNotFondException& e) {
		std::cout << "Erreur: " << e.what() << std::endl;
	}

	std::cout << "~~~ TEST avec list ~~~~\n";
	int tab[] = {6, 7, 8, 9, 10};
	std::list<int> lst(tab, tab + 5);

	try {
		std::list<int>::iterator it = easyfind(lst, 4);
		std::cout << "Iterator trouve: " << *it << std::endl;
	} catch (const ValeurNotFondException& e) {
		std::cout << "Erreur: " << e.what() << std::endl;
	}
}