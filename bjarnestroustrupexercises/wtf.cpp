#include <iostream>
int cows ( std::vector<char> user, std::vector<char> rand ) {
    
    // return the number of letters the user entered which match rand,
    // regardless of whether or not they are actually in-position
    int cow{};
    
    // we'll iterate through the users input and use find()
    // to see if the users input values line up with any in rand.
    for ( char x : user ) {
        
        // it -> x
        auto it = find(rand.begin(), rand.end(), x);
        
        auto ti = find(user.begin(), user.end(), x); // quick fix to make sure a bull doesnt show up as a cow too
        
        auto dist_rand = (rand.begin(), it);
        auto dist_user = (user.begin(), ti);
        // if the iterator positions are not the same, do this.
        // nothing will happen otherwise, of course.
        if ( it != rand.end() && dist_rand != dist_user ) {
            cow++;
        }
        
    }
    
    return cow;
    
}

int main() {
    std::vector<char>* u = new std::vector<char> {'a', 'b', 'f', 'c'};
    std::vector<char> r = {'a', 'b', 'c', 'f'};
    int bullys = cows(*u, r);
    std::cout << bullys;
    delete u;
    std::cout << "you're safe...";
    
}
