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


*/

#include<bits/stdc++.h>
using namespace std;

// Bruteforce Solution:
class Solution_BruteForce{
private:
    bool isSpecial(vector<int> &nums, int from, int to){
        if(to - from == 0) return 1;    // consider true for single element

        for(int i=from+1;i<=to;i++){
            // if two consecutive element has same parity: return flase
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