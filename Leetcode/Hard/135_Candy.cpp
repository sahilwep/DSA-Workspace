/*

//  135. Candy


//  Problem Statement: 
    -> There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
    -> You are giving candies to these children subjected to the following requirements:
        -> Each child must have at least one candy.
        -> Children with a higher rating get more candies than their neighbors.
    -> Return the minimum number of candies you need to have to distribute the candies to the children.
    

// Example: 
    Example 1:
        Input: ratings = [1,0,2]
        Output: 5
        Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

    Example 2:
        Input: ratings = [1,2,2]
        Output: 4
        Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
        The third child gets 1 candy because it satisfies the above two conditions.


// Observations: 
    -> If we carefully observe the examples, we have to look for the strictly increasing or strictly decreeing value
    -> Alternatively we can say prefix sum for strictly increasing & suffix sum for strictly decreeing..
    -> Compute the prefix & suffix
    -> Compute our answer from getting maximum from both of them for every index & build sum...

// Complexity: 
    -> TC: O(logN)
    -> SC: O(1)
    
*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        // Compute prefix Sum:
        vector<int> pref(n, 1);
        for(int i = 1; i < n; i++) {
            if(ratings[i] > ratings[i - 1]) {
                pref[i] = pref[i-1] + 1;
            }
        }
        
        // Compute Suffix Sum:
        vector<int> suff(n, 1);
        for(int i = n - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i+1]) {
                suff[i] = suff[i + 1] + 1;
            }
        }

        // Compute the maximum sums: 
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += max(suff[i], pref[i]);
        }

        return sum;
    }
};
