//
//  quadraticformula.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/17/26.
//
//  todo: make this work idiot
#include <iostream>
double pow ( double base, double exp ) {
    double result = 1;
    for ( int i{}; i < exp; i++ ) {
        result *= base;
    }
    std::cout << result << '\n';
    return result;
}
double sqrt ( double x ) {
    double guess = x / 2.0;
    double tolerance = 0.00000000001;
    while ( 1 == 1 ) {
        double new_guess = ( guess + x / guess ) / 2;
        if ( abs ( new_guess - guess ) < tolerance ) {
            return new_guess;
        }
        guess = new_guess;
    }
}
std::pair<double, double> quadraticformula( double a, double b, double c ) {
    // x = (-b(+-)sqrt(b^2-4ac))/2a
    std::pair<double, double> ans{};
    double discriminant = ( pow(b, 2) ) - ( 4 * a * c );
    std::cout << discriminant << '\n';
    ans.first =  (-b + (sqrt(discriminant))) / 2 * a;
    ans.second = (-b - (sqrt(discriminant))) / 2 * a;
    std::cout << ans.first << '\n';
    std::cout << ans.second << '\n';
    return ans;
}
int main() {
    double a; double b; double c;
    std::cin >> a >> b >> c;
    quadraticformula(a, b, c);
}
