#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <stack>
#include <vector>

class RPN {
private:
	std::stack<int>value;
	std::vector<std::string>token;

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void tokenisation(std::string num);
	bool isValidToken(std::string str);
	bool isNumber(std::string str);
	bool validateAllTokens();
	void evaluateRPN();
};

#endif