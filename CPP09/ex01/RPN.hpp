#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <vector>

class RPN {
private:
	std::stack<int>value;
	std::vector<int>token;

public:
	RPN();
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();

	void tokenisation(std::string num);
	bool isDigitOrMath(std::string str);
};

#endif