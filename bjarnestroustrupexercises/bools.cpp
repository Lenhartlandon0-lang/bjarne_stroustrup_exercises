//
//  bools.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 9/2/26.
//
/*
 1. Read a value.
 2. Check whether it is the sentinel.
 3. Validate it.
 4. Store or process it.
 */
#include <iostream>

//----------------------------------------------
// Input validation
//----------------------------------------------
bool is_valid_byte( int value ) {
    return value >= 0 && value <= 255;
}

bool is_printable_ascii( int value ) {
    if ( value >= 32 && value <= 126 && is_valid_byte(value)) {
        return true;
    }
    return false;
}
//----------------------------------------------
// End of validation methods, start of main()
//----------------------------------------------
int main() {
    short value{};
    short nonprintables_counter{};
    short printables_counter{};
    short invalid{};
    std::vector<int> valid_inputs{};
    std::vector<char> stuff_to_print{};
    while ( std::cin >> value ) {
        
        if ( value == -1 ) {
            break; // escape character
        }
        
        if ( is_valid_byte(value) ) {
            
            valid_inputs.push_back(value); // This should have a length = to the amount of printable + nonprintable characters
            char printable = is_printable_ascii(value) ? (printables_counter++, static_cast<char>(value)) : (nonprintables_counter++, '.'); // if is_printable_ascii use it's static cast, else '.'
            stuff_to_print.push_back(printable);
            
        }
        else {invalid++;}
    }
    if ( printables_counter + nonprintables_counter != valid_inputs.size() ) {
        std::cout << "shite logic!\n";
    }
    for ( char x : stuff_to_print ) {
        std::cout << x << " ";
    }
    std::cout << '\n';
}
