#ifndef B_HPP
#define B_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class B : public Base {
public:
	~B() {
		std::cout << "Destructor B is called" << std::endl;
	}
};

#endif