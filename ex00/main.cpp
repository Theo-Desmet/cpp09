#include <iostream>
#include <string>

#include "BitcoinExchange.hpp"

int	checkIsTxt(std::string str) {
	size_t ret = str.find(".txt");
	if (ret == std::string::npos || ret == 0 || ret != str.size() - 4
			|| (ret == 1 && str.size() > 4 && str[0] == '.'))
		return (0);
	return (1);
}

void	readInputExchange(BitcoinExchange btc, std::string str) {
	std::ifstream input(str.c_str());
	if (!input.is_open())
		return ;

	std::string		read;
	std::getline(input, read);
	if (str.find("date | value"))
		;
	while (std::getline(input, read)) {
		if (btc.parseInput(read) != -1)
			btc.printExchange(read);
	}
}

int main(int argc, char **argv) {
	if (argc != 2 || !checkIsTxt(argv[1])) {
		std::cerr << "Error: format command: ./btc [input.txt]" << std::endl;
		return (1);
	}

	BitcoinExchange btc;
	if (!btc.initDataBase()) {
		std::cerr << "Error: dataBase not found" << std::endl;
		return (1);
	}
	readInputExchange(btc, argv[1]);

	return (0);
}