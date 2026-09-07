#include <iostream>
uint fus(uint n) {
    // fus stand for fast unsigned integer square root
    // it is also part of the dragonborn chant in skyrim
    uint res = 0;
    uint bit = 1U << 30; // 2^30
    
    // since bit starts at 2^30, rightshift it until its less than n
    while ( bit > n ) {
        bit >>= 2;
    }
    
    while ( bit != 0 )
    {
        if ( n >= res + bit ) {
            // if n is greater than or equal to res + bit,
            // subtract n by their sum ()
            // and rightshift res 1 ()
            n -= res + bit;
            res = ( res >> 1 ) + bit;
        }
        
        else {
            // if n is not greater, we only need to rightshift once to get an approximate result
            res >>= 1;
        }
        // always rightshift bit
        bit >>= 2;
    }
    return res;
}
int findindex(int x, int y) {
    return x * fus(100) + y;
}
int main() {
    int s = 100;
    std::vector<char> a(s);
    for ( int i{}; i < s; i++ ) {
        a[i] = 'x';
    }
    int f = findindex(9, 9);
    std::cout << f << '\n';
    a[f] = 'c';
    for ( int i{}; i < s; i++ ) {
        if ( i % fus(s) == 0 ) {
            std::cout << '\n';        }
        std::cout << a[i];
    }
}
