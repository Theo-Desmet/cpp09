#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy) {(void)cpy;}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(const PmergeMe &cpy) {
	(void)cpy;
	return (*this);
}

void	PmergeMe::mergeInsertSortVector(std::vector<int> vec, int left, int right) {
	if (right > left) {
		int	middle = (left + right) / 2;
		mergeInsertSortVector(vec, left, middle);
		mergeInsertSortVector(vec, middle + 1, right);
		mergeVector(vec, left, middle, right);
	}
};

void 	PmergeMe::mergeVector(std::vector<int> vec, int left, int middle, int right) {
    int i = left; 
    int j = middle + 1;
	int	k = left;
	std::vector<int> temp;

    while (i <= middle && j <= right) {
        if (vec[i] < vec[j]) {
            temp[k] = vec[i];
            i++;
        } else {
            temp[k] = vec[j];
            j++;
        }
		k++;
    }
    while (i <= middle) {
        temp[k] = vec[i];
        k++;
        i++;
    }
    while (j <= right) {
        temp[k] = vec[j];
        k++;
        j++;
    }
    for (i = left; i < k; i++)  {
        vec[i] = temp[i];
    }
}

