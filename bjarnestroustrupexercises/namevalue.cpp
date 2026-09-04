//
//  namevalue.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/28/26.
//

#include <iostream>
/* part of Bjarne Stroustrup's programming exercises */
class name_value {
public:
    
    std::string name;
    int value;
    
    name_value() :name(""), value(-2) {}
    name_value(std::string n, int v) :name(n), value(v) {}
    
    std::string find_string( std::vector<name_value> nv, int n );
    int find_int( std::vector<name_value> namv, std::string str );
};

std::string name_value::find_string( std::vector<name_value> namv, int n ) {
    auto it = find_if(namv.begin(), namv.end(), [n] (const auto& nv) {return nv.value == n; } );
    if ( it != namv.end() ) {
        auto dist = distance(namv.begin(), it);
        return namv[dist].name;
    }
    else if ( it == namv.end() ){
        return "aw man!";
    }
    else {
        return "exception";
    }
}
int name_value::find_int( std::vector<name_value> namv, std::string str ) {
    auto it = find_if(namv.begin(), namv.end(), [str] (const auto& nv) {return nv.name == str; } );
    if ( it != namv.end() ) {
        auto dist = distance(namv.begin(), it);
        return namv[dist].value;
    }
    else {
        return 0;
    }
}

name_value bs; //stands for bull shit

int main() {
    
    std::vector<name_value> list{};
    std::string n; int v; int ul;
    int i = 1;
    
    std::cout << "Enter an integer for the maximum size of your list! Then, you'll enter a pair of a string an an integer for every value in the your stated range!\n";
    
    std::cin >> ul;
    std::cout << ul << " Will be the maximum allowed entries. Please hit enter every entry.\n";
    
    
    while ( i <= ul ) {
        std::cin >> n >> v;
        list.push_back(name_value(n, v));
        i++;
    }
    
    char choice{};
    std::cout << "Hello! Please enter 's' or 'i' to continue...\n";
    std::cin >> choice;
        switch ( choice ) {
            case 's':
            {
                int in;
                std::cout << "Enter the integer you'd like to find your entered string-value for!\n";
                std::cin >> in;
                std::string ans = bs.find_string(list, in);
                std::cout << ans << '\n';
                break;
            }
            case 'i':
            {
            std::cout << "Enter the string you'd like to find your entered integer-value for!\n";
            std::string in;
            std::cin >> in;
            int ans = bs.find_int(list, in);
            std::cout << ans << '\n';
            break;
        }
        default:
            std::cout << "Please enter a valid choice!\n";
            break;
    }
}
