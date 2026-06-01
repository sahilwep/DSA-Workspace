/*

//  2144. Minimum Cost of Buying Candies With Discount


//  Problem Statement: 
    - A shop is selling candies at a discount. For every two candies sold, the shop gives a third candy for free.
    - The customer can choose any candy to take away for free as long as the cost of the chosen candy is less than or equal to the minimum cost of the two candies bought.
        - For example, if there are 4 candies with costs 1, 2, 3, and 4, and the customer buys candies with costs 2 and 3, they can take the candy with cost 1 for free, but not the candy with cost 4.
    - Given a 0-indexed integer array cost, where cost[i] denotes the cost of the ith candy, return the minimum cost of buying all the candies.

 
// Example:

    Example 1:
        Input: cost = [1,2,3]
        Output: 5
        Explanation: We buy the candies with costs 2 and 3, and take the candy with cost 1 for free.
        The total cost of buying all candies is 2 + 3 = 5. This is the only way we can buy the candies.
        Note that we cannot buy candies with costs 1 and 3, and then take the candy with cost 2 for free.
        The cost of the free candy has to be less than or equal to the minimum cost of the purchased candies.

    Example 2:
        Input: cost = [6,5,7,9,2,2]
        Output: 23
        Explanation: The way in which we can get the minimum cost is described below:
        - Buy candies with costs 9 and 7
        - Take the candy with cost 6 for free
        - We buy candies with costs 5 and 2
        - Take the last remaining candy with cost 2 for free
        Hence, the minimum cost to buy all candies is 9 + 7 + 5 + 2 = 23.

    Example 3:
        Input: cost = [5,5]
        Output: 10
        Explanation: Since there are only 2 candies, we buy both of them. There is not a third candy we can take for free.
        Hence, the minimum cost to buy all candies is 5 + 5 = 10.

// Observations:
    - One thing we are sure that we have to minimize the cost, and we will have to pick the max value, but the conditions says we only pick value that is lesser than the two picked candies.
    - So, let's say we will have something like:
            4 3 2 1 9 4 7 8 8
        - After sorting:
            1 2 3 4 4 7 8 8 9
            
        - Now choosing candies and rejecting lesser or equal to minimum choose candies:
        
                0     1   2    3    4   5    6   7   8/n-1th  -> index
                1    [2   3]   4   [4   7]   8  [8   9]
                |              |             |
                |              |            n-3
                |              n-6
                n-9

                These are the index, on which we have the candies we can reject..
                Because, for every pair or candies we can reject one candy
        
        - It's just we have to skip the n - 3, 6, 9,... values
        - then we can calculate the sum and the return our answer.



// Complexity:
    - TC: O(nlogn)
    - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();

        if(n <= 2)  return accumulate(begin(cost), end(cost), 0);
        
        // Now sort the given cost to select minimum as possible:
        vector<int> temp = cost;
        sort(begin(temp), end(temp));

        for(int i = n - 3; i >= 0; i -= 3) {
            temp[i] = 0;    // mark it as '0', so that we dont' include them in sum.
        }

        int ans = accumulate(begin(temp), end(temp), 0);   // get the sum

        return ans;
    }
};