/*

// 121. Best Time to Buy and Sell Stock


//  Problem Statement: 
    -> You are given an array prices where prices[i] is the price of a given stock on the ith day.
    -> You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
    -> Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


// Example: 
    Example 1:
        Input: prices = [7,1,5,3,6,4]
        Output: 5
        Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
        Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

    Example 2:
        Input: prices = [7,6,4,3,1]
        Output: 0
        Explanation: In this case, no transactions are done and the max profit = 0.

// BruteForce: 
    -> use nested loop to find the maximum difference.

    // Complexity: 
        -> TC: O(n^2)
        -> SC: O(1)
    

// Efficient Solution: 
    ->  Use Two Pointer approach, & start iterating from right to left:
        -> One pointer should be pointing on maxElement
        -> Second pointer should be pointing on the minElement
        -> We will make sure that minPointer will always be on left of maxPointer.

    // Complexity: 
        -> TC: O(n)
        -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: 
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int minPtr = n-1, maxPtr = n-1;
        int maxDiff = 0;

        // Iterate from backwords:
        for(int i = n - 1; i >= 0; i--) {
            if(prices[i] >= prices[maxPtr]) {
                maxPtr = i;
                minPtr = i; // we also need to change this minPtr, as it should be left to maxPtr
            } else if(prices[i] < prices[minPtr]) {
                minPtr = i;
            }

            // Get the max Difference: 
            maxDiff = max(maxDiff, prices[maxPtr] - prices[minPtr]);
        }
        
        return maxDiff;
    }
};

// BruteForce: TLE TC: O(n^2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(prices[j] > prices[i]) {
                    ans = max(ans, prices[j] - prices[i]);
                }
            }
        }
        
        return ans;
    }
};