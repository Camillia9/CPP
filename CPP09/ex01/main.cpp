#include "RPN.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Error: 2 argumets required" << std::endl;
		return 0;
	}
	RPN rpn;
	rpn.tokenisation(av[1]);
	if (!rpn.validateAllTokens())
		return -1;
	rpn.evaluateRPN();
}