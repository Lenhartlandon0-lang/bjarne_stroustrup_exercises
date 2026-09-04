//
//  leet.cpp
//  bjarnestroustrupexercises
//
//  Created by Landon Lenhart on 8/21/26.
//
#include <iostream>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int s = n - k + 1;
        vector<unordered_set<int>> array{};
        for ( int i{}; i < s; ++i ) {
            unordered_set<int> subarray(nums.begin() + i, nums.begin() + i + k);
            array.push_back(subarray);
        }
        int counter{};
        int j = 0;
        for ( int i{}; i < array.size(); i++) {
            j++;
            if ( j == s ) {
                j = 0;
            }
            cout << i << endl;
            cout << j << endl;
            for ( const auto& e : array[i] ) {
                counter = 1;
                if ( array[j].contains(e) ) {
                    counter++;
                }
                cout << e << " found " << counter << " times\n";
                if ( counter > 1 ) {
                    nums.erase(std::remove(nums.begin(), nums.end(), e), nums.end());
                }
            }
            cout << "bla" << endl;
            for ( int n : nums ) {
                cout << n << endl;
            }
        }
        auto mx_it = max_element(nums.begin(), nums.end());
        cout << *mx_it;
            return -1;
            }
        };
int main() {
    vector<int> nums = {3, 9, 2, 1, 7};
    int k = 3;
    Solution s;
    s.largestInteger(nums, k);
}
