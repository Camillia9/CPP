#include "PmergeMe.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error: A few numbers" << std::endl;
		return 0;
	}
	PmergeMe merge(ac, av);
	if (!merge.getIsValid())
		return 1;
	merge.displayBefore(merge.getlist());
	merge.AlgoTime();
	std::list<int>sortedList = merge.sortList(merge.getlist());
	merge.displayAfter(sortedList);
	return 0;
}