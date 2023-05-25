#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const RPN &cpy) {(void) cpy;}

RPN::~RPN() {}

RPN & RPN::operator=(const RPN &cpy) {
	(void) cpy;
	return (*this);
}

int RPN::calculOperand(int nb1, int nb2, char signe) {
    switch (signe) {
        case '+':
            return (nb2 + nb1);
        case '-':
            return (nb2 - nb1);
        case '*':
            return (nb2 * nb1);
        case '/':
            return (nb2 / nb1);
    }
    return (0);
}

std::stack<int> RPN::calcul(char *argv) {
    std::stack<int> stack;
    int i = 0;
    int temp;
    while (argv[i]) {
        if (strchr("0123456789", argv[i]) && argv[i + 1] == ' ')
            stack.push(argv[i] - '0');
        else if (strchr("+-*/", argv[i])
                && (argv[i + 1] == ' ' || argv[i + 1] == 0)&& stack.size() > 1) {
            temp = stack.top();
            stack.pop();
            stack.top() = calculOperand(temp, stack.top(), argv[i]);
        }
        else if (argv[i] != ' ') {
            std::cout << "Error at '" << argv[i] << "' " << "at column: " << i + 1 << std::endl; 
            while (stack.size() != 0)
                stack.pop();
            return (stack);
        }
        i++;
    }

    if (stack.size() > 1) {
        std::cout << "invalid number of operand" << std::endl; 
        while (stack.size() != 0)
            stack.pop();
    }
    return (stack);
}