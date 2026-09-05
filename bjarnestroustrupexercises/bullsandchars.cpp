//
//  bullsandchars.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 9/2/26.
//
#include <iostream>
#include <random>
#include <vector>
char make_random_char( ) {
    
    // make random device for use w/ engine
    std::random_device rd;
    
    // make engine
    std::mt19937 engine(rd());
    
    // ints in the range of printable ascii chars
    std::uniform_int_distribution<int> dist(32, 126);
    
    // (hopefully) static_cast a random int in that range to a char
    char randomc = static_cast<char>(dist(engine));
    
    // return the random char
    return randomc;
    
}

std::vector<char> generate_rand ( int list_size ) {
    //make list return it
    std::vector<char> rand{};
    
    //add objects by-pass to rand
    for ( int i{}; i < list_size; i++ ) {
        
        const char c = make_random_char();
        rand.push_back(c);
        
    }
    
    return rand;
    
}

std::vector<char> tokenize_input( std::string input ) {
    
    //lossy conversion because input size shouldn't be that big anyway
    short len = input.size();
    
    //declare char vector for comparison
    std::vector<char> userguess{};
    
    //Check for valid length (we could probably change this later)
    if ( len <= 0 || len > 4 ) {
        throw std::invalid_argument("Please only enter up to 4 chars at a time.");
    }
    
    for ( int i{}; i < len; i++ ) {
        
        char c = input[i]; // index-by-index conversion to char
        userguess.push_back(c); // push char into user guess
        
    }
    
    return userguess;
}

std::vector<bool> matched_positions ( std::vector<char> user, std::vector<char> rand ) {
    
    std::vector<bool> bulls (4); // vector of 4 falses rn
    int itrtr{}; // iterator variable
    
    for ( auto x : user ) {
        // if a character in users input exactly matches a character in rand,
        // flip that index to a bull
        
        if ( rand[itrtr] == x ) {
            
            bulls[itrtr] = true;
            
        }
        
        itrtr++;
        
    }
    
    return bulls;
}

bool bullscheck ( std::vector<bool> v ) {
    
    // little function to allow for looped input w/ while
    for ( auto x : v ) {
        if (!x) {
            return true; // continue if any position in bulls is still 0 (false)
        }
    }
    return false; // if every value in bulls is true, the user has won -- end the game
}

void show_bulls ( std::vector<bool> bulls ) {
    
    //show the user what positions they've got!
    for ( bool x : bulls ) {
        
        std::cout << x << ' ';
        
    }
    
    std::cout << '\n';
    
}

int bulls_count( std::vector<bool> bulls ) {
    // the original exercise requests that we print the number of bulls we found, too.
    
    int found{}; // the default amount is of course 0...
    
    for ( bool x : bulls ) {
        
        if ( x ) {
            
            found++;
            
        }
    }
    return found;
}

int cows ( std::vector<char> user, std::vector<char> rand, std::vector<bool> bull ) {
    
    // return the number of letters the user entered which match rand,
    // regardless of whether or not they are actually in-position
    int cow{};
    
    // we'll iterate through the users input and use find()
    // to see if the users input values line up with any in rand.
    for ( char x : user ) {
        
        // it -> x
        auto it = find( rand.begin(), rand.end(), x );
        auto shit = distance( rand.begin(), it );
        
        // if the iterator positions are not the same, do this.
        // nothing will happen otherwise, of course.
        if ( it != rand.end() && !bull[shit] ) { // added check
            // cows will not be bulls
            cow++;
            
        }
        
    }
    
    return cow;
    
}


int main() {
    
    std::vector<char> guessthis = generate_rand(4); // vector where random chars will be stored
    
    std::cout << "Enter a stream of four characters, and we'll tell you what you got right.\n";
    
    std::string guess{};
    
    std::cin >> guess;
    
    std::vector<char> user_guess = tokenize_input(guess); // turn input into a vector of chars for our other functions
    
    std::vector<bool> bulls = matched_positions(user_guess, guessthis);
    
    show_bulls(bulls); // shows correct positions below guess
    
    while ( bullscheck ( matched_positions ( user_guess, guessthis ) ) ) {
        
        std::cin >> guess; // guess is already a string, we don't need init
        
        user_guess = tokenize_input(guess); // turn it into a vector of chars again
        
        bulls = matched_positions(user_guess, guessthis); // update bulls to reflect users current standing
        
        show_bulls(bulls);
        
        std::cout << "You have " << bulls_count(bulls) << " bulls and " << cows( user_guess, guessthis, bulls ) << " cows!\n";
        
    }
    
    
}
