#include <iostream>
int main() {
    int in = 8;

    for ( int i = in - 1; i > 0; i-- )
    {
        in *= i;
        std::cout << in << '\n';
    }
    
}
/*
 left = 8
 8 *= 8
 64 *= 64
 4096*=4096
 */
