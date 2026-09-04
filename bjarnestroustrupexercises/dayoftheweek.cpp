//
//  dayoftheweek.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/24/26.
//
/*
 Read (day-of-the-week, value) pairs from standard input. Collect all the values for each day of the week in a vector<int>. Write out the valeus of the seven-day-of-the-week vectors. Ignore illegal days of the week, such as Funday, but accept common synonyms such as Mon and monday. Write out the number of rejected values.
 */

#include <iostream>
bool contains_string_value(const std::vector<std::string>& vec, std::string val) {
    return std::find(vec.begin(), vec.end(), val) != vec.end();
}
bool contains_int_value(const std::vector<int>& vec, int val) {
    return std::find(vec.begin(), vec.end(), val) != vec.end();
}
int main() {
    /*
     First, we need a vector, an int and a string, to store string input, integer input,
     and a vector to store integer inputs. We'll also declare a vector to compare the intro string too,
     to allowlist some words and reject others.
     */
    
    std::string DotW{};
    std::vector<std::string> wordlist{};
    int num{};
    std::vector<int> nums{};
    
    //Words I chose to be acceptable.
    std::vector<std::string> allowedWords {"Monday", "mon", "Mon", "monday", "Tuesday", "Tue", "tuesday", "tue", "Wednesday", "wed", "Wed", "wednesday", "Thursday", "thursday", "thurs", "Thurs", "Friday", "friday", "Fri", "fri", "Saturday", "saturday", "Sat", "sat", "Sunday", "sunday", "Sun", "sun"};
    
    //take string ( day ) input and the integer.
    
    //cc: cuck counter, to cut us off so we don't have to spend all day typing and testing
    int cc{};

    while ( std::cin >> DotW >> num ) {
        
        //add stuffs to vectors
        wordlist.push_back(DotW);
        nums.push_back(num);
        
        //limit maximum amount of inputs to make life easier
        if ( cc > 5 ) {
            break;
        }
        
        if (contains_string_value(allowedWords, DotW)) [[likely]] {
            //increase counter duh
            cc++;
        }
        else {
            //get mad
            throw std::invalid_argument("Please enter a valid day!");
        }
    }
    //Self-explanatory bs
    std::cout << "Now enter the id of the value you'd like to see!\n";
    int id;
    std::cin >> id;
    
    //Check if entered id is in nums
    if ( contains_int_value( nums, id ) ) {
        auto it = std::find( nums.begin(), nums.end(), id );
        
        //since in this happy path it is, we'll use std::distance to get its index
        long index = std::distance( nums.begin(), it );
        
        //give the user what they want
        std::cout << "Your value is the day " << wordlist[index] << "!\n";
    }
    else {
        throw BADSIG; // evil ass code
    }
    return 0;
}
