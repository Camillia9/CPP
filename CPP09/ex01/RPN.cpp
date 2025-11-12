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
			token.push_back(tmp);
			tmp = "";
		} else
			tmp = num[i];
	}
	if (!tmp.empty())
		token.push_back(tmp);
}

bool RPN::validateAllTokens() {
    for (size_t i = 0; i < token.size(); i++) {
        if (!isValidToken(token[i])) {
            std::cerr << "Error" << std::endl;
            return false;
        }
    }
    return true;
}

void RPN::evaluateRPN() {
	for(size_t i = 0; i < token.size(); i++) {
		std::string tok = token[i];
		if (isNumber(tok)) {
			int nb = std::atoi(tok.c_str());
			value.push(nb);
		} else {
			if (value.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}
			int droite = value.top();
			value.pop();
			int gauche = value.top();
			value.pop();
			char operateur = tok[0];
			int resultat = 0;
			if (operateur == '+')
				resultat = gauche + droite;
			else if (operateur == '-')
				resultat = gauche - droite;
			else if (operateur == '*')
				resultat = gauche * droite;
			else if (operateur == '/') {
				if (droite == 0) {
					std::cerr << "Error: Division for 0" << std::endl;
					return;
				}
				resultat = gauche / droite;
			}
			value.push(resultat);
		}
	}
	if (value.size() != 1) {
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << value.top() << std::endl;
}