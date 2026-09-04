//
//  minmaxmodestrings.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/17/26.
//

#include <iostream>
std::string findmax ( std::vector<std::string> s ) {
    std::ranges::sort( s.begin(), s.end() );
    std::string max = s.back();
    std::cout << max << '\n';
    return max;
}
std::string findmin ( std::vector<std::string> s ) {
    std::ranges::sort( s.begin(), s.end() );
    std::string min = s[0];
    std::cout << min << '\n';
    return min;
}
std::string findmode ( std::vector<std::string> s ) {
    std::string mode{};
    std::ranges::sort( s.begin(), s.end() );
    std::vector<int> temp{};
    int count{};
    for ( int i{}; i < s.size() - 1; i++ ) {
        std::string current = s.at(i);
        if ( s.at(i+1) == current) {
            count++;
            while ( current == s.at(i+count)) {
                count++;
            }
            temp.push_back(count);
        }
        else {temp.push_back(0);}
    }
    auto mm = std::ranges::minmax_element(temp);
    int max = *mm.max;
    for ( int i{}; i < s.size() - 1; i++ ) {
        if ( temp.at(i) == max ) {
            mode = s.at(i);
        }
    }
    std::cout << mode << '\n';
    return mode;
}
int main() {
    std::vector<std::string> a {"apple", "banana", "cucumber", "apple"};
    findmax(a);
    findmin(a);
    findmode(a);
}
