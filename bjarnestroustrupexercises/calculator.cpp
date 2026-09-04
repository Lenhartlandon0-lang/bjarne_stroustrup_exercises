//
//  calculator.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/26/26.
//

#include <iostream>
#include "PPPheaders.h"
class Token {
public:
    char kind;
    double value;
    Token(char ch) :kind(ch), value(0) { }
    Token(char ch, double val) :kind(ch), value(val) { }
};

class Token_stream {
public:
    Token_stream();
    Token get();
    void putback(Token t);
    
private:
    bool full;
    Token buffer;
    
};

Token_stream::Token_stream() :full(false), buffer(0)  {}  // no Token in buffer

void Token_stream::putback(Token t) {
    if (full)
    {
        error("cannot call putback() with a full buffer!");
    }
    buffer = t;
    full = true;
}

Token Token_stream::get() {
    //This function will be for putting tokens into the token stream.
    if (full)
    {
        full = false;
        return buffer;
    }
    char ch = 0;
    std::cin >> ch;
    switch(ch)
    {
        case '+': case '-': case '*': case '/': case '^': case '!': case '(': case ')': case 'q': case ';': case'{': case '}':
        {
            return Token(ch); //"easy values": 'values' who's value don't really matter
        }
            
        case '.': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9': case '0':
        {
            //case for numbers...
            std::cin.putback(ch);
            double val;
            std::cin >> val;
            return Token('8', val);
        }
        default:
            error("Please enter a valid input!");
    }
    return Token('f', -1);
// hopefully this still works. Fuck you compiler!! agh!!!
}

Token_stream ts;
/*************************************************************mathematic functions here*************************************************************/
double expr();
//Forward declare expression() so other functions can use it ahead-of-time

/**********************************************************************************************************************************/
double primary() {
    
    Token t = ts.get(); //turn tokenstream into single token
    switch (t.kind)
    {
        case '{':
        {
            double n = expr();
            t = ts.get();
            if (t.kind != '}' ) error("'}' expected");
            return n;
        }
        case '(':
        {
            double n = expr();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return n;
        }
        case '8':            // we use '8' to represent a number
                return t.value;  // return the number's value
        default:
            error("Primary expected");
            return -1.0;
    }
}
/**********************************************************************************************************************************/
/*
 SPECIAL:
    primary
    primary!
    primary^primary
 */
/**********************************************************************************************************************************/

int special() {
    
    int left = primary(); //get the next token, don't forget
    Token t = ts.get();
    
    //A special should only really be able to take a factorial and an exponent. later, we can add log, ln, and roots, but these are the basic ones we can do for now.
    //It is prioritized over addition, subtraction, multiplication and division, but it is done after the parsing of integers (values) and parentheses (primaries, hence the use of primary for the left hand value.
    while(true)
    {
        switch (t.kind)
        {
            case '!':
            {
                if ( left == 0 )
                {
                    return 1;
                }
                
                for ( int i = left - 1; i > 0; i-- )
                {
                left *= i;
                }
            t = ts.get();
            break;
        }
                
        case '^':
        {
            if ( left == 0 )
            {
                return 1;
            }
            
            int base = left;
            
            int right = primary();
            for ( int i = 1; i < right; i++ ) {
                left *= base;
            }
            t = ts.get();
            break;
        }
        default:
            ts.putback(t);
            return left;
        }
    }
}
/**********************************************************************************************************************************/
/*
 TERM:
   primary
   term * primary
   term / primary
 */
/**************************************************************************************************************************************************/
double term() {
    
    double left = special();
    Token t = ts.get();
    
    while(true) {
        switch(t.kind) {
                
            case '*': {
                left *= special();
                t = ts.get();
                break;
            }
            case '/': {
                double d = special();
                if ( d == 0 ) {
                    error("Cannot divide by 0!");
                }
                t = ts.get();
                left /= special();
            }
            default:
                ts.putback(t);
                return left;
                
        }
    }
}
/**************************************************************************************************************************************************/

/**************************************************************************************************************************************************/
double expr() {
/*EXPRESSION:
    term
    expression + term
    expression - term
 */
    double left = term();
    Token t = ts.get();
    while (true) {
        switch(t.kind) {
            case '+': {
                left += term();
                t = ts.get();
                break;
            }
            case '-':
            {
                left -= term();
                t = ts.get();
                break;
            }
            default:
            {
                ts.putback(t);
                return left;
            }
        }
    }
}
/*************************************************************mathematic functions end*************************************************************/
/**************************************************************************************************************************************************/

int main() {
    try {
        while (true) {
            Token t = ts.get();
            if (t.kind == 'q') {break;}
            if (t.kind == ';') {continue;} // force no exception handling
            ts.putback(t);
            double result = expr();
            std::cout << "= " << result << '\n';
        }
    }
    catch ( exception& e ) {
        std::cerr << "Error: " << e.what() << '\n';
        return 1;
    }
    catch (...) {
        std::cerr << "Wtf?\n";
        return 2;
    }
}
//what the fuck am I even doing?
