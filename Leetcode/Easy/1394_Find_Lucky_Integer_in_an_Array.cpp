/*

//  1394. Find Lucky Integer in an Array

//  Problem Statement: 
    -> Given an array of integers arr, a lucky integer is an integer that has a frequency in the array equal to its value.
    -> Return the largest lucky integer in the array. If there is no lucky integer return -1.

 
// Example: 

    Example 1:
        Input: arr = [2,2,3,4]
        Output: 2
        Explanation: The only lucky number in the array is 2 because frequency[2] == 2.

    Example 2:
        Input: arr = [1,2,2,3,3,3]
        Output: 3
        Explanation: 1, 2 and 3 are all lucky numbers, return the largest of them.

    Example 3:
        Input: arr = [2,2,2,3,3]
        Output: -1
        Explanation: There are no lucky numbers in the array.


//  Approach: 
    -> Hash the given number frequency in map.
    -> return the largest one.
    -> If no value found return -1;

// Complexity: 
    -> TC: O(n)
    -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findLucky(vector<int>& arr) {

        unordered_map<int, int> mp;
        for(auto& num: arr) {
            mp[num]++;
        }

        int ans = -1;
        for(auto& [num, freq]: mp) {
            if(num == freq) {
                if(num > ans) {
                    ans = num;
                }
            }
        }

        return ans;
    }
};