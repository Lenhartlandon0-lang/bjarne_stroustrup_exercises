//
//  array_tomfoolery.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 9/6/26.
//
#include <array>
#include <iostream>
int main() {
    
    std::array<char, 10> a{'s', 1, 'a' , 3, 4, 5, 6, 7, 8, 9};
    
    char* p = a.data(); // Pointer to the first object of a
    
    std::cout << "address of p is " << &p << '\n'; // prints garbage becasuse cout treats p as a c-string
    std::cout << "The dereferenced value of p is " << *(p + 2) << '\n';
    
    *(p + 2) = 'f';
    
    std::cout << a[2];
    
    return 0;
    
}
