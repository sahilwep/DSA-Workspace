/*

//  3573. Best Time to Buy and Sell Stock V


//  Problem Statement: 
    - You are given an integer array prices where prices[i] is the price of a stock in dollars on the ith day, and an integer k.
    - You are allowed to make at most k transactions, where each transaction can be either of the following:
        - Normal transaction: Buy on day i, then sell on a later day j where i < j. You profit prices[j] - prices[i].
        - Short selling transaction: Sell on day i, then buy back on a later day j where i < j. You profit prices[i] - prices[j].
    - Note that you must complete each transaction before starting another. Additionally, you can't buy or sell on the same day you are selling or buying back as part of a previous transaction.
    - Return the maximum total profit you can earn by making at most k transactions.

 
// Example: 

    Example 1:
        Input: prices = [1,7,9,8,2], k = 2
        Output: 14
        Explanation: We can make $14 of profit through 2 transactions:
            A normal transaction: buy the stock on day 0 for $1 then sell it on day 2 for $9.
            A short selling transaction: sell the stock on day 3 for $8 then buy back on day 4 for $2.

    Example 2:

        Input: prices = [12,16,19,19,8,1,19,13,9], k = 3
        Output: 36
        Explanation: We can make $36 of profit through 3 transactions:
            A normal transaction: buy the stock on day 0 for $12 then sell it on day 2 for $19.
            A short selling transaction: sell the stock on day 3 for $19 then buy back on day 4 for $8.
            A normal transaction: buy the stock on day 5 for $1 then sell it on day 6 for $19.

    

// Observations:
    - we will try writing the recursive solution for both the case & try finding the maximum profit we can get..
    - NOTE: Always make sure that every transaction complete before starting another one.
    - Choices:
        - No action:
            - move for that price[i]..
        - Action:
            - Let's Say Buy:
                - (-price[i]), it's because this much about is gone from our pocket
                - We have just buy means we have to sell this on future, then only we can start another transactions..
                - A Complete Transactions is:
                    buy -> sell     => Normal transactions.
                    sell -> buy     => Short selling
                
                - We need to make sure that we should complete every transactions, then only we can decrement 'k'.
                - if we buy, then we must sell || OR || if we sell, then we must buy.

            - Other Options is we can short-Sell:   
                - means we just sell that amount..
                - In future when price is low, we will purchase that and get the profit..

    - We can say we will have 3 choices for Action:
        - No Actions:
            - skip
        - Action:
            - Buy -> sell
            - Sell -> buy
            - Start Fresh Transaction

    - Also when we we have take action, we need to make sure that next action should be in chain, means (buy -> sell |OR| sell -> buy)


    - More Clearly for choices:
        case 0:  fresh Transaction

        case 1: buy -> sell (normal transaction)

        case 2: sell -> buy (short-sell)


    - Recursive Solution:
                    ll solve(i, k, case, prices[]) {
                        ...
                    }; 

                    solve(0, k, 0, prices) -> case = 0, because initially we will start fresh transaction.

            For current index:

                -> Do-nothing: don't take anything..
                    dontTake = solve(i + 1, k, case, price);    => just move

                -> Take Action:
                    int take = 0;
                    if(k > 0):      // check if we have available transaction
                        check case:
                            case 1: we have buy & now we will sell (normal transaction)
                                take = price[i] + solve(i + 1, k - 1, 0, prices);  -> here at this point we are selling means we will add this value into our profit and also, one transaction is completed & also we can start new fresh transactoin, so we will send '0'

                            case 2: we have just sell, now we will buy (short selling)
                                take = -price[i] + solve(i + 1, k - 1, 0, price);  -> here at this point we just buy means we will have to subtract this value into our profit and also, one transaction is completed & now we can strat fresh one, this is why we are sending '0'

                            case 3: We can start fresh transaction (buy -> sell |OR| Sell -> buy) -> and we will be needing max among all..

                                take = max(
                                    -price[i] + solve(i + 1, k, 1, prices),        // normal transaction
                                    +price[i] + solve(i + 1, k, 2, prices)        // short selling
                                );   // take maximum among both the transaction.


                    return max(take, dontTake);

    // This falls into TLE: TC: O(2^n) exponentially
        - Memoization the solution, as it's overlapping..
            DP State:
                i, k, _case
                    i = (0, n)
                    k = (0, k)
                    case = (0, 2)

        // Complexity:
            - TC: O(n * k)
            - SC: O(n * k)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization Solution:
class Solution {
private: 
    typedef long long ll;
    vector<vector<vector<ll>>> t;
    ll solve(int i, int k, int _case, vector<int> &prices) {
        // Base case:
        if(i >= prices.size()) { // out of bound, item exhausted
            if(_case == 0) {    // all transaction is done, we are in fresh transaction
                return 0;   // nothing needed, just return '0'
            } else {    // (case == 1 || 2 )transaction is pending, & we got out of index -> we need to return invalid value
                return INT_MIN; // invalid transaction
            }
        }

        // Check in memo-table:
        if(t[i][k][_case] != -1) {
            return t[i][k][_case];
        }

        // Decision Tree:
        // Do-Nothing:
        ll dontTake = solve(i + 1, k, _case, prices);   // Option -> skip

        // Take action:
        ll take = INT_MIN;
        if(k > 0) { // if we left with transactions:
            if(_case == 1) { 
                // normal transaction (buy -> "sell")
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            } else if(_case == 2) {  
                // Short selling (sell -> "buy")
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            } else {   
                 // Fresh transaction: ("buy" -> sell |OR| "sell" -> buy) take maximum among all..
                take = max(
                    -prices[i] + solve(i + 1, k, 1, prices),     // normal transaction 
                    prices[i] + solve(i + 1, k, 2, prices)     // short-sell
                );
            }
        }

        return t[i][k][_case] = max(take, dontTake);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        t.resize(n + 1, vector<vector<ll>> (k + 1, vector<ll> (3, -1)));

        return solve(0, k, 0, prices);  // start with fresh transaction
    }
};


// Recursive Solution:
class Solution {
private: 
    typedef long long ll;
    ll solve(int i, int k, int _case, vector<int> &prices) {
        // Base case:
        if(i >= prices.size()) { // out of bound, item exhausted
            if(_case == 0) {    // all transaction is done, we are in fresh transaction
                return 0;   // nothing needed, just return '0'
            } else {    // (case == 1 || 2 )transaction is pending, & we got out of index -> we need to return invalid value
                return INT_MIN; // invalid transaction
            }
        }

        // Decision Tree:
        // Do-Nothing:
        ll dontTake = solve(i + 1, k, _case, prices);   // Option -> skip

        // Take action:
        ll take = INT_MIN;
        if(k > 0) { // if we left with transactions:
            if(_case == 1) { 
                // normal transaction (buy -> "sell")
                take = prices[i] + solve(i + 1, k - 1, 0, prices);
            } else if(_case == 2) {  
                // Short selling (sell -> "buy")
                take = -prices[i] + solve(i + 1, k - 1, 0, prices);
            } else {   
                 // Fresh transaction: ("buy" -> sell |OR| "sell" -> buy) take maximum among all..
                take = max(
                    -prices[i] + solve(i + 1, k, 1, prices),     // normal transaction 
                    prices[i] + solve(i + 1, k, 2, prices)     // short-sell
                );
            }
        }

        return max(take, dontTake);
    }
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();

        return solve(0, k, 0, prices);  // start with fresh transaction
    }
};