#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>

class BitcoinExchange {
private:
	std::map<std::string, float> _priceDatabase;

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void loadData();
	void readData();
	void calculateData();
};

//template<typename T>


#endif