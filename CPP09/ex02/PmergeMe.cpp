#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(int ac, char **av) {
	for (int i = 1; i < ac; i++) {
		for (int j = 0; av[i][j]; j++) {
			if (!isdigit(av[i][j])) {
				std::cerr << "Error: Invalid Argument" << std::endl;
				return;
			}
		}
		int nb = std::atoi(av[i]);
		if (nb < 0) {
			std::cerr << "Error: Not a positif number" << std::endl;
			return;
		}
		liste.push_back(nb);
		dek.push_back(nb);
	}
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	(void)other;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void PmergeMe::displayBefore(std::list<int>& container) {
	std::list<int>::iterator it = container.begin();
	std::cout << "Before: ";
	while (it != container.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::displayAfter(std::list<int>& container) {
	std::list<int>::iterator it = container.begin();
	std::cout << "After: ";
	while (it != container.end()) {
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void PmergeMe::AlgoTime() {
	clock_t startL = clock();
	
	sortList(liste);

	clock_t endL = clock();
	double durationL = static_cast<double>(endL - startL) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of : " << liste.size() << " elements with std::list: " << durationL << " us" << std::endl;

	clock_t startD = clock();
	
	// ALGO DEQUE
	//sortDek(dek);

	clock_t endD = clock();
	double durationD = static_cast<double>(endD - startD) / CLOCKS_PER_SEC * 1000000;
	std::cout << "Time to process a range of : " << dek.size() << " elements with std::deque: " << durationD << " us" << std::endl;
}

std::list<int> PmergeMe::sortList(std::list<int>& liste) {
	// Créer une copie pour ne pas modifier l'original
	std::list<int> temp(liste);
	
	if (temp.size() <= 1) {
		return temp;
	} 
	int singleElement = 0;
	bool hasSingle = false;
	std::list<std::pair<int, int> > p = makePairs(temp, singleElement, hasSingle);
	std::list<int>largeElements = extractLargeElements(p);
	std::list<int>sortedLarge = sortListHelper(largeElements);
	insertSmallElements(sortedLarge, p, singleElement, hasSingle);
	
	return sortedLarge;
}