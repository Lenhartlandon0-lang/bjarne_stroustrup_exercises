//
//  Censoring.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/6/26.
//
#include <iostream>
using namespace std;
int main() {
    cout << "Enter a list of word \n";
    vector<string> words;
    for(string word; cin >> word;) {
        words.push_back(word);
    }
    vector<string> dislike = {"brocolli", "ok", "this", "you", "suck", "whatever"};
    for(string x : words) {
        if(std::find(dislike.begin(), dislike.end(), x) == dislike.end()) {
            cout << x << '\n';
        }
        else {
            cout << "bleep" << '\n';
        }
    }
    return 0;
}
