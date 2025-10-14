#ifndef C_HPP
#define C_HPP

#include <iostream>
#include <string>
#include "Base.hpp"

class C : public Base {
public:
	~C() {
		std::cout << "Destructor C is called" << std::endl;
	}
};

#endif