#include "BitcoinExchange.hpp"

bool BitcoinExchange::DateIsValid(const std::string& date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int year = std::atoi(date.substr(0, 4).c_str());
	int mounth = std::atoi(date.substr(5, 2).c_str());
	int days = std::atoi(date.substr(8, 2).c_str());

	if (year < 1000 || year > 9999)
		return false;
	if (mounth < 1 || mounth > 12)
		return false;
	if (days < 1 || days > 31)
		return false;
	return true;
}

int BitcoinExchange::ValueIsValid(const std::string &value) {
	std::stringstream ss(value);
	double numValue;
	ss >> numValue;
	if (ss.fail())
		return 1;
	if (!ss.eof())
		return 1;
	if (numValue < 0.0)
		return 2;
	if (numValue > 1000.0)
		return 3;
	return 0;
}

double BitcoinExchange::calculateData(const std::string &date, const double value) {
	std::map<std::string, float>::iterator it = _priceDatabase.find(date);

	if (it != _priceDatabase.end()) //La bonne date est trouvee
		return value * it->second;
	
	it = _priceDatabase.lower_bound(date);
	if (it == _priceDatabase.begin()) // La date est plus petite que celles existante: Ne peux donc pas retourner une date plus petite. Erreur.
		return -1;

	// Maintenant on peux retourner la premiere date plus petite en securite
	--it;
	return value * it->second;
}

