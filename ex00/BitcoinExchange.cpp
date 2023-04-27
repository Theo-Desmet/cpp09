#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy) {
	this->_data = cpy.getData();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &cpy) {
	this->_data = cpy.getData();
	return (*this);
}

int	BitcoinExchange::initDataBase() {
	std::ifstream	file;
	file.open("./data.csv");
	if (!file.is_open())
		return (0);

	std::string		read;
	std::string		value;
	while (std::getline(file, read)) {
		value = read.substr(read.find(",") + 1);
		read.erase(4, 1).erase(6,1).erase(8);
		_data.insert(std::make_pair(read, _stringToFloat(value)));
		// std::cout << read << " " << value << std::endl;
	}
	file.close();

	return (1);
}

std::map<std::string, float>	BitcoinExchange::getData() const {
	return (_data);
};

void	BitcoinExchange::printExchange(std::string str) const {
    std::map<std::string, float>::const_iterator ite = _data.end();
	float nbCoin = _stringToFloat(str.substr(str.find(" | ")).erase(0,3));

	str.erase(4, 1).erase(6,1).erase(8);
	ite = _data.lower_bound(str);
	if (ite->first != str)
		ite--;
    std::cout << str.insert(4,"-").insert(7,"-") << " => " << nbCoin << " = " 
			<< std::fixed << std::setprecision(2) 
			<< nbCoin * ite->second << "\n";
}

int	BitcoinExchange::parseInput(std::string str) const {
	std::string cpystr = str; 
	if (str.find(" | ") == std::string::npos || str.size() < 14) {
		std::cerr << "Error: bad input => " << cpystr << std::endl;
		return (-1);
	}

	std::string nbCoin = str.substr(str.find(" | ")).erase(0,3);
	str.erase(str.find(" | "));
	if (str[4] != '-' || str[7] != '-') {
		std::cerr << "Error: bad input => " << cpystr << std::endl;
		return (-1);
	}
	str.erase(4,1).erase(6,1);
	
	if (!_checkIsDigit(str)) {
		std::cerr << "Error: bad input => " << cpystr << std::endl;
		return (-1);
	}
	int year = _stringToInt(str.substr(0, 4));
	int month = _stringToInt(str.substr(4, 2));
	int day = _stringToInt(str.substr(6, 2));
	int	month_list[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (year < 2009 || year > 2022 || month < 1 || month > 12
			|| day < 1 || day > month_list[month - 1]) {
		std::cerr << "Error: bad input => " << cpystr << std::endl;
		return (-1);
	}

	if (!_checkIsDigit(str)) {
			std::cerr << "Error: bad input. => " << cpystr << std::endl;
		return (-1);
	}
	if (nbCoin[0] == '-') {
		std::cerr << "Error: not a positive number. => " << cpystr << std::endl;
		return (-1);
	}
	if (_stringToLong(nbCoin) > 1000) {
		std::cerr << "Error: too large a number. => " << cpystr << std::endl;
		return (-1);
	}
	return (1);
}

float	BitcoinExchange::_stringToFloat(std::string str) const {
	std::stringstream ss;
	float ret = 0.0;

	ss << str;
	ss >> ret;
	return (ret);
}

int		BitcoinExchange::_checkIsDigit(std::string str) const {
	for (std::string::const_iterator it = str.begin(); it < str.end(); it++) {
		if (!std::isdigit(*it))
			return (0);
	}
    return (1);
}

int		BitcoinExchange::_stringToInt(std::string str) const {
	std::stringstream ss;
	int ret = 0;

	ss << str;
	ss >> ret;
	return (ret);
}

long	BitcoinExchange::_stringToLong(std::string str) const {
	std::stringstream ss;
	long ret = 0;

	ss << str;
	ss >> ret;
	return (ret);
}