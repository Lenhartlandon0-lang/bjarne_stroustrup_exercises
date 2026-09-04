//
//  bullsandchars.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 9/2/26.
//
#include <iostream>
#include <random>
#include <vector>
char make_random_char() {
    
    // make random device for use w/ engine
    std::random_device rd;
    
    // make engine
    std::mt19937 engine(rd());
    
    // ints in the range of printable ascii chars
    std::uniform_int_distribution<int> dist(32, 126);
    
    // (hopefully) static_cast a random int in that range to a char
    char randomc = static_cast<char>(dist(engine));
    
    // return the random char
    return randomc;
    
}

std::vector<char> tokenize_input( std::string input ) {
    
    //lossy conversion because input size shouldn't be that big anyway
    short len = input.size();
    
    //declare char vector for comparison
    std::vector<char> userguess{};
    
    //Check for valid length (we could probably change this later)
    if ( len <= 0 || len > 4 ) {
        throw std::invalid_argument("Please only enter up to 4 chars at a time.");
    }
    
    for ( int i{}; i < len; i++ ) {
        
        char c = input[i]; // index-by-index conversion to char
        userguess.push_back(c); // push char into user guess
        
    }
    return userguess;
}


int main() {
    
    std::vector<char> guessthis{}; // vector where random chars will be stored
    
    for ( int i{}; i < 4; i++ ) {
        
        char a = make_random_char(); // for readability, declare char before insertion
        
        guessthis.push_back(a);
        
    }
    
    std::cout << "Enter a stream of four characters, and we'll tell you what you got right.";
    
    std::string guess{};
    
    std::cin >> guess;
    
    
}
