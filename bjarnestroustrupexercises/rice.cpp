//
//  rice.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/16/26.
//
int pow ( int x, int y ) {
    int res = 1;
    for ( int i{}; i < y; i++ ) {
        res *= x;
    }
    return res;
}
int findsquares ( int input ) {
    int i = 1;
    while ( pow(2, i) < input ) {
        //All we have to do is find the power of an iterator that gets closed to input.
        i++;
    }
    return i;
}
#include <iostream>
int main() {
    int x;
    std::cin >> x;
    std::cout << findsquares(x) << std::endl;
    return 0;
}
