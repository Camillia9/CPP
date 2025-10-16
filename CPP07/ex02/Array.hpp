#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T>
class Array {
private:
	T* _elements;		// Pointeur vers les elements
	unsigned int _size;  // nb elements

public:
	Array() : _elements(NULL), _size(0) {}

	Array(unsigned int n) : _elements(new T[n]), _size(n) {}

	Array(const Array& other) {
		_size = other._size;
		_elements = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_elements[i] = other._elements[i];
	}

	Array& operator=(const Array& other) {
		if (this != &other) {
			delete[] _elements;
			_size = other._size;
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++)
				_elements[i] = other._elements[i];
		}
		return *this;
	}

	~Array() {
		delete[] _elements;
	}

	T& operator[](unsigned int idx) {
		if (idx >= _size)
			throw std::exception();
		return _elements[idx];
	}

	const T& operator[](unsigned int idx)const {
		if (idx >= _size)
			throw std::exception();
		return _elements[idx];
	}

	unsigned int size() const {
    	return _size;
	}

};

#endif