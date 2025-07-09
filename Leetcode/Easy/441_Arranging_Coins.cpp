/*

//  441. Arranging Coins | Binary Search on Answer


//  Problem Statement: 
    -> You have n coins and you want to build a staircase with these coins. The staircase consists of k rows where the ith row has exactly i coins. The last row of the staircase may be incomplete.
    -> Given the integer n, return the number of complete rows of the staircase you will build.

 
// Example: 

    Example 1:
        Input: n = 5
        Output: 2
        Explanation: Because the 3rd row is incomplete, we return 2.

    Example 2:
        Input: n = 8
        Output: 3
        Explanation: Because the 4th row is incomplete, we return 3.


// Observations: 
    -> Given n coins
    -> find the row on which we can fill that whole row with available coins.
    -> return the largest row on which we can fill the available coins.
    
    // Binary Search on Answer: 
        -> Build a function that will check for every row wether we have enough coins or not?
            -> for every row -> {n * (n + 1) / 2} coins needs
        -> Check for every range 1 to n & try finding the row which satisfies the functions that we have build..


        // Complexity: 
            -> TC: O(logN)
            -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Binary Search:
class Solution {
private: 
    typedef long long ll;
    bool isPossible(ll k ,int n) {  // Function to find the current coins is lesser to total or not?
        ll sum = (k * (k + 1)) / 2;
        return ((ll)n >= sum);
    }
public:
    int arrangeCoins(int n) {
        
        int low = 1;
        int high = n;
        int ans = 1;

        while(low <= high) {
            ll mid = low + (high - low) / 2;

            if(isPossible(mid, n)) {
                low = mid + 1;
                ans = mid;
            } else {
                high = mid - 1;
            }
        }

        return ans;
    }
};