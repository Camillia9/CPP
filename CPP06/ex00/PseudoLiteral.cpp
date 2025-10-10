#include "ScalarConverter.hpp"

std::string ScalarConverter::toLower(const std::string &str) {
	std::string result = str;

	for (size_t i = 0; i < result.length(); i++) {
		result[i] = tolower(result[i]);
	}
	return result;
}

Pseudo ScalarConverter::isPseudoLiteral(const std::string& literal) {
	std::string str = toLower(literal);

	if (str == "nan")
		return PSEUDO_NAN;
	else if (str == "nanf")
		return PSEUDO_NANF;
	else if (str == "+inf" || str == "inf")
		return PSEUDO_INF_POS;
	else if (str == "+inff" || str == "inff")
		return PSEUDO_INFF_POS;
	else if (str == "-inf")
		return PSEUDO_INF_NEG;
	else if (str == "-inff")
		return PSEUDO_INFF_NEG;
	else
		return NOT_PSEUDO;
}

void ScalarConverter::printPseudoLiteral(Pseudo pseudo) {
    // Char et Int sont toujours impossibles pour les pseudo-littéraux
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    
    // Float et Double dépendent du type de pseudo-littéral
    std::cout << "float: ";
    switch (pseudo) {
        case PSEUDO_NAN:
        case PSEUDO_NANF:
            std::cout << "nanf" << std::endl;
            break;
        case PSEUDO_INF_POS:
        case PSEUDO_INFF_POS:
            std::cout << "+inff" << std::endl;
            break;
        case PSEUDO_INF_NEG:
        case PSEUDO_INFF_NEG:
            std::cout << "-inff" << std::endl;
            break;
        default:
            break;
    }
    
    std::cout << "double: ";
    switch (pseudo) {
        case PSEUDO_NAN:
        case PSEUDO_NANF:
            std::cout << "nan" << std::endl;
            break;
        case PSEUDO_INF_POS:
        case PSEUDO_INFF_POS:
            std::cout << "+inf" << std::endl;
            break;
        case PSEUDO_INF_NEG:
        case PSEUDO_INFF_NEG:
            std::cout << "-inf" << std::endl;
            break;
        default:
            break;
    }
}
