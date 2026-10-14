/*

//  122. Best Time to Buy and Sell Stock II



//  Problem Statement: 
    - You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
    - On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.
    - Find and return the maximum profit you can achieve.

 
// Example:
    Example 1:
        Input: prices = [7,1,5,3,6,4]
        Output: 7
        Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
        Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
        Total profit is 4 + 3 = 7.

    Example 2:
        Input: prices = [1,2,3,4,5]
        Output: 4
        Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
        Total profit is 4.

    Example 3:
        Input: prices = [7,6,4,3,1]
        Output: 0
        Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.




// Observations:
    - Given array prices
    - on each you may decided to buy/sell the stock, you can only hold at most one share of the stock at anytime.
    - you can sell and buy the stock multiple times on the same day, ensuring you never hold more than one share of the stock.

    // Approach:    
        - On each day we have two choices:
            - buy
            - sell
        - From all the choices: 
            - we will have to return the maximum, from all the choosing possibility.
        
        - We can use recursive solution to process the choices in each possible states.

        - for current index:
            -> if we don't hold any value:
                two options:
                    buy: -prices[i] + (i + 1, holding)
                    skip: (i + 1, not_holding)
            -> if we hold any value:
                two options:
                    sell: prices[i] + (i + 1, not_holding)
                    skip: (i + 1, holding);


            -> last return max({buy, sell, skip})


            // Complexity:
                - TC: O(2^n)
                - SC: O(n)
                    - even if we have buy, sell, and skip, complexity is O(2^n), because we are using if-else: and in one block we only have two choices.


        -> This falls into TLE
        - we can optimize the solution using memoization:
            - variable values:
                i ranges(0 to n)
                holding ranges(0 - 1)

            - create dp table:
                - and memoize..

            // Complexity:
                - TC: O(n)
                - SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization Solution:
class Solution {
private:
    int n;
    vector<vector<int>> t;
    int solve(int i, bool holding, vector<int>& prices) {
        if(i == n) return 0;    // nothing to buy or sell

        // Check in memo-table:
        if(t[i][holding] != INT_MIN) {
            return t[i][holding];
        }

        // Decision Tree: two choices -> buy/sell (sell only if you buy)
        int buy = 0, sell = 0, skip = 0;
        if(!holding) {
            // buy || skip
            buy = -prices[i] + solve(i + 1, !holding, prices);
            skip = solve(i + 1, holding, prices);
        } else {
            // sell || skip
            sell = prices[i] + solve(i + 1, !holding, prices);
            skip = solve(i + 1, holding, prices);
        }

        return t[i][holding] = max({buy, sell, skip});
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        t.resize(n + 1, vector<int> (2, INT_MIN));

        return solve(0, 0, prices);
    }
};

// Recursive Solution: TLE
class Solution_ {
private:
    int n;
    int solve(int i, bool holding, vector<int>& prices) {
        if(i == n) return 0;    // nothing to buy or sell

        // Decision Tree: two choices -> buy/sell (sell only if you buy)
        int buy = 0, sell = 0, skip = 0;
        if(!holding) {
            // buy || skip
            buy = -prices[i] + solve(i + 1, !holding, prices);
            skip = solve(i + 1, holding, prices);
        } else {
            // sell || skip
            sell = prices[i] + solve(i + 1, !holding, prices);
            skip = solve(i + 1, holding, prices);
        }

        return max({buy, sell, skip});
    }
public:
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        return solve(0, 0, prices);
    }
};