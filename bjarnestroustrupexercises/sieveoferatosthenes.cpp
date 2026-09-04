//
//  sieveoferatosthenes.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/17/26.
//
#include <iostream>
double pow ( int base, double exp ) {
    int res{};
    if ( exp > 1 ) {
        for ( int i{}; i < exp; i++ ) {
            res *= base;
        }
    }
    else if ( exp < 1 ) {
        // sqrt function
        double tolerance = 0.1;
        double guess = base / 2;
        while ( 1 == 1 ) {
            double new_guess = (guess + base / guess ) / 2;
            if ( abs(new_guess - guess) < tolerance ) {
                return new_guess;
            }
            guess = new_guess;
        }
    }
    return res;
}
std::vector<bool> generate_list ( int upperbound ) {
    std::vector<bool> sieve{};
    for( int i{}; i <= upperbound + 1; i++ ) {
        sieve.push_back(true);
    }
    return sieve;
}
std::vector<bool> sieve ( std::vector<bool> list, int upperbound ) {
    for ( int i = 2; i < pow( upperbound, 0.5 ) + 1; i++ ) {
        if ( list[i] == true ) {
            for ( int ii = i * i; ii < upperbound + 1; ii += i ) {
                list[ii] = false;
            }
        }
    }
    return list;
}
std::vector<int> primes ( std::vector<bool> sievedlist ) {
    std::vector<int> primelist{};
    for ( int i{}; i < sievedlist.size(); i++ ) {
        if ( sievedlist[i] == true ) {
            primelist.push_back(i);
        }
    }
    return primelist;
}
int main() {
    int upperbound;
    std::cout << "Enter your upper bound!\n";
    std::cin >> upperbound;
    std::cout << pow ( upperbound, 0.5 ) << '\n';
    std::vector<bool> table = sieve(generate_list(upperbound), upperbound);
    std::vector<int> primetable = primes(table);
    for ( auto x : primetable ) {
        std::cout << x << " is prime " << '\n';
    }
}
