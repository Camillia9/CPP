#include "Serialization.hpp"

int main () {

	Data data;
	data.valeur = 20;
	data.txt = "Hello";
	data.c = 'C';

	Data* ptr1 = &data;

	std::cout << "Pointeur original: " << ptr1 << std::endl;

	uintptr_t nombre = Serialization::serialize(ptr1);
	std::cout << "En nombre: " << nombre << std::endl;

	Data* ptr2 = Serialization::deserialize(nombre);
	std::cout << "Pointeur recupere: " << ptr2 << std::endl;

	if (ptr1 == ptr2) {
		std::cout << "Les pointeurs sont identiques (OK)" << std::endl;
		std::cout << "On peut acceder aux donnes: " << std::endl;
		std::cout << "Valeur: " << ptr2->valeur << std::endl;
		std::cout << "Txt: " << ptr2->txt << std::endl;
		std::cout << "Char: " << ptr2->c << std::endl;
	} else {
		std::cout << "PROBLEME" << std::endl;
	}
	return 0;
}