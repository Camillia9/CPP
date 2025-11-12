#include "RPN.hpp"

bool RPN::isValidToken(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (!isdigit(str[i])
		&& str[i] != '+'
		&& str[i] != '-'
		&& str[i] != '*'
		&& str[i] != '/')
		return false;
	}
	return true;
}

bool RPN::isNumber(std::string str) {
    for (size_t i = 0; i < str.length(); i++) {
        if (!isdigit(str[i]))
            return false;
    }
    return true;
}