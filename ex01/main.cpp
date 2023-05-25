#include <iostream>
#include <stack>
#include <deque>
#include <cstring>

#include "RPN.hpp"

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "invalid number parameter" << std::endl;
        return (0);
    }

	RPN rpn;
    std::stack<int, std::deque<int> > stack = rpn.calcul(argv[1]);
    if (!stack.empty())
        std::cout << stack.top() << std::endl;

    return (0);
} 