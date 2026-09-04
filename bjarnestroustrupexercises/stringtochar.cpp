//
//  stringtochar.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//

#include <iostream>
int main() {
    std::string input;
    std::cin >> input;
    for ( char x : input ) {
        std::cout << x << '\t' << int(x) << std::endl;
    }
    return 0;
}
