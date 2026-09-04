//
//  operation.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//
#include <iostream>
int main() {
    /*
     std::cout << "Enter an operator and two operands to get started!: ";
     char op;
     double val1; double val2;
     std::cin >> op >> val1 >> val2;
     switch (op) {
     case '+':
     std::cout << val1 + val2;
     break;
     case '-':
     std::cout << val1 - val2;
     break;
     case '*':
     std::cout << val1 * val2;
     break;
     case '/':
     std::cout << val1 / val2;
     }
     }*/
    std::cout << "Enter an operator and two operands to get started!: ";
    std::string operation;
    double val1; double val2;
    std::cin >> operation >> val1 >> val2;
    if ( operation == "+" || operation == "plus" ) {
        std::cout << val1 + val2;
    }
    if ( operation == "-" || operation == "minus" ) {
        std::cout << val1 - val2;
    }
    if ( operation == "*" || operation == "mul" ) {
        std::cout << val1 * val2;
    }
    if ( operation == "/" || operation == "div" ) {
        std::cout << val1 / val2;
    }
    
}
