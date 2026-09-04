//
//  bullsandcowss.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/24/26.
//
/*
 Implement a little guessing game called "bulls and cows." The porgram has a vector of four different integers in the range 0 to 9 and it is the users task to discover those numbers by repeated guesses. Say the number to be guessed is 1234 and the suer guesses 1359, the response should be "1 bull and 1 cow" becasue the user got one digit right and in the right position and one digit right but in the wrong position (cow.) The geussing continues until the user gets four bulls, that is, has the four digits correct and in the correct order.
 */
#include <iostream>
#include <random>
#include <vector>

std::vector<int> generate_list ( ) {
    
    //initialize vector
    std::vector<int> list{};
    
    // create engine, restrict it and use to fill list
    std::random_device rd;
    
    std::mt19937 engine(rd());
    
    std::uniform_int_distribution<int> dist(0,10);
    
    for ( int i{}; i < 4; ++i ) {
        list.push_back(dist(engine));
    }
    return list;
}
std::pair<int, int> cowsandbulls ( std::vector<int> list, int in, int internal_counter ) {
    //note: we need to track index misalignment.
    int cow{};
    int bulls{};
    for ( int i{}; i < list.size(); ++i ) {
        if ( list[i] == in && i != internal_counter ) {
            cow++;
        }
        else if ( list[i] == in && i == internal_counter ) {
            bulls++;
        }
    }
    return std::pair<int, int> {cow, bulls};
}
int main() {
    
    std::vector<int> l = generate_list();
    for ( auto x : l ) {
        std::cout << x << '\n';
    }
    //a = [0] and the users guess, and our variables to track cbs
    int a{}, b{}, c{};
    int internal_counter{};
    int total_bulls = 0; // counter for number of bulls so far...
    while ( std::cin >> a && total_bulls < 4 ) {
        auto cbs = cowsandbulls(l, a, internal_counter);
        c = cbs.first;
        b = cbs.second;
        total_bulls += b;
        internal_counter++;
        std::cout << c << " cows and " << total_bulls << " bulls\n";
    }
    
}

