//
//  integerbdsm.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//

#include <iostream>
int main() {
    float val1; float val2;
    std::cout << "Enter two floating point values, separated by a space.\n";
    std::cin >> val1 >> val2;
    float min = (val1 < val2) ? val1 : val2; //condition, true part, false part
    float max = (val1 > val2) ? val1 : val2; //if val1, is greater than val2, we will set max to val1.
    float sum = val1 + val2;
    float difference = max - min;
    float product = val1 * val2;
    std::cout << "The smallest value is " << min << " and the larger value is " << max << '\n' <<         "The sum of the values is " << sum << " and the difference is " << difference << '\n'
             << "The product of the values is " << product << " and the ratio is " << max << '/' << min << '\n';
    
}
