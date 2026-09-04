//
//  main.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//

#include <iostream>

int main() {
    double miles = 0.0;
    double rate = 1.609;
    std::cout << "Enter the amount of miles to be converted: \n";
    std::cin >> miles;
    double km = miles * rate;
    std::cout << miles << " is " << km << " Kilometers. \n";
    
    return EXIT_SUCCESS;
}
