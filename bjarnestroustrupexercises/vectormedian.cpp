//
//  vectormedian.cpp
//  
//
//  Created by Landon Lenhart on 8/6/26.
//

#include <iostream>
int main() {
    std::vector<double> v;
    for (double i; std::cin >> i;) {
        v.push_back(i);
    }
    std::ranges::sort(v);
    if(v.size() % 2) {
        double median = v[v.size() / 2];
        std::cout << median;
    }
    else {
        double median = v[(v.size() / 2 + (v.size() / 2) + 1) / 2];
        std::cout << median;
        
    }
}
