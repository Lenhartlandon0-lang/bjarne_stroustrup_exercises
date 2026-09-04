//  I swear I've done this before...
//  simplecalculator.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//

#include <iostream>
/*std::vector<std::string> nums { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
std::string input;
while ( std::cin >> input ) {
    if ( input.size() == 1 ) {
        for ( char x : input ) {
            std::cout << nums[int(x) - 48] << std::endl;
        }
    }
    else {
        for ( int i{}; i < std::size(nums); i++) {
            if ( nums[i] == input ) {
                std::cout << i << std::endl;
            }
        }
    }
}
}*/
int ifstring ( std::string in1 ) {
    int val = -1;
    std::vector<std::string> nums { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    for ( int i{}; i < std::size(nums); i++) {
        if ( nums[i] == in1 ) {
            val = i;
        }
        else if ( nums[i] != in1 ) {}
        else {
            std::cout << "Please enter a valid string!\n";
        }
    }
    return val;
}
void calculator ( int num1, int num2, char oper ) {
    std::cout << num1 << oper << num2 << '\n';
    switch ( oper ) {
        case '+':
            std::cout << "The sum of " << num1 << " and " << num2 <<  " is " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "The difference of " << num1 << " and " << num2 <<  " is " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "The product of " << num1 << " and " << num2 <<  " is " << num1 * num2 << std::endl;
            break;
        case '/':
            std::cout << "The difference of " << num1 << " and " << num2 <<  " is " << num1 / num2 << std::endl;
            break;
    }
}
int main() {
    std::cout << "Enter two numbers followed by the operator you'd like to use on them!\n";
    std::string val1; std::string val2; char op;
    while (std::cin >> val1 >> val2 >> op) {
        if ( val1.size() > 1 && val2.size() > 1) {
            int num1 = ifstring ( val1 );
            int num2 = ifstring ( val2 );
            calculator(num1, num2, op);
        }
        else if ( val1.size() > 1 && val2.size() == 1 ) {
            int num1 = ifstring ( val1 );
            int num2 = int(char(val2[0])) - 48;
            calculator(num1, num2, op);
        }
        else if ( val1.size() == 1 && val2.size() > 1 ) {
            int num1 = int(char(val1[0])) - 48;
            int num2 = ifstring ( val2 );
            calculator(num1, num2, op);
        }
        else {
            int num1 = int(char(val1[0])) - 48;
            int num2 = int(char(val2[0])) - 48;
            calculator(num1, num2, op);
        }
    }
    return 0;
}
//Shit code, visit later
