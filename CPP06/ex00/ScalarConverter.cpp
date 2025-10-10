#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {
	std::cout << "Default constructor ScalarConverter is called" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {
	std::cout << "Destructor ScalarConverter is called" << std::endl;
}

void ScalarConverter::convert(const std::string& literal) {
	Pseudo pseudo = isPseudoLiteral(literal);
	if (pseudo != NOT_PSEUDO) {
		printPseudoLiteral(pseudo);
		return;
	}
	if (isInt(literal)) {
	// Convertir en double d'abord pour détecter l'overflow
    double doubleValue = std::atof(literal.c_str());
    
    // Vérifier si ça rentre dans un int
    if (doubleValue < INT_MIN || doubleValue > INT_MAX) {
        std::cout << "char: impossible (overflow)" << std::endl;
        std::cout << "int: impossible (overflow)" << std::endl;
        std::cout << "float: " << std::fixed << std::setprecision(1) 
                  << static_cast<float>(doubleValue) << "f" << std::endl;
        std::cout << "double: " << std::fixed << std::setprecision(1) 
                  << doubleValue << std::endl;
        return;
    }

    // Si on arrive ici, c'est safe de convertir en int
    int value = static_cast<int>(doubleValue);

		// INT
		std::cout << "int: " << value << std::endl;

		//CHAR
		std::cout << "char: ";
        if (value < 0 || value > 127) {
            std::cout << "impossible" << std::endl;
        } else if (!std::isprint(static_cast<char>(value))) {
            std::cout << "Non displayable" << std::endl;
        } else {
            std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
        }
		
		// FLOAT
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< static_cast<float>(value) << "f" << std::endl;

		// DOUBLE
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(value) << std::endl;

	} else if (isChar(literal)) {
		char charValue;

		// CHAR
		if (literal.length() == 1)
			charValue = literal[0];
		else
			charValue = literal[1];

		std::cout << "char: '" << charValue <<  "'" << std::endl;

		// INT
		int intValue = static_cast<int>(charValue);
		std::cout << "int: " << intValue << std::endl;

		// FLOAT
		float floatValue = static_cast<float>(charValue);
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< floatValue << "f" << std::endl;

		// DOUBLE
		double doubleValue = static_cast<double>(charValue);
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< doubleValue << std::endl;

	} else if (isFloat(literal)) {
		float floatValue = std::atof(literal.c_str());

		// CHAR
		bool isInteger = (floatValue == static_cast<int>(floatValue)); // verification si c'est un nb entier
		
		std::cout << "char: ";
		if (!isInteger) {
			std::cout << "Impossible (Not integer)" << std::endl;
		} else if (floatValue < 0 || floatValue > 127){
			std::cout << "Impossible (Not plage ASCII)";
		} else if (!std::isprint(static_cast<char>(floatValue))) {
			std::cout << "Non Displayable" << std::endl;
		} else {
			std::cout  << "'" << static_cast<char>(floatValue) << "'" << std::endl;
		}

		// INT
		std::cout << "int: ";
		if (static_cast<double>(floatValue) < INT_MIN || 
    		static_cast<double>(floatValue) > INT_MAX) {
			std::cout << "Impossible (overflow)" << std::endl;
		} else {
			std::cout << static_cast<int>(floatValue) << std::endl;
		}

		// FLOAT
		std::cout << "float: " << std::fixed << std::setprecision(1)
				<< floatValue << "f" << std::endl;

		// Double
		std::cout << "double: " << std::fixed << std::setprecision(1)
				<< static_cast<double>(floatValue) << std::endl;

	} else if (isDouble(literal)) {
		double doubleValue = std::atof(literal.c_str());

		// CHAR 
    	std::cout << "char: ";
    	bool isInteger = (doubleValue == static_cast<int>(doubleValue));
		
    	if (!isInteger) {
    	    std::cout << "Impossible (Not integer)" << std::endl;
    	} else if (doubleValue < 0 || doubleValue > 127) {
    	    std::cout << "impossible" << std::endl;
    	} else if (!std::isprint(static_cast<char>(doubleValue))) {
    	    std::cout << "Non Displayable" << std::endl;
    	} else {
    	    std::cout << "'" << static_cast<char>(doubleValue) << "'" << std::endl;
    	}

    	// INT
    	std::cout << "int: ";
    	if (doubleValue < INT_MIN || doubleValue > INT_MAX) {
    	    std::cout << "impossible" << std::endl;
    	} else {
    	    std::cout << static_cast<int>(doubleValue) << std::endl;
    	}
	
    	// FLOAT
    	std::cout << "float: " << std::fixed << std::setprecision(1) 
    	          << static_cast<float>(doubleValue) << "f" << std::endl;
	
    	// DOUBLE
    	std::cout << "double: " << std::fixed << std::setprecision(1) 
    	          << doubleValue << std::endl;
	} else {
    	std::cout << "Error: Invalid literal format" << std::endl;
	}
}

