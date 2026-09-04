//
//  binarysearch.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//
#include <iostream>
int max_search ( int upper_bound, int lower_bound ) {
    int dist = upper_bound - lower_bound;
    int i = 0;
    int n = 1;
    while ( i < dist ) {
        i = std::pow(2, n);
        n++;
    }
    return n - 1;
}
int main() {
    std::cout << "Hello, and welcome to my numbers guessing game! Please, think of a number between 0-100." << std::endl;
    std::cout << "Type 'y' for yes, 'n' for no." << std::endl;
    int upper_bound = 100;
    int lower_bound = 0;
    int mid = upper_bound / 2;
    int maxtree = max_search(upper_bound, lower_bound);
    for ( int i = 0; i <= maxtree; ++i ) {
        char input;
        std::cout << "Is your value greater than " << mid << "?" <<std::endl;
        std::cin >> input;
        switch( input ) {
            case 'y':
                std::cout << "Greater than or equal to?\n";
                std::cout << "Type 'g' for greater, or 'e' for equal.\n";
                char response;
                std::cin >> response;
                if ( i == maxtree ) {
                    mid = upper_bound;
                    response = 'e';
                }
                switch ( response ) {
                    case 'e':
                        std::cout << "Your number was: " << mid << std::endl;
                        return 0;
                        break;
                    case 'g':
                        mid = (mid + (upper_bound - mid) / 2);
                        break;
                    default:
                        i = i -1;
                        break;}
                break;
            case 'n':
                std::cout << "Less than or equal to?\n";
                std::cout << "Type 'l' for less, or 'e' for equal.\n";
                char response2;
                std::cin >> response2;
                if ( i == maxtree ) {
                    mid = lower_bound;
                    response = 'e';
                }
                switch ( response2 ) {
                    case 'e':
                        std::cout << "Your number was: " << mid << std::endl;
                        return 0;
                        break;
                    case 'l':
                        mid = (mid + (upper_bound - mid) / 2);
                        break;
                    default:
                        i = i -1;
                        break;}
            break;}
        }
    }
