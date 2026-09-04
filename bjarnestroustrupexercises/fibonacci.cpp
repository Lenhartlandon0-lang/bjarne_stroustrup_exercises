//
//  fibonacci.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/20/26.
//

#include <iostream>
int main() {
    int c;
    std::cin >> c;
    int f = 1;
    int s = 1;
    int t = f + s;
    std::cout << f << '\n' << s << '\n';
    for ( int i{}; i <= c; ++i ) {
        f = s;
        s = t;
        t = f + s;
        std::cout << t << '\n';
    }
}
