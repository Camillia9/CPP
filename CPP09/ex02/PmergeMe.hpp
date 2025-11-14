#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <deque>
#include <chrono>

class PmergeMe {
private:
	std::list<int>liste;
	std::deque<int>dek;

public:
	PmergeMe();
	PmergeMe(int ac, char **av);
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
	~PmergeMe();

	std::list<int>& getlist();
	std::deque<int>& getdeque();
	void displayBefore(std::list<int>& container);
	void displayAfter(std::list<int>& container);
	void AlgoTime();
	std::list<int>sortList(std::list<int>& liste);
	std::deque<int>sortDek(std::deque<int>& dek);
};

#endif