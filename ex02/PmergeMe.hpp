#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <string>
#include <sys/time.h>
#include <sys/types.h>

#define	MIN_SIZE 1

class PmergeMe {
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &cpy);

		~PmergeMe();
		
		PmergeMe & operator=(const PmergeMe &cpy);

		template <typename T>
		void	printSort(T& container, int argc, char **argv) {
			std::cout << "Before: ";
			for (int i = 1; i < argc; i++)
				std::cout << " " << argv[i];
			std::cout << std::endl;
			std::cout << "after:  ";
			for (typename T::const_iterator it = container.begin(); it != container.end(); it++) 
				std::cout << " " << *it;
			std::cout << std::endl;

			std::cout << "Time to process a range of   " << argc - 1
					<< " elements with std::vector :  " << std::fixed
					<< std::setprecision(5) << timeContainer1 << " ms"
					<< std::endl;

			std::cout << "Time to process a range of   " << argc - 1
					<< " elements with std::list :    " << std::fixed
					<< std::setprecision(5) << timeContainer2 << " ms"
					<< std::endl;
		};

		void	mergeInsertSortVector(std::vector<int>& vec);

		void	mergeInsertSortList(std::list<int>& list);

		double	getTime();
		double	deltaTime(long long time);

		double	timeContainer1;
		double	timeContainer2;


};

#endif