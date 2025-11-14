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
	std::chrono::high_resolution_clock::time_point startL = std::chrono::high_resolution_clock::now();
	
	// ALGO LIST

	std::chrono::high_resolution_clock::time_point endL = std::chrono::high_resolution_clock::now();

	std::chrono::microseconds durationL = std::chrono::duration_cast<std::chrono::microseconds>(endL - startL);

	std::cout << "Time to process a range of : " << liste.size() << "elements with std::list: " << durationL.count() << " us" << std::endl;


	std::chrono::high_resolution_clock::time_point startD = std::chrono::high_resolution_clock::now();
	
	// ALGO DEQUE

	std::chrono::high_resolution_clock::time_point endD = std::chrono::high_resolution_clock::now();

	std::chrono::microseconds durationD = std::chrono::duration_cast<std::chrono::microseconds>(endD - startD);

	std::cout << "Time to process a range of : " << dek.size() << "elements with std::list: " << durationD.count() << " us" << std::endl;
}

std::list<int> PmergeMe::sortList(std::list<int>& liste) {
	std::list<int>sorted;

	
	return sorted;
}

