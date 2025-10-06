#ifndef SedProcessor_HPP
#define SedProcessor_HPP

#include <iostream>
#include <fstream>
#include <string>

class SedProcessor {
private:
	std::string s1, s2;

public:
	SedProcessor(const std::string& s1, const std::string& s2);
	std::string replaceString(const std::string& txt) const;
	bool processFile(const std::string& filename) const;
};

#endif