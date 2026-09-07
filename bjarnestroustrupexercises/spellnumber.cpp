//
//  spellnumber.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//
#include <iostream>
int main() {
    std::cout << "Enter a number as a string: ";
    std::string input;
    std::cin >> input;
    if ( input == "zero" ) {
        std::cout << '0';
        return 0;
    }
    if ( input == "one" ) {
        std::cout << '1';
        return 0;
    }
    if ( input == "two" ) {
        std::cout << '2';
        return 0;
    }
    if ( input == "three" ) {
        std::cout << '3';
        return 0;
    }
    if ( input == "four" ) {
        std::cout << '4';
        return 0;
    }
    else {
        std::cout << "I am too stupid!";
        return 9;
    }
}

