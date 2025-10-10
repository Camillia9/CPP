#include "ScalarConverter.hpp"

bool ScalarConverter:: isInt(const std::string &literal) {
	if (literal.empty())
		return false;

	size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;
	
	if (start >= literal.length()) // Verif s'il reste au moins un carateres apres le signe
		return false;

	// Verif que les caracteres restant sont QUE des chiffres
	if (literal.find_first_not_of("0123456789", start) != std::string::npos)
		return false;
	
	return true;
}

bool ScalarConverter:: isChar(const std::string &literal) {
	if (literal.empty())
		return false;

	if (literal.length() == 1 && !std::isdigit(literal[0]))
		return true;

	if (literal.length() == 3 && literal[0] == '\'' && literal[literal.length() - 1] == '\'')
    	return true;

	return false;
}

bool ScalarConverter:: isFloat(const std::string &literal) {
	if (literal.empty() || literal.length() < 3) //Min 0.f
		return false;

	if (literal[literal.length() - 1] != 'f' && literal[literal.length() - 1] != 'F') // checker le f a a fin
		return false;

	std::string withoutF = literal.substr(0, literal.length() - 1); //enleve le f

	// Check s'il ya exactement 1 '.' :
    size_t firstDot = withoutF.find('.');
    size_t lastDot = withoutF.rfind('.');
    if (firstDot == std::string::npos || firstDot != lastDot) {
        return false;
	}

	if (firstDot == 0 || firstDot == withoutF.length() - 1) {
		return false;  // Le point ne doit pas être au début ou à la fin
	}

	size_t start = (withoutF[0] == '-' || withoutF[0] == '+') ? 1 : 0;

	if (start >= withoutF.length()) // Reste t-il des caractere apres le signe ?
		return false;
	
	if (withoutF.find_first_of("0123456789") == std::string::npos) // y'a t-il au moins un chiffre?
		return false;

	//Le reste ne doit contenir que des chiffres et un point:
	if (withoutF.find_first_not_of("0123456789.", start) != std::string::npos)	
			return false;

	return true;
}

bool ScalarConverter:: isDouble(const std::string &literal) {
	if (literal.empty() || literal.length() < 3)
		return false;

	if (literal[literal.length() - 1] == 'f' || literal[literal.length() - 1] == 'F')
        return false;

    size_t firstDot = literal.find('.');
    size_t lastDot = literal.rfind('.');
    if (firstDot == std::string::npos || firstDot != lastDot) {
        return false;
	}
	if (firstDot == 0 || firstDot == literal.length() - 1) {
    	return false;  // Le point ne doit pas être au début ou à la fin
	}

	size_t start = (literal[0] == '-' || literal[0] == '+') ? 1 : 0;

	if (start >= literal.length())
		return false;

	// Vérifier qu'il y a au moins un chiffre
    if (literal.find_first_of("0123456789") == std::string::npos) {
        return false;
	}

	if (literal.find_first_not_of("0123456789.", start) != std::string::npos) {
        return false;
	}

	return true;
}
