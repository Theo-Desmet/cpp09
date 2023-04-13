#include <iostream>
#include <stack>
#include <cstring>

int RPNCalcul(int nb1, int nb2, char signe) {
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

std::stack<int> RPN(char *argv) {
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
            stack.top() = RPNCalcul(temp, stack.top(), argv[i]);
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
        std::cout << "invalide number of operand" << std::endl; 
        while (stack.size() != 0)
            stack.pop();
    }
    return (stack);
}

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "invalide number parameter" << std::endl;
        return (0);
    }
    std::stack<int> stack = RPN(argv[1]);
    if (!stack.empty())
        std::cout << stack.top() << std::endl;

    return (0);
} 