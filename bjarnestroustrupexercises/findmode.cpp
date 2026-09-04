//
//  findmode.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/17/26.
//

#include <iostream>
int findmode ( std::vector<int> list ) {
    int mode{};
    std::ranges::sort(list.begin(), list.end());
    std::vector<int> countlist{};
    for ( int i{}; i < list.size() - 1; i++ ) {
        //in order to determine the mode, we need to determine which number repeats the most. (no shit)
        if ( list.at(i + 1) == list.at(i) ) {
            // if one element matches another, we should say that's a "good" element
            int count = 1;
            while (list.at(i) == list.at(i+count)) {
                //increase the points for the repeatedly matching value
                count++;
            }
            countlist.push_back(count);
        }
        else {
            //make sure the lists are of even length
            countlist.push_back(0);
        }
    //Now we have a list of counts for repeated numbers, the max of which is obviously the mode. But we're still iterating over the original list.
        auto minmax = std::ranges::minmax_element(countlist);
        int max = *minmax.max;
        if ( countlist.at(i) == max ) {
            mode = list.at(i);
        }
    }
    std::cout << mode << '\n';
    return mode;
}
int main() {
    std::vector<int> f {1, 1, 1, 1, 1, 2, 5, 3, 2, 6, 6, 23, 2, 2, 6, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 4, 5, 6, 1001, 3, 5};
    findmode(f);
    return 0;
}
