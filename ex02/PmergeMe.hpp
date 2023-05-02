#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>

#define	MIN_SIZE 1

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		~PmergeMe();
		
		PmergeMe & operator=(const PmergeMe &cpy);

		template <typename T>
		void	printSort(T& container, char **argv) {
			
		};

		template <typename T>
		void	mergeInsertSort(T& container) {
			typename T::iterator middle = container.begin() + (container.size()) / 2;
			T left(container.begin(), middle);
			T right(middle, container.end());
			if (container.size() > 1) {
				mergeInsertSort(left);
				mergeInsertSort(right);
			}
			typename T::iterator i = left.begin();
			typename T::iterator j = right.begin();
			typename T::iterator k = container.begin();

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

};

#endif