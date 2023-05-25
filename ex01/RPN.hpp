#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <deque>
#include <cstring>

class RPN {
	public:
		RPN();
		RPN(const RPN &cpy);
		
		~RPN();
		
		RPN &	operator=(const RPN &cpy);

		std::stack<int> calcul(char *argv);
		int 			calculOperand(int nb1, int nb2, char signe);

};

#endif