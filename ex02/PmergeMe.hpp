#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>

#define	MIN_SIZE 1

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		~PmergeMe();
		
		PmergeMe & operator=(const PmergeMe &cpy);

		void	mergeInsertSortVector(std::vector<int> vec, int left, int right);
		void	mergeVector(std::vector<int> vec, int left, int middle, int right);

};

#endif