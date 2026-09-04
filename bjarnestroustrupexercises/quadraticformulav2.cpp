//
//  quadraticformulav2.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/23/26.
//
#include <iostream>
#include <cmath>
std::pair<double, double> quadformula(double a, double b, double c) {
    double stupidassnumber{};
    stupidassnumber = (b * b) - (4 * a * c);
    if ( stupidassnumber <= 0 ) {
        throw std::invalid_argument( "discriminant can not be less than 0!\n" );
    }
    double root1 = (-b - std::sqrt(stupidassnumber)) / (2 * a);
    double root2 = (-b + std::sqrt(stupidassnumber)) / (2 * a);
    return std::pair<double, double>{root1, root2};
}
int main() {
    double a, b, c;
    while ( std::cin >> a >> b >> c ) {
        try {
            auto roots = quadformula(a, b, c);
            std::cout << roots.first << '\t' << roots.second << '\n';
        }
        catch (std::invalid_argument& e) {
            std::cerr << e.what();
            std::cerr << "Please enter valid arguments for a, b, and c.\n";
        }
    }
}

