/*

//  1726. Tuple with Same Product


//  Problem Statement: 
    -> Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d where a, b, c, and d are elements of nums, and a != b != c != d.
 
// Example:

    Example 1:

        Input: nums = [2,3,4,6]
        Output: 8
        Explanation: There are 8 valid tuples:
        (2,6,3,4) , (2,6,4,3) , (6,2,3,4) , (6,2,4,3)
        (3,4,2,6) , (4,3,2,6) , (3,4,6,2) , (4,3,6,2)

    Example 2:

        Input: nums = [1,2,4,5,10]
        Output: 16
        Explanation: There are 16 valid tuples:
        (1,10,2,5) , (1,10,5,2) , (10,1,2,5) , (10,1,5,2)
        (2,5,1,10) , (2,5,10,1) , (5,2,1,10) , (5,2,10,1)
        (2,10,4,5) , (2,10,5,4) , (10,2,4,5) , (10,2,5,4)
        (4,5,2,10) , (4,5,10,2) , (5,4,2,10) , (5,4,10,2)


// BruteForce: 
    -> Write the given conditions using nested n^4 loop.
    -> TC: O(n^4), This one also falls into TLE.


// Better Approach:
    -> Observations: 
            a * b = c * d

        
            If we observe mathematically:

                a > c
                a > d
                b > c 
                b > d

            or:

                a < c
                a < d
                b < c 
                b < d
                
                -> Then Condition not possible
                -> It should be balanced

        -> If we sort the given input array, then we can make such pairs where these conditions are possible
            Input: nums = [2,3,4,6]

                        [2, 3, 4, 6]
                         |        |
                         we can choose these pairs

                         [2, 3, 4, 6]
                         |  |
                         and these two pairs
                         
                         Now, These whole numbers of pairs will gives us true for given conditions.
                         
        -> In simple, we can use pointers approach, & try to find such pairs.

                         0         n-1
                         [2, 3, 4, 6]
                          |  |  |  |
                          i  k  l  j
                          -->    <--    and move this way.
        
        -> NOTE: k & l should not cross, so that we won't have any duplicates in our tuple.
    -> TC: O(n^4), This one also falls into TLE.


// Efficient: 
    -> Observations: 
        IF: a * b = c * d

            -> if we know a, b & c, then we can also find 'd' very easily..
            -> Because:
                        (a * b) / c = d
            
            -> Means we can only use 3 pointers & find our answer.

                         0         n-1
                         [2, 3, 4, 6]
                          |  |     |
                          i  k     j
                             -> 
            -> We can move 'k' forward and check the conditions..
            -> to store the result of previous operations, we need some type DS, which holds our value & gives us when it's needed in O(1), we can use unordered set..
    -> TC: O(n^3)

// Optimal:
    -> Observations: 

                [2, 3, 4, 6]
                 |  |  |  |

                 (2, 6) = 12
                 (3, 4) = 12

                -> we got two pairs which product is 12.
                -> and to form a tuple, we atleast need 2 pairs.
                -> We have two pairs & we need to choose 2, Combinations: 2c2 or nCr in simplified
                -> So, in simple, we will store the product of every two element somewhere in map, & later on we will check from map, how many pairs we have..
                -> Combinations formula: C(n,2) = 2!*(n−2)! * n!  ​= (n(n−1)​)/2
                -> And the product that comes only once were not allowed.
                -> So, we need to choose such pairs, whose product is greater or equal to 2 times.
                -> TC: O(n^2)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Optimal:
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();


        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                mp[nums[i] * nums[j]]++;    // process the product of every number possible
            }
        }

        // Now count the number of such combinations, whose product is greater or equal to 2:
        int tuples = 0;

        for(auto &it: mp) {
            int prod = it.first;
            int freq = it.second;

            tuples += (freq * (freq - 1)) / 2;
        }

        return tuples * 8;
    }
};


// Efficient:
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int tuples = 0;

        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                int product = nums[i] * nums[j];
                unordered_set<int> st;
                for(int k = i + 1; k < j; k++) {
                    if(product % nums[k] == 0) {    // it should be divisible
                        int dValue = product / nums[k];   // with this we can get 'l' index value.

                        // Check whether this 'd' exist in set or not?
                        if(st.count(dValue) == 1) tuples++;

                        st.insert(nums[k]); // insert this value, so that we can check this in further.
                    }
                }
            }
        }

        return tuples * 8;
    }
};


// Better:
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        sort(begin(nums), end(nums));

        int tuples = 0;

        for(int i = 0; i < n; i++) {
            for(int j = n - 1; j >= 0; j--) {
                for(int k = i + 1; k < j; k++) {
                    for(int l = j - 1; l > k; l--) {
                        int p1 = nums[i] * nums[j];
                        int p2 = nums[k] * nums[l];

                        if(p1 == p2) tuples++;
                    }
                }
            }
        }

        return tuples * 8;
    }
};


// BruteForce:
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();

        int tuples = 0;

        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                for(int k=0;k<n;k++) {
                    for(int l=k+1;l<n;l++) {
                        // Ignore the value cases:
                        if(i != k && i != l && j != k && j != l) {
                            int p1 = nums[i] * nums[j];
                            int p2 = nums[k] * nums[l];

                            if(p1 == p2) {
                                tuples++;
                            }
                        }
                    }
                }
            }
        }

        return (tuples / 2) * 8;
    }
};