/*

//  1550. Three Consecutive Odds


//  Problem Statement: 
    -> Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
 

// Example:

    Example 1:
        Input: arr = [2,6,4,1]
        Output: false
        Explanation: There are no three consecutive odds.

    Example 2:
        Input: arr = [1,2,34,3,4,5,7,23,12]
        Output: true
        Explanation: [5,7,23] are three consecutive odds.



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    bool isOdd (int x) {
        return (x % 2 != 0);
    }
public:
    bool threeConsecutiveOdds(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return false;

        for(int i = 2; i < n; i++) {
            if(isOdd(nums[i-2]) && isOdd(nums[i-1]) && isOdd(nums[i])) {
                return true;
            }
        }

        return false;
    }
};