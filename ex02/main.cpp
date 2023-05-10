#include <iostream>
#include <sstream>
#include <vector>

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
		return (1);
	}

	PmergeMe			merge;
	std::vector<int>	vec;
	for (int i = 1; i < argc; i++)
		vec.push_back(stringToInt(argv[i]));
	merge.timeContainer1 = merge.getTime();
	merge.mergeInsertSortVector(vec);
	merge.timeContainer1 = merge.deltaTime(merge.timeContainer1);

	std::list<int>	list;
	for (int i = 1; i < argc; i++)
		list.push_back(stringToInt(argv[i]));
	merge.timeContainer2 = merge.getTime();
	merge.mergeInsertSortList(list);
	merge.timeContainer2 = merge.deltaTime(merge.timeContainer2);

	merge.printSort(vec, argc, argv);
}