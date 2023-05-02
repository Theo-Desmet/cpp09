#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

#include "PmergeMe.hpp"

int		stringToInt(std::string str) {
	std::stringstream ss;
	int ret = 0;

	ss << str;
	ss >> ret;
	return (ret);
}


int main(int argc, char **argv) {
	if (argc == 1) {
		std::cout << "Error: invalide parameter: ./PmergeMe [nb] <...> [nb]" << std::endl;
	}

	PmergeMe			merge;
	std::vector<int>	vec;
	// std::deque<int> 	deque;

	for (int i = 1; i < argc; i++)
		vec.push_back(stringToInt(argv[i]));
	merge.mergeInsertSort<std::vector<int> >(vec);
	for (int i = 0; i < argc - 1; i++)
		std::cout << vec[i] << " " << std::endl;
}