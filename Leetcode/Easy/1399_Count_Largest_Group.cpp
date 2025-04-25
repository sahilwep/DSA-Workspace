/*

//  1399. Count Largest Group


//  Problem Statement: 
    -> You are given an integer n.
    -> Each number from 1 to n is grouped according to the sum of its digits.
    -> Return the number of groups that have the largest size.

    
// Example:
    Example 1:
        Input: n = 13
        Output: 4
        Explanation: There are 9 groups in total, they are grouped according sum of its digits of numbers from 1 to 13:
        [1,10], [2,11], [3,12], [4,13], [5], [6], [7], [8], [9].
        There are 4 groups with largest size.

    Example 2:
        Input: n = 2
        Output: 2
        Explanation: There are 2 groups [1], [2] of size 1.


// Observations: 
    -> For every number we need digit sum:
        -> when we have same digit sum we will store it somewhere & increase frequency.
        -> we will start from 1 & go up till n
        -> for every number we will find the digit sum
        -> with same digit sum we will store the numbers
        -> Last return the group count of maximum frequency group.

// Complexity: 
    -> TC: O(n * log(n))
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    int digitSum(int x) {
        int sum = 0;
        while(x > 0) {
            int ld = x % 10;
            sum += ld;
            x /= 10;
        }
        return sum;
    }
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> mp;     // <digitSum, frequency>

        for(int i = 1; i <= n; i++) {
            int dSum = digitSum(i);  // get the digit sum.
            mp[dSum]++; // hash the digit sum values.
        }

        // Now check the maximum frequency count: 
        int grpCnt = 0;     // maintain the group count of with maximum frequency.
        int grpFreq = 0;    // maintain the maximum frequency of group

        for(auto &it: mp) {
            int dSum = it.first, freq = it.second;
            if(freq == grpFreq) {
                grpCnt++;
            } 
            else if (freq > grpFreq){
                grpFreq = freq; // set newGroup Frequency our maximum frequency.
                grpCnt = 1;  // set maximum frequency of group as 1.
            }
        }

        return grpCnt;
    }
};