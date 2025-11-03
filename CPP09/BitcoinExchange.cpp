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
