//
//  ctok.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/20/26.
//

#include <iostream>
#include "PPPheaders.h"
double ctok( double c ) {
    double k = c + 273.15;
    expect([&]{ return k > 0; }, "K cannot be below 0!\n"); //if this is false, the world ends
    return k;
}
double ktoc ( double k ) {
    double c = k - 273.15;
    expect( [&] { return c > -273.15; }, "Please don't enter Kelvin values below absolute 0!\n"); // same thing here, really...
    return c;
}
double ctof ( double c ) {
    double f = ((9*c)/5) + 32;
    expect ( [&] {return f > -459.67;}, "Please don't enter Celsius values below absolute 0!\n" );
    return f;
    
}
double ftoc ( double f ) {
    double c = (5*f)/9 - 32;
    expect( [&] { return c > -273.15; }, "Please don't enter Fahrenheit values below absolute 0!\n" );
    return c;
}
double ktof ( double k ) {
    double f = (1.8 * ( k - 273.15 )) + 32;
    expect ( [&] {return f > -459.67;}, "Please don't enter Celsius values below absolute 0!\n" );
    return f;
    
}
double ftok ( double f ) {
    double k = (f-32)/1.8 + 273.15;
    expect([&]{ return k > 0; }, "K cannot be below 0!\n"); //if this is false, the world ends
    return k;
}
int main() {
    std::cout << "To get started, choose a base unit! 'f' for Fahrenheit, 'c' for Celsius, 'k' for Kelvin!";
    char in{};
    while ( std::cin >> in ) {
        std::cout << "Next, enter the value you'd like to convert to!\n";
        switch(in) {
            case 'c': {
                std::cout << "You entered c for Celsius! Now, enter the value you need converted.\n";
                double c;
                std::cin >> c;
                std::cout << '\n' << "That is " << ctok(c) << " Kelvin\n";
                std::cout << "Or, " << ctof(c) << " Fahrenheit\n";
                break; }
            case 'k': {
                std::cout << "You entered k for Kelvin! Now, enter the value you need converted.\n";
                double k;
                std::cin >> k;
                std::cout << '\n' << "That is " << ktoc(k) << " Celsius\n";
                std::cout << "Or, " << ktof(k) << " Fahrenheit\n";
                break; }
            case 'f': {
                double f;
                std::cin >> f;
                std::cout << '\n' << "That is " << ftok(f) << "Kelvin\n";
                std::cout << '\n' << "Or, " << ftoc(f) << "Celsus\n";
                break; }
            default: {
                std::cout << "Please enter a valid character!\n";
                break; }
        }
    }
    return 0;
}
