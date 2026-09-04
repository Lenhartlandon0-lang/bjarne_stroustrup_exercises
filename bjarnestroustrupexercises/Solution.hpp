//
//  Solution.hpp
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
        if ( k == 1 ) {
            sort(nums.begin(), nums.end());
            cout << "n";
            vector<int> res;
            for (int i = 0; i < n; ++i) {
                bool is_duplicate = (i > 0 && nums[i] == nums[i - 1]) ||
                             (i < n - 1 && nums[i] == nums[i + 1]);
                             if (!is_duplicate) {
            res.push_back(nums[i]);
        }
    }
    nums = std::move(res);
    if (!nums.empty()) {
        auto mx_it = max_element(nums.begin(), nums.end());
            int MAX_UNIQUE_INT = *mx_it;
            return MAX_UNIQUE_INT;
    }
    else {
        for ( int i{}; i < s; ++i ) {
            unordered_set<int> subarray(nums.begin() + i, nums.begin() + i + k);
            array.push_back(subarray);
        }
        int counter{};
        int j = 0;
        for ( int i{}; i < s; i++) {
            j++;
            if ( j == s ) {
                j = 0;
            }
            for ( const auto& e : array[i] ) {
                counter = 1;
                if ( array[j].contains(e) ) {
                    counter++;
                }
                if ( counter > 1 && k != n ) {
                    nums.erase(std::remove(nums.begin(), nums.end(), e), nums.end());
                }
            }
        }
        if(!nums.empty() || k == n ) {
            auto mx_it = max_element(nums.begin(), nums.end());
            int MAX_UNIQUE_INT = *mx_it;
            return MAX_UNIQUE_INT;
        }
        else {
            int MAX_UNIQUE_INT = -1;
            return MAX_UNIQUE_INT;
        }
    }
            }
        };
};
int main() {
    vector<int> nums = {0, 0};
    int k = 2;
    Solution s;
    s.largestInteger(nums, k);
}
