/*

//  3005. Count Elements With Maximum Frequency


//  Problem Statement: 
    -> You are given an array nums consisting of positive integers.
    -> Return the total frequencies of elements in nums such that those elements all have the maximum frequency.
    -> The frequency of an element is the number of occurrences of that element in the array.

 
// Example: 
    Example 1:
        Input: nums = [1,2,2,3,1,4]
        Output: 4
        Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
        So the number of elements in the array with maximum frequency is 4.

    Example 2:
        Input: nums = [1,2,3,4,5]
        Output: 5
        Explanation: All elements of the array have a frequency of 1 which is the maximum.
        So the number of elements in the array with maximum frequency is 5.

// Observations: 
    -> hash all the numbers frequency
    -> get the maximum frequency count.
    -> If multiple numbers have same maximum frequency, store all of them.


// Complexity:
    -> TC: O(N)
    -> SC: O(1)

    
*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        
        vector<int> freq(101, 0);
        for(auto& num: nums) {
            freq[num]++;
        }

        int tFreq = 0;
        int currFreq = 0;
        for(auto& x: freq) {
            if(x > currFreq) {
                currFreq = x;
                tFreq = x;
            } else if(x == currFreq) {
                tFreq += x;
            }
        }

        return tFreq;
    }
};