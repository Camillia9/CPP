#include "Span.hpp"

Span::Span() { 
	std::cout << "Default constructor Span is called" << std::endl;
}

Span::Span(unsigned int n) : _max_size(n) {
	std::cout << "Default constructor Span is called" << std::endl;
}

Span::Span(const Span& other) : _max_size(other._max_size) {
	std::cout << "Copy constructor Span is called" << std::endl;
}

Span& Span::operator=(const Span& other) {
    std::cout << "Copy assignment operator Span is called" << std::endl;
	if (this != &other)
		_max_size = other._max_size;
	return *this;
}

Span::~Span() {
	std::cout << "Destructor Span is called" << std::endl;
}

void Span::addNumber(int value) {
	if (numbers.size() >= _max_size)
		throw std::exception();
	numbers.push_back(value);
}

void Span::afficher() {
	std::cout << "Afficher la pile: " << std::endl;
	for (size_t i = 0; i < numbers.size(); i++) {
		std::cout << numbers[i] << std::endl;
	}
}

int Span::shortestSpan() {
	if (numbers.size() <= 1)
		throw std::exception();
	std::sort(numbers.begin(), numbers.end());

	// std::cout << "Triage de la pile:" << std::endl;
	// for (size_t i = 0; i < numbers.size(); i++) {
	// 	std::cout << numbers[i] << std::endl;
	// }

	std::vector<int>::iterator current = numbers.begin();
	std::vector<int>::iterator next = current;
	next++;

	int min_ecart = INT_MAX;
	while (next != numbers.end()) {
		int ecart = *next - *current;
		if (ecart < min_ecart)
			min_ecart = ecart;
		current++;
		next++;
	}
	return min_ecart;
}

int Span::longestSpan() {
	std::sort(numbers.begin(), numbers.end());

	std::vector<int>::iterator begin = numbers.begin();
	std::vector<int>::iterator end = numbers.end() - 1;

	return *end - *begin;
}