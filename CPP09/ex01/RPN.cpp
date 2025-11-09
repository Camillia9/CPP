#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN& other) {
	(void)other;
}

RPN& RPN::operator=(const RPN& other) {
	(void)other;
	return *this;
}

RPN::~RPN() {}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void RPN::tokenisation(std::string num) {
	std::string tmp = "";
	for (size_t i = 0; i < num.length(); i++) {
		if (num[i] == ' ') {
			if (!tmp.empty()) {
				token.push_back(tmp);
				tmp = "";
			}
		} else {
			tmp += num[i];
		}
		if (!tmp.empty())
			token.push_back(tmp);
	}
}