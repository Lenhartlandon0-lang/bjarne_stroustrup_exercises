//
//  graphing_calculator.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 9/5/26.
//

/*
 * Graphing calculator version 0.0.0:
 * The mission: display a simple triangle.
 */

#include <iostream>
#include <algorithm>
#include <cmath>
class graphics_buffer {
private:
    
    //variables for internal use only.
    
    char* m_data; // pointer to what will later be an array of chars
    size_t m_cap; // the maximum size of the buffer
    size_t m_size; // the current size of the buffer
    
public:
    
    //constructor functinos
    
    explicit graphics_buffer( size_t cap = 10000 )  // always make constructors explicit if they can be called with a single arugment.
    : m_cap(cap), m_size(0)
    {
        m_data = new char[m_cap];
    }
    
    //destructor function
    ~graphics_buffer()
    {
        delete[] m_data;
    }
    
    // constructor with another same type
    graphics_buffer( const graphics_buffer& other ) // pass - by - reference to avoid heavy copying
    : m_cap(other.m_cap), m_size(other.m_size) { // assign m_cap as the old m_cap and the same for size, and allocate a similar amount of memory to what was already allocated
        m_data = new char[m_cap]; // you know...
        std::copy(other.m_data, other.m_data + other.m_size, m_data); // once everything has been properly moved over, we can just use std::copy to properly copy the graphics_buffer object
    }
    
    // avoid shitty default copying when =
    graphics_buffer& operator=( const graphics_buffer& other ) {
        
        // default back to norm if other is this
        if ( this == &other ) {return *this;}
        
        delete[] m_data;
        m_cap = other.m_cap;
        m_size = other.m_size;
        m_data = new char[m_cap];
        
        return *this;
    }
    // ----------
    // helper functinos
    // ----------
    void push_back( char val ) {
        if ( m_size < m_cap ) {
            m_data[m_size++] = val;
        }
    }
    
    char* data() { return m_data; } // method for access (copied from array_)
    const char* data() const { return m_data; } // const ver
    
    size_t size() const { return m_size; } // current size
    size_t capacity() const { return m_cap; } // maximum capacity
    
    char& operator[] ( size_t index ) { // dereference-char-returning [] operator
        return *(this->data() + index); // graphics buffer.data() + index = value at index
    }
    
};


// A graphics_buffer object is basically just an array of 10k garbage chars.
// (or more, or less)
// in order to create it into a 2d plane, we need x and y coordinates.

uint fus(size_t n) {
    // fus stand for fast unsigned integer square root
    // it is also part of the dragonborn chant in skyrim
    uint res = 0;
    uint bit = 1U << 30; // 2^30
    
    // since bit starts at 2^30, rightshift it until its less than n
    while ( bit > n ) {
        bit >>= 2;
    }
    
    while ( bit != 0 )
    {
        if ( n >= res + bit ) {
            // if n is greater than or equal to res + bit,
            // subtract n by their sum ()
            // and rightshift res 1 ()
            n -= res + bit;
            res = ( res >> 1 ) + bit;
        }
        
        else {
            // if n is not greater, we only need to rightshift once to get an approximate result (res = res/2)
            res >>= 1;
        }
        // always rightshift bit
        // (bit = bit/4)
        bit >>= 2;
    }
    return res;
}

class Plane {
private:
    // private values
    graphics_buffer gb; //array for manipulation (default size = 10000 chars)
    // max size of array
public:
    const size_t cap = gb.capacity();
    const uint sq = fus(cap);
    graphics_buffer initialize() {
        for ( int i{}; i < cap; i++ ) {
            gb[i] = ' ';
        }
        return gb;
    }
    
    graphics_buffer plot( int x, int y ) {
        size_t index = x * sq + y;
        gb[index] = '.';
        return gb;
    }
    
    graphics_buffer plot( int index ) {
        gb[index] = '.';
        return gb;
    }
    
    void draw() {
        for ( int i{}; i < cap; i++ ) {
            if ( i % sq == 0 && i != 0) {
                std::cout << '\n';
            }
            std::cout << gb[i];
        }
    }
    // public values
};
int main() {
    Plane p;
    p.initialize();
    for ( int x{}; x < p.sq; x++ ) {
        for ( int y{}; y < p.sq; y++) {
            if ( y == x ) {
                p.plot(x, y);
            }
        }
    }
    p.draw();
    std::cout << '\n';
}

