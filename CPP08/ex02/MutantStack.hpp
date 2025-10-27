#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T> {
public:
	typedef typename std::deque<T>::iterator iterator;
	typedef typename std::deque<T>::reverse_iterator reverse_iterator;

	typename std::deque<T>::iterator begin() {
		return this->c.begin();
	}
	typename std::deque<T>::iterator end() {
		return this->c.end();
	}
	typename std::deque<T>::reverse_iterator rbegin() {
		return this->c.rbegin();
	}
	typename std::deque<T>::reverse_iterator rend() {
		return this->c.rend();
	}
	void afficher() {
		MutantStack<int>::reverse_iterator it = this->rbegin();
		MutantStack<int>::reverse_iterator ite = this->rend();
		while (it != ite) {
			std::cout << *it << std::endl;
				it++;
		}
	}
};

#endif