//
//  Uncaught.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/19/26.
//

#include <iostream>
void error(std::string s) {
    throw std::runtime_error{s};
}
int main() {
    error("ok");
}
