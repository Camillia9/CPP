#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

class ValeurNotFondException : public std::exception {
public:
	const char* what()const throw() {
		return "Valeur non trouve";
	}
};

template<typename T>
typename T::iterator easyfind(T& containers, int value) {
	typename T::iterator it = containers.begin() =
		std::find(containers.begin(), containers.end(), value);

	if (it == containers.end())
		throw ValeurNotFondException();
	return it;
}

#endif