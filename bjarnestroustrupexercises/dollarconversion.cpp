//
//  dollarconversion.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//
#include <iostream>
int main() {
    char currency{};
    float amount{};
    std::cout << "Please enter a dollar amount followed by a currency\n";
    std::cout << "The allowed currencies are Yen (Y), Kroner (K), Franc (F), and Pound (P).\n";
    std::cin >> amount >> currency;
    switch (currency) {
        case 'Y':
            std::cout << "The amount you entered in Yen is: " << amount * 0.0063 << currency << std::endl;
            break;
        case 'K':
            std::cout << "The amount you entered in Kroner is: " << amount * 0.1100 << currency << std::endl;
            break;
        case 'P':
            std::cout << "The amount you entered in Pounds is: " << amount * 1.3500 << currency << std::endl;
            break;
        case 'F':
            std::cout << "The amount you entered in Francs is: " << amount * 1.2300 << currency << std::endl;
            break;
    }
    return 0;
}
