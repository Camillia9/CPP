#include "SedProcessor.hpp"

std::string SedProcessor::replaceString(const std::string& txt) const {
	if (s1.empty())
		return txt;
	size_t pos = 0;
	std::string result = "";
	while (pos < txt.length()) {
		size_t found = txt.find(s1, pos);
		if (found != std::string::npos) {
			std::string avant = txt.substr(pos, found - pos);
			result += avant; 
			result += s2;
			pos = found + s1.length();
		} else {
			result += txt.substr(pos);
			break;
		}
	}
	return result;
}
