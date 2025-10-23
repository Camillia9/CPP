#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <climits>

class Span {
private:
	unsigned int _max_size;
	std::vector<int> numbers;

public:
	Span();
	Span(unsigned int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int value);
	int shortestSpan();
	int longestSpan();
	void afficher();
};


#endif