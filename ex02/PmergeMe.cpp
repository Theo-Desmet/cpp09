#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &cpy) {(void)cpy;}

PmergeMe::~PmergeMe() {}

PmergeMe & PmergeMe::operator=(const PmergeMe &cpy) {
	(void)cpy;
	return (*this);
}

double	PmergeMe::getTime(void) {
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec *.001));
}

double	PmergeMe::deltaTime(long long time) {
	return (getTime() - time);
}

void	PmergeMe::mergeInsertSortVector(std::vector<int>& vec) {
	std::vector<int>::iterator middle = vec.begin()
			+ (vec.size()) / 2;
	std::vector<int> left(vec.begin(), middle);
	std::vector<int> right(middle, vec.end());
	if (vec.size() > 1) {
		mergeInsertSortVector(left);
		mergeInsertSortVector(right);
	}
	std::vector<int>::iterator i = left.begin();
	std::vector<int>::iterator j = right.begin();
	std::vector<int>::iterator k = vec.begin();
	while (i != left.end() && j != right.end()) {
		if (*i < *j) {
			*k = *i;
			i++;
		} else {
			*k = *j;
			j++;
		}
		k++;
	}
	while (i != left.end()) {
		*k = *i;
		k++;
		i++;
	}
	while (j != right.end()) {
		*k = *j;
		k++;
		j++;
	}
};

void	PmergeMe::mergeInsertSortList(std::list<int>& list) {
	std::list<int>::iterator middle = list.begin();
	for (size_t i = 0; i < list.size() / 2; i++)
		middle++;
	std::list<int> left(list.begin(), middle);
	std::list<int> right(middle, list.end());
	if (list.size() > 1) {
		mergeInsertSortList(left);
		mergeInsertSortList(right);
	}
	std::list<int>::iterator i = left.begin();
	std::list<int>::iterator j = right.begin();
	std::list<int>::iterator k = list.begin();
	while (i != left.end() && j != right.end()) {
		if (*i < *j) {
			*k = *i;
			i++;
		} else {
			*k = *j;
			j++;
		}
		k++;
	}
	while (i != left.end()) {
		*k = *i;
		k++;
		i++;
	}
	while (j != right.end()) {
		*k = *j;
		k++;
		j++;
	}
};