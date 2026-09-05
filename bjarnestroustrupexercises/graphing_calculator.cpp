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
    
    char* data() { return m_data; }
    const char* data() const { return m_data; }
    
    size_t size() const { return m_size; }
    size_t capacity() const { return m_cap; }
};


class Plane {
    
public:
    // public values
    
private:
    // private values
    
};
int main() {
    graphics_buffer gb;
}
