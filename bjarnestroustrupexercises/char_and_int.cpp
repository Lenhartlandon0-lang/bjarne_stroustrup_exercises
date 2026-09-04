//
//  char_and_int.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//

#include <iostream>
int main() {
    for ( int i = 0; i < 74; i++ ) {
        std::cout << char('0'+i) << '\t' << 48 + i << std::endl;
    }
    return 0;
}
/*
 int i{};
 while ( int i < 26 ) {
    std::cout << (char('a'+i) << '\t' << 97 + i << std::endl;
    i++;
 */
 
