//
//  integeroddoreven.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//
#include <iostream>
int main () {
    int val1 = 0;
    std::cin >> val1;
    if (val1 % 2) {
        std::cout << "odd\n";
    }
    else {
        std::cout << "even\n";
    }
    
}
