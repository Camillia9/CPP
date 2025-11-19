#include "PmergeMe.hpp"

std::list<int>& PmergeMe::getlist() {
	return liste;
}

std::deque<int>& PmergeMe::getdeque() {
	return dek;
}

std::list<std::pair<int, int> > PmergeMe::makePairs(std::list<int>& liste, int& singleElement, bool& hasSingle) {
	std::list<std::pair<int, int> >paire;
	if (liste.size() % 2 == 1) { // 0 paire, 1 impaire
		singleElement = liste.back();
		liste.pop_back();
		hasSingle = true;
	}
	std::list<int>::iterator it = liste.begin();
	while (it != liste.end()) {
		std::pair<int, int> p = std::make_pair(*it, *(++it));
		it++;
		if (p.first > p.second) {
			std::swap(p.first, p.second);
		}
		paire.push_back(p);
	}
	return paire;
}

std::list<int> PmergeMe::extractLargeElements(std::list<std::pair<int, int> >& pairs) {
	std::list<int>largeElements;
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
	while (it != pairs.end()) {
		largeElements.push_back(it->second);
		it++;
	}
	return largeElements;
}

void PmergeMe::insertSmallElements(std::list<int>& principal, std::list<std::pair<int, int> >& pairs, int singleElement, bool& hasSingle) {
	std::list<int>smallElements;
	std::list<std::pair<int, int> >::iterator it = pairs.begin();
	while(it != pairs.end()) {
		smallElements.push_back(it->first);
		it++;
	}
	if (hasSingle)
		smallElements.push_back(singleElement);

	std::list<int>::iterator it2 = smallElements.begin();
	while (it2 != smallElements.end()) {
		std::list<int>::iterator pos = findPosition(principal, *it2);
		principal.insert(pos, *it2);
		it2++;
	}
}

std::list<int> PmergeMe::sortListHelper(std::list<int>& large) {
	if (large.size() <= 1)
		return large;
	int newSingleElement = 0;
	bool newHasSingle = false;
	std::list<std::pair<int, int> > paires = makePairs(large, newSingleElement, newHasSingle);
	std::list<int> largeElements = extractLargeElements(paires);
	std::list<int> sortedLarge = sortListHelper(largeElements);
	insertSmallElements(sortedLarge, paires, newSingleElement, newHasSingle);
	if (newHasSingle)
		sortedLarge.push_back(newSingleElement);
	return sortedLarge;
}

std::list<int>::iterator PmergeMe::findPosition(std::list<int>& sorted, int value) {

	std::list<int>::iterator start = sorted.begin();
	std::list<int>::iterator end = sorted.end();

	while (start != end) {
		int distance = std::distance(start, end); //distance de la list
		std::list<int>::iterator mid = start; // mid est un it sur le debut de la list
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
