#include "PmergeMe.hpp"

int main (int ac, char **av) {
	if (ac < 2) {
		std::cout << "Error: A few numbers" << std::endl;
		return 0;
	}
	PmergeMe merge(ac, av);
	merge.displayBefore(merge.getlist());
	merge.displayAfter(merge.getlist());
}