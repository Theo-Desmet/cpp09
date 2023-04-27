#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <map>

class BitcoinExchange {
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		
		~BitcoinExchange();
		
		BitcoinExchange &	operator=(const BitcoinExchange &cpy);

		int		initDataBase();
		int		parseInput(std::string str) const;
		void	printExchange(std::string str) const;
		std::map<std::string, float>	getData() const;

	private:
		std::map<std::string, float>	_data;

		float	_stringToFloat(std::string str) const;
		long		_stringToLong(std::string str) const;
		int		_stringToInt(std::string str) const;
		int		_checkIsDigit(std::string str) const;
};

#endif