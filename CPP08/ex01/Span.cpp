#include "Span.hpp"

Span::Span() { 
	std::cout << "Default constructor Span is called" << std::endl;
}

Span::Span(int n) {
	std::cout << "Default constructor Span is called" << std::endl;
}

Span::Span(const Span& other) : _N(other._N) {
	std::cout << "Copy constructor Span is called" << std::endl;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Copy assignment operator Span is called" << std::endl;
	if (this != &other)
		_N = other._N;
	return *this;
}

Span::~Span() {
	std::cout << "Destructor Span is called" << std::endl;
}

void Span::addNumber(unsigned int N) {
	
}