/*

//  1523. Count Odd Numbers in an Interval Range


//  Problem Statement: 
    - Given two non-negative integers low and high. Return the count of odd numbers between low and high (inclusive).

 
// Example:
    Example 1:
        Input: low = 3, high = 7
        Output: 3
        Explanation: The odd numbers between 3 and 7 are [3,5,7].

    Example 2:
        Input: low = 8, high = 10
        Output: 1
        Explanation: The odd numbers between 8 and 10 are [9].


// Observations:
    - We have mathematical formula for counting odd number from 1 to n: (n + 1) / 2
    - For efficient approach, we can count total odd number from 1 to high with: (high + 1) / 2
    - then we can again count, total odd number from 1 to low with: low / 2
        - Note: we didn't count 1, as we already counted with high.
    - Last we will subtract the lowCnt from highCnt.
    
    // Complexity: 
        - TC: O(1)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// O(1)
class Solution {
public:
    int countOdds(int low, int high) {

        int cntFrom1Tohigh = (high + 1)/ 2;
        int cntFrom1Tolow = low / 2;
        int total = cntFrom1Tohigh - cntFrom1Tolow;

        return total;
    }
};

// Bruteforce:
class Solution {
public:
    int countOdds(int low, int high) {
        int odd = 0;

        for(int i = low; i <= high; i++) {
            if(i % 2 != 0) odd++;
        }
        
        return odd;
    }
};