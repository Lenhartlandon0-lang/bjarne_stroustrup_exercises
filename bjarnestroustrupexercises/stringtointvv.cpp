//
//  stringtointvv.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/16/26.
//
#include <iostream>
int main() {
    std::vector<std::string> nums { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
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
}
