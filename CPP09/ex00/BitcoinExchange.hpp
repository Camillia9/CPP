#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <sstream>

class BitcoinExchange {
private:
	std::map<std::string, float> _priceDatabase;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadData();
	void readData(const std::string &filename);
	
	bool DateIsValid(const std::string &date);
	int ValueIsValid(const std::string &value);
	double calculateData(const std::string &date, double value);
	
};

#endif