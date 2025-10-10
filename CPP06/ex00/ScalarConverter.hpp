#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <iomanip>
#include <cstdlib>
#include <climits>

enum Type {
	CHAR,      
    INT,      
    FLOAT,    
    DOUBLE,   
    PSEUDO    
};

enum Pseudo {
	PSEUDO_NAN,			
	PSEUDO_NANF,		
	PSEUDO_INF_POS,		
	PSEUDO_INF_NEG,		
	PSEUDO_INFF_POS,	
	PSEUDO_INFF_NEG,	
	NOT_PSEUDO			
};

class ScalarConverter {
private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static bool isInt(const std::string &literal);
	static bool isChar(const std::string &literal);
	static bool isDouble(const std::string &literal);
	static bool isFloat(const std::string &literal);

	static Pseudo isPseudoLiteral(const std::string& literal);
	static std::string toLower(const std::string &str);
	static void printPseudoLiteral(Pseudo pseudo);
	
	public:
	static void convert(const std::string& literal);
};


#endif