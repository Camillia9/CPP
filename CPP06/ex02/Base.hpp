#ifndef BASE_HPP
#define BASE_HPP

#include <iostream>
#include <string>

class Base {
public:
	virtual ~Base() {
		std::cout << "Destrucor Base is called" << std::endl;
	}

};

#endif