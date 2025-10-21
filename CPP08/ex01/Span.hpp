#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>

class Span {
private:
	unsigned int _N;
	size_t lenght;

public:
	Span();
	Span(int n);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(unsigned int N);
	int shortestSpan();
	int longestSpan();
};

#endif