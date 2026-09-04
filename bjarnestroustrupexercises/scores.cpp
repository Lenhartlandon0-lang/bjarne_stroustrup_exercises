//
//  scores.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/18/26.
//

#include <iostream>
std::vector<std::string> make_unique ( std::vector<std::string> names ) {
    //rather than throw an error, we can just make sure everything in names is unique by deleting non unique elements.
    int i = 1;
    if ( names.empty () ) {
        std::cout << "Please enter a valid string!";
        return names;
    }
    for ( int j = 1; j < names.size(); j++ ) {
        if ( names[j] != names[i - 1] ) {
            names[j] = names[i];
            i++;
        }
    }
    /*
     
     if ( i > 1 ) {
     iterate over the list of scores and remove the values which were assigned to duplicates.
     
    }
     
     */
    names.erase(names.begin() + i, names.end());
    return names;
}
int main() {
    std::cout << "Please enter a name followed by their score to continue.\n";
    std::string inname;
    int inscore;
    std::vector<std::string> namelist{};
    std::vector<int> scorelist{};
    while ( std::cin >> inname >> inscore ) {
        if ( inname == "NoName" && inscore == 0 ) { //im in-score ^///^
            break;
        }
        
        namelist.push_back(inname);
        scorelist.push_back(inscore);

    }
    namelist = make_unique(namelist);
    if ( namelist.size() == scorelist.size() ) {
        char choice{};
        std::cout << "Enter the letter [a] if you'd like to see a score based on a name, or [b] if you'd like to see a name based on a score.\n";
        std::cin >> choice;
        switch (choice) {
            case 'a': {
                std::cout << "Enter the name of the person who's score you'd like to see!\n";
                std::string nname;
                std::cin >> nname;
                auto it = find(namelist.begin(), namelist.end(), nname);
                if ( it != namelist.end() ) {
                    std::cout << scorelist[it - namelist.begin()] << std::endl;
                }
                else {
                    std::cout << "That persons name is not in our system yet!\n";
                }
                break; }
                
            case 'b': {
                std::cout << "Enter a score!\n";
                int in;
                std::cin >> in;
                auto it = find(scorelist.begin(), scorelist.end(), in);
                if ( it != scorelist.end() ) {
                    std::cout << namelist[it - scorelist.begin()] << std::endl;
                }
                else {
                    std::cout << "That score does not exist.\n";
                }
                break; }
        }
    }
    else {
        std::cout << "Please do not enter the same name twice! \n";
    }
}
//final exercise of chapter 3
