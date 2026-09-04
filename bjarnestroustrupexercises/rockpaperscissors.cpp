//
//  rockpaperscissors.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/16/26.
//
//  Why? Why would you make something so useless?

#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <chrono>
long long rng( int s ) {
    //Xn+1 = (aXn + c) (mod m)
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    int i = 0;
    if (s) {
        while ( i <= s ) {
            i += 2;
            static long long seed = std::chrono::duration_cast<std::chrono::hours>(duration).count();
            long long m = 214748368;
            long long a = 53687093;
            long long c = 214748367;
            seed = (((a * seed) + c) % m);
            return seed % 3 + 1;
        }
    }
    return 0;
}
std::unordered_set<long> create_set ( int input ) {
    std::vector<long> vals{};
    for ( int i{}; i < input; i++ ) {
        vals.push_back(rng(input));
    }
    std::unordered_set<long> a{};
    long index{};
    for (int i = 1; i <= 3; i++) {
        int target = i;
        auto it = std::find(vals.begin(), vals.end(), target);
        index = std::distance(vals.begin(), it);
        a.insert(index % 3 + 1);
    }
    return a;
}
//How can we use this to create a random choice? Already, we are going through the possible values 1-3. The value of each possible outcome should also be assigned to a random number...
std::unordered_map<long, std::string> assign_values ( int input ) {
    std::unordered_set a = create_set(input);
    if ( a.size() != 3 ) {
        while ( a.size() != 3 ) {
            a = create_set(input);
        }
    }
    std::vector<long> setmap(a.begin(), a.end());
    std::unordered_map<long, std::string> assignedvalues {{setmap[0], "Scissors!"}, {setmap[1], "Rock!"}, {setmap[2], "Paper!"}};
    return assignedvalues;
}

int main() {
    std::string input{};
    //rock beats scissors, paper beats rock, scissors beats paper
    std::cout << "Welcome to Rock, Paper, Scissors! Please enter your choice to get started.\n";
    while ( std::cin >> input ) {
        std::cout << "Thank you for entering your choice! Next, enter a random number, whichever you want -- so long as it's not negative or greater than 2,147,483,687... or 32, for some reason?\n";
        int val1;
        std::cin >> val1;
        std::cout << "Calculating...\n";
        std::unordered_map<long, std::string> a = assign_values(val1);
        auto it = a.find(rng(val1));
        if ( it != a.end()) {
            std::cout << it->second << '\n';
            if ( input == "paper" || input == "rock" || input == "scissors" ) {
                if ( it->second == "Paper!" && input != "scissors" ) {
                    std::cout << it->second << " Beats " << input << "!\n";
                }
                else if ( it->second == "Paper!" && input == "scissors" ){
                    std::cout << input << " Beats " << it->second << "!\n";
                    break;
                }
                if ( it->second == "Rock!" && input != "paper" ) {
                    std::cout << it->second << " Beats " << input << "!\n";
                }
                else if ( it->second == "Rock!" && input == "paper" ){
                    std::cout << input << " Beats " << it->second << "!\n";
                    break;
                }
                if ( it->second == "Scissors!" && input != "rock" ) {
                    std::cout << it->second << " Beats " << input << "!\n";
                }
                else if ( it->second == "Scissors!" && input == "rock" ){
                    std::cout << input << " Beats " << it->second << "!\n";
                    break;
                }
                std::cout << "Go again!\n";
            }
            else {
                std::cout << "Enter a valid answer!\n";
            }
        }
    }
    return 0;
}
