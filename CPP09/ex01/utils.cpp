#include "RPN.hpp"

bool RPN::isDigitOrMath(std::string str) {
	for (size_t i = 0; i < str.length(); i++) {
		if (isdigit(str[i]) || str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == ' ')
			return true;
		return false;
	}
}