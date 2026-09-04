//
//  Distances.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/15/26.
//

#include <iostream>
double findgreatest( std::vector<double> values ) {
    double max = 0;
    for ( double x : values ) {
        if ( x > max ) {
            max = x;
        }
    }
    std::cout << max << std::endl;
    return max;
}
double findleast( std::vector<double> values, double max ) {
    double min = 0;
    for ( double x : values ) {
        if ( x < max ) {
            min = x;
        }
    }
    std::cout << min << std::endl;
    return min;
}
double sum ( std::vector<double> values ) {
    double sum = 0;
    for ( double x : values ) {
        sum = sum + x;
    }
    std::cout << sum << std::endl;
    return sum;
}

int main() {
    std::vector<double> distances = {1, 3, 8, 29, 2, 3};
    double max = findgreatest(distances);
    findleast(distances, max);
    double s = sum(distances);
    std::cout << (s / std::size(distances)) << std::endl;
}
