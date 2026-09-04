//
//  threesortedintegers.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 7/24/26.
//
#include <iostream>
int main() {
    std::string val1; std::string val2; std::string val3;
    std::cout << "Enter three integer values, and I will use magic to sort them.\n";
    std::cin >> val1 >> val2 >> val3;
    //sort them
    if(val1 >= val2 && val1 >= val3) {
        std::string max = val1;
        std::string min = (val2 < val3) ? val2 : val3; std::string mid = (val2 == min) ? val3 : val2;
        std::cout << min << ' ' << mid << ' ' << max;
    }
    else if (val2 >= val1 && val2 >= val3) {
        std::string max = val2;
        std::string min = (val1 < val3) ? val1 : val3; std::string mid = (val1 == min) ? val3 : val1;
        std::cout << min << ' ' << mid << ' ' << max;
    }
    else if (val3 >= val1 && val3 >= val2) {
        std::string max = val3;
        std::string min = (val1 < val2) ? val1 : val2; std::string mid = (val1 == min) ? val2 : val1;
        std::cout << min << ' ' << mid << ' ' << max;
    }
}
