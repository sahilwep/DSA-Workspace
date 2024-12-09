/*

//  3152. Special Array II

//  Problem Statement: 
    * An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    * You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [from-i, toi] 
    * your task is to check that subarray nums[from-i..toi] is special or not.

    * Return an array of booleans answer such that answer[i] is true if nums[from-i..toi] is special.

// Example:

    Example 1:
        Input: nums = [3,4,1,2,6], queries = [[0,4]]
        Output: [false]
            Explanation: The subarray is [3,4,1,2,6]. 2 and 6 are both even.

    Example 2:
        Input: nums = [4,3,1,6], queries = [[0,2],[2,3]]
        Output: [false,true]
            Explanation:
                * The subarray is [4,3,1]. 3 and 1 are both odd. So the answer to this query is false.
                * The subarray is [1,6]. There is only one pair: (1,6) and it contains numbers with different parity. So the answer to this query is true.

    
//  Approach:
    // Bruteforce Approach:
        -> Query every with given from & to range & store the solution..
        -> Complexity: 
            -> TC: O(nums.size()*q.size())



    // Efficient Approach: 
        * The goal is to determine if every consecutive pair of elements in the given subarray satisfies the condition of having opposite parity (i.e., one is even and the other is odd).


        * Example:
                    nums = [3,4,1,2,6,3,4,5,8,4,2],     queries = [[0,4],[0,1],[4,7]]

                    let's say given range is: 4, 7 => [6,3,4,5]
                            -> There are total 4 valid pairs
                            -> If we subtract the given query range: 7 - 4 + 1(because of '0' based index) = '4'
                            -> We need to build prefix array in a way so that it can have exactly '4' valid values in (4, 7) subarray range.


                    Now, when we querying the valid pair from prefixSum, we need '4' pairs, if we don't get '4' pairs, our result is false

                    -> Let's build prefix Array:
                            -> values that having diffent consecutive parity -> add 1 to it
                            -> values that having same consecutive parity -> get the previous parity..
                            -> Start filling with '0', because first value is always unique & true for the condition
                                nums = [3,4,1,2,6,3,4,5,8,4,2]
                                parity[] = {same size as nums},    parity[0] = [0]

                                i = 1:  nums[1] = 4
                                    parity[i] = parity[i-1] // initialize the value, with previous parity value
                                    // Check the given condition, if it's follow:
                                    if ((nums[i - 1] % 2 == 0 && nums[i] % 2 != 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 == 0)) 
                                        parity[i]++;    // increment the parity[i] value
                                    // Else, don't do anything keep it as it is.
                                        parity[0, 1]
                                        
                                i = 2:  nums[2] = 1
                                    parity[i] = parity[i-1] // initialize the value, with previous parity value
                                    // Check the given condition, if it's follow:
                                    if ((nums[i - 1] % 2 == 0 && nums[i] % 2 != 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 == 0)) 
                                        parity[i]++;    // increment the parity[i] value
                                    // Else, don't do anything keep it as it is.
                                        parity[0, 1, 2]
                                        
                                i = 3:  nums[3] = 2
                                    parity[i] = parity[i-1] // initialize the value, with previous parity value
                                    // Check the given condition, if it's follow:
                                    if ((nums[i - 1] % 2 == 0 && nums[i] % 2 != 0) || (nums[i - 1] % 2 != 0 && nums[i] % 2 == 0)) 
                                        parity[i]++;    // increment the parity[i] value
                                    // Else, don't do anything keep it as it is.
                                        parity[0, 1, 2, 3]
                                    
                                ...
                                ...

                                        parity = [0, 1, 2, 3, 3, 4, 5, 6, 7, 7, 7]
                                        index     0  1  2  3  4  5  6  7  8  9  10
                                
                                // Now Query:

                                    queries = [[0,4],[0,1],[4,7]]
                                            
                                            range[0,4]
                                                left = queries[0][0]
                                                right = queries[0][1]
                                                totalPair: right - left
                                                totalPair: 4 - 0 = 4

                                                validPair: parity[right] - parity[left]
                                                validPair: 3 - 0 = 3

                                                    totalPair != validPair => false

                                            range[1, 0]
                                                left = queries[1][0]
                                                right = queries[1][1]
                                                totalPair: right - left
                                                totalPair: 1 - 0 = 1

                                                validPair: parity[right] - parity[left]
                                                validPair: 1 - 1 = 1

                                                    totalPair == validPair => true

                                            range[4, 7]
                                                left = queries[2][0]
                                                right = queries[2][1]
                                                totalPair: right - left
                                                totalPair: 7 - 4 = 3

                                                validPair: parity[right] - parity[left]
                                                validPair: 6 - 3 = 3

                                                    totalPair == validPair => true

                                    res = [false, true, true] -> This give us answer..

        * Implementation:
            1. Prefix Sum Array for Valid Pairs:
                * Build a prefix sum array, prefSum, where:
                    * prefSum[i] counts the number of valid consecutive pairs (even-odd or odd-even) from the start of the array up to index i.
                * This allows quick computation of the number of valid pairs in any range [left, right] using the formula:
                    validPair=prefSum[right]−prefSum[left]

            2. Process Queries:
                * For each query [left, right], determine the total number of consecutive pairs in the range, totalPair = right - left.
                * Compare validPair with totalPair:
                    * If validPair == totalPair, all consecutive pairs in the subarray satisfy the condition.
                    * Otherwise, they do not.

        * Complexity: 
            -> TC: O(n + k)
                -> Where n = nums.size(), k = queries.size()


*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution:
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefSum(n, 0); // Prefix sum array to store valid consecutive pairs

        // Step 1: Compute the prefix sum array
        for (int i = 1; i < n; i++) { // Start from index 1 since pairs involve two elements
            prefSum[i] = prefSum[i - 1]; // Carry forward the previous prefix sum

            // Check if the pair (nums[i-1], nums[i]) has opposite parity
            if ((nums[i - 1] % 2 == 0 && nums[i] % 2 != 0) || 
                (nums[i - 1] % 2 != 0 && nums[i] % 2 == 0)) {
                prefSum[i]++; // Increment for valid pair
            }
        }
        
        // Step 2: Process each query
        vector<bool> res;       // Result array to store whether each query range is "special"
        for (int i = 0; i < queries.size(); i++) {
            int left = queries[i][0];       // Starting index of the query range
            int right = queries[i][1];      // Ending index of the query range

            int totalPair = right - left;                       // Total number of consecutive pairs in the range
            int validPair = prefSum[right] - prefSum[left];     // Number of valid pairs in the range
            res.push_back(validPair == totalPair);              // Check if all consecutive pairs in the range are valid
        }

        return res;
    }
};


// Bruteforce Solution:
class Solution_BruteForce{
private:
    bool isSpecial(vector<int> &nums, int from, int to){
        if(to - from == 0) return 1;    // consider true for single element

        for(int i=from+1;i<=to;i++){
            // if two consecutive element has same parity: return false
            if(nums[i-1] % 2 == 0 && nums[i] % 2 == 0){
                return 0;
            }
            else if(nums[i-1] % 2 != 0 && nums[i] % 2 != 0){
                return 0;
            }
        }

        return 1;   // else return true
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        
        vector<bool> res;

        for(int i=0;i<queries.size();i++){
            int f = queries[i][0];
            int t = queries[i][1];
            res.push_back(isSpecial(nums, f , t));
        }

        return res;
    }
};