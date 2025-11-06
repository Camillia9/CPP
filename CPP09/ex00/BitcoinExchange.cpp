#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	(void)other;
}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	(void)other;
	return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void BitcoinExchange::loadData() {
	std::ifstream file("data.csv");
	if (!file.is_open()) {
		std::cerr << "Error: cannot open file !" << std::endl;
		return;
	}
	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (firstLine){
			firstLine = false;
			continue;
		}
		size_t pos = line.find(",");
		std::string date = line.substr(0, pos);
		std::string value = line.substr(pos + 1);
		float price = std::atof(value.c_str());
		_priceDatabase[date] = price;
	}
	file.close();
}

void BitcoinExchange::readData(const std::string &filename) {
	std::ifstream file(filename.c_str());
	if (!file.is_open()) {
		std::cerr << "Error: cannot open file" << std::endl;
		return;
	}
	std::string line;
	bool firstLine = true;
	while (std::getline(file, line)) {
		if (firstLine) {
			firstLine = false;
			continue;
		}
		if (line.find("|") == std::string::npos) {
			std::cerr << "bad input => " << line << std::endl;
			continue;
		}
		size_t pos = line.find("|");
		std::string date = line.substr(0, pos - 1); // pour ne pas compter l'espace avant le '|'
		std::string value = line.substr(pos + 1);
		if (!DateIsValid(date)) {
			std::cerr << "Error: bad input => " << date << std::endl;
			continue;
		}
		int validnum = ValueIsValid(value);
		if (validnum == 1) {
			std::cerr << "Error: bad input =>" << date << std::endl;
			continue;
		}
		else if (validnum == 2) {
			std::cerr << "Error: not a positive number" << std::endl;
			continue;
		}
		else if (validnum == 3) {
			std::cerr << "Error: too large a number" << std::endl;
			continue;
		}
		double numValue = std::atof(value.c_str());
		double result = calculateData(date, numValue);

		if (result == -1) {
			std::cerr << "Error: not a price before this date => " << date << std::endl;
			continue;
		}
		std::cout << date << " => " << value << " = " << result << std::endl;
	}
}