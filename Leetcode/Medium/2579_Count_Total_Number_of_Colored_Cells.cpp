/*

//  2579. Count Total Number of Colored Cells


//  Problem Statement: 
    -> There exists an infinitely large two-dimensional grid of uncolored unit cells. You are given a positive integer n, indicating that you must do the following routine for n minutes:
        -> At the first minute, color any arbitrary unit cell blue.
        -> Every minute thereafter, color blue every uncolored cell that touches a blue cell.
    -> Below is a pictorial representation of the state of the grid after minutes 1, 2, and 3.
    -> Return the number of colored cells at the end of n minutes.

// Example: 

    Example 1:

        Input: n = 1
        Output: 1
        Explanation: After 1 minute, there is only 1 blue cell, so we return 1.

    Example 2:

        Input: n = 2
        Output: 5
        Explanation: After 2 minutes, there are 4 colored cells on the boundary and 1 in the center, so we return 5. 


// Approach:
    -> If we observe this question with higher number 4, 5 we can easily crack the pattern how it's increasing..
    -> We just have to add the oddNum sequence until we not reach to end point..
    -> Breaking point when oddNum divide by 2 and add 1 is equal to given number..
        -> make sure to add the last generated oddNum, which is the middle oddNum..

        

// Complexity:
    -> TC: O(n)
    -> SC: O(1)



*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
private: 
    typedef long long ll;
public:
    long long coloredCells(int n) {
        ll ans = 0;
        int oddNum = 1;

        while(true) {
            if((oddNum / 2) + 1 == n) { // if we reach to middle odd number.
                ans += oddNum;  // add the last generated odd Number into answer.
                break;  // break out
            }

            // Generate answer: Add oddNumber twice in our answer.
            ans += (oddNum) * 2;

            // Increment to next odd number:
            oddNum += 2;
        }

        return ans;
    }
};