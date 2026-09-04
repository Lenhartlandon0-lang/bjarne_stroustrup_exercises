//
//  squarefunction.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//
#include <iostream>
int square ( int num ) {
    int res = 0;
    for ( int i = 0; i < num; i++ ) {
        res = res + num;
    }
    return res;
}
int main() {
    int dig{};
    std::cin >> dig;
    std::cout << square(dig) << std::endl;
}
