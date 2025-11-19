#include "PmergeMe.hpp"

std::deque<int>& PmergeMe::getdeque() {
	return dek;
}

std::deque<std::pair<int, int> > PmergeMe::makePairs(std::deque<int>& dek, int& singleElement, bool& hasSingle) {
	std::deque<std::pair<int, int> >paire;
	if (dek.size() % 2 == 1) { // 0 paire, 1 impaire
		singleElement = dek.back();
		dek.pop_back();
		hasSingle = true;
	}
	std::deque<int>::iterator it = dek.begin();
	while (it != dek.end()) {
		std::pair<int, int> p = std::make_pair(*it, *(++it));
		it++;
		if (p.first > p.second) {
			std::swap(p.first, p.second);
		}
		paire.push_back(p);
	}
	return paire;
}

std::deque<int> PmergeMe::extractLargeElements(std::deque<std::pair<int, int> >& pairs) {
	std::deque<int>largeElements;
	std::deque<std::pair<int, int> >::iterator it = pairs.begin();
	while (it != pairs.end()) {
		largeElements.push_back(it->second);
		it++;
	}
	return largeElements;
}

void PmergeMe::insertSmallElements(std::deque<int>& principal, std::deque<std::pair<int, int> >& pairs, int singleElement, bool& hasSingle) {
	std::deque<int>smallElements;
	std::deque<std::pair<int, int> >::iterator it = pairs.begin();
	while(it != pairs.end()) {
		smallElements.push_back(it->first);
		it++;
	}
	if (hasSingle)
		smallElements.push_back(singleElement);

	std::deque<int>::iterator it2 = smallElements.begin();
	while (it2 != smallElements.end()) {
		std::deque<int>::iterator pos = findPosition(principal, *it2);
		principal.insert(pos, *it2);
		it2++;
	}
}

std::deque<int> PmergeMe::sortListHelper(std::deque<int>& large) {
	if (large.size() <= 1)
		return large;
	int newSingleElement = 0;
	bool newHasSingle = false;
	std::deque<std::pair<int, int> > paires = makePairs(large, newSingleElement, newHasSingle);
	std::deque<int> largeElements = extractLargeElements(paires);
	std::deque<int> sortedLarge = sortListHelper(largeElements);
	insertSmallElements(sortedLarge, paires, newSingleElement, newHasSingle);
	if (newHasSingle)
		sortedLarge.push_back(newSingleElement);
	return sortedLarge;
}

std::deque<int>::iterator PmergeMe::findPosition(std::deque<int>& sorted, int value) {

	std::deque<int>::iterator start = sorted.begin();
	std::deque<int>::iterator end = sorted.end();

	while (start != end) {
		int distance = std::distance(start, end); //distance de la list
		std::deque<int>::iterator mid = start; // mid est un it sur le debut de la list
		std::advance(mid, distance / 2); //On avance mid au milieu de la list
		if (*mid <= value) {
			start = mid;
			start++;
		} else {
			end = mid;
		}
	}
	return start;
}
