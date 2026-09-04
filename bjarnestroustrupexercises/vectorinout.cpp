//
//  vectorinout.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/23/26.
//
// The purpose of the program: Have the user enter some values,
// Then have them enter a range of values to cout.

#include <iostream>
#include <random>
#include <stdint.h>
#include <stdexcept>
std::vector<int> savevalues ( uint_fast64_t n ) {
    //Take an input as the upper bound.
    //Initialize list for safety...
    std::vector<int> vals{};
    
    //Create a random seed from hardware
    std::random_device rd;
    
    //Initialize Mersenne Twister random engine
    std::mt19937 engine(rd());
    
    //Define the possible range of pseudo-random values.
    std::uniform_int_distribution<int> dist(1, 100);
    
    for ( int i{}; i < n; i++ ) {
        
        //Actually generate the random number
        int val = dist(engine);
        
        //Add it to vals vector
        vals.push_back(val);
    }
    return vals;
}
uint_fast64_t uerror( uint_fast64_t u ) {
    if ( u ) {
        // do nothing
    }
    else {
        throw std::invalid_argument("Please enter a valid positive integer!\n");
    }
    return u;
}
uint64_t verror ( uint64_t v, uint_fast64_t u ) {
    if ( v && v <= u ) {
        // do nothing, again
        // Note that if there's extremely faulty input we default here...
    }
    else {
        throw std::invalid_argument("Please enter a valid positive integer!\nAlso, ensure that the second number you entered is in range of the first value you entered.\n");
    }
    return v;
}
int main() {
    try {
        std::cout << "Enter the upper bound of your list!\n";
        
        // Unsigned to ensure positive value
        uint_fast64_t u{};
        std::cin >> u;
        
        //Handle non-valid entry
        uerror(u);
        
        std::cout << "Good! Now enter the amount of values you'd like to see!\n";
        
        uint64_t v{};
        std::cin >> v;
        
        verror(v, u);
        
        std::vector<int> list = savevalues(u);
        
        for ( int i{}; i < v; ++i ) {
            std::cout << list[i] << '\n';
        }
    }
    
    //handle errors...
    catch ( const std::overflow_error& e ) {
        std::cout << e.what();
    }
    
    catch ( const std::invalid_argument& e ) {
        std::cout << e.what();
    }
    
    catch (...) {
        std::cout << "An unknown exception occured. Please go get fucked.\n";
    }
    
    return 0;   
}
