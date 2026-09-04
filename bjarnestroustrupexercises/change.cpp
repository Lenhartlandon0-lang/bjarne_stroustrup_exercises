//
//  change.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//

#include <iostream>
int main() {
    int n;
    int a = 0;
    std::string currency;
    while(a <= 5) {
        switch(a) {
            case 0:
                currency = "pennies";
                break;
            case 1:
                currency = "nickels";
                break;
            case 2:
                currency = "dimes";
                break;
            case 3:
                currency = "quarters";
                break;
            case 4:
                currency = "half-dollars";
                break;
            case 5:
                currency = "dollars";
                break;
        }
        std::cout << "Enter the amount of " << currency << " that you have: ";
        std::cin >> n;
        if ( n == 1 && a != 0) {
            currency.erase(currency.end() - 1);
            std::cout << "You have " << n << ' ' << currency << '\n';
        }
        else if (n == 1 && a == 0) {
            currency.clear();
            currency = "penny";
            std::cout << "You have " << n << ' ' << currency << '\n';

        }
        else {
            std::cout << "You have " << n << ' ' << currency << '\n';
        }
        a++;
    }
}
