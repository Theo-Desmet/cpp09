#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy) {(void)cpy;}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(const PmergeMe &cpy) {
	(void)cpy;
	return (*this);
}

