#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <list>
#include <deque>
#include <ctime>

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

	//std::list<std::pair<int, int> >makePairs(std::list<int>& liste, int& singleElement);
	std::list<std::pair<int, int> > makePairs(std::list<int>& liste, int& singleElement, bool& hasSingle);
	std::list<int> extractLargeElements(std::list<std::pair<int, int> >& pairs);
	std::list<int> sortListHelper(std::list<int>& large);
	void insertSmallElements(std::list<int>& principal, std::list<std::pair<int, int> >& pairs, int singleElement, bool& hasSingle);
	std::list<int>::iterator findPosition(std::list<int>& sorted, int value);
};

#endif