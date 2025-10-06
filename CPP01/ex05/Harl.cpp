#include "Harl.hpp"

void Harl::debug() {
	std:: cout << "debug" << std::endl;
}

void Harl::info() {
	std:: cout << "info" << std::endl;
}

void Harl::warning() {
	std:: cout << "warning" << std::endl;
}

void Harl::error() {
	std:: cout << "error" << std::endl;
}

void Harl::complain(std::string level) {
	void (Harl::*fonctions[4])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i <4; i++) {
		if (levels[i] == level) {
			(this->*fonctions[i])();
			return;
		}
	}
}

