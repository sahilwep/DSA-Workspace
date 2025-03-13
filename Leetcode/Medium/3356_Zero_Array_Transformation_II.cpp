/*

// Leetcode: 3356. Zero Array Transformation II 


//  Problem Statement: 
    -> You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, val[i]].
    -> Each queries[i] represents the following action on nums:
        -> Decrement the value at each index in the range [li, ri] in nums by at most val[i].
        -> The amount by which each value is decremented can be chosen independently for each index.
    -> A Zero Array is an array with all its elements equal to 0.
    -> Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

 
// Example: 

    Example 1:
        Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
        Output: 2
        Explanation:
            For i = 0 (l = 0, r = 2, val = 1):
                Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
                The array will become [1, 0, 1].
            For i = 1 (l = 0, r = 2, val = 1):
                Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
                The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.

    Example 2:
        Input: nums = [4,3,2,1], queries = [[1,3,2],[0,2,1]]
        Output: -1
        Explanation:
                For i = 0 (l = 1, r = 3, val = 2):
                    Decrement values at indices [1, 2, 3] by [2, 2, 1] respectively.
                    The array will become [4, 1, 0, 0].
                For i = 1 (l = 0, r = 2, val = 1):
                    Decrement values at indices [0, 1, 2] by [1, 1, 0] respectively.
                    The array will become [3, 0, 0, 0], which is not a Zero Array.

        

// Observations: 
    -> Given an array of integer of length n
    -> given queries[i] = {l[i], r[i], val[i]}
    -> Each queries[i] represents the following actions on nums:
            -> decrement the value at each index in the range {l[i] r[i]} in nums bt AT MOST val[i]
            -> The amount by which each value decremented can be choosen independently.
    
    -> Return the minimum possible non-negative value of 'k', such that after processing the first 'k' queries in sequence, nums become a zero. 
    -> if no such k query exit return '-1'

    // BruteForce Solution: 
        -> Apply all the given conditions & given constrains with stdrightforword implementations.
        // Complexity:
            -> TC: O(Q * n)
            -> SC: (1)

    // Good Solution:
        -> We need to perform range update.
        -> With using Difference Array technique we can perfrom all query update in O(n) time.
        -> Now we will iterate in every query & perform difference array technique to only that range times.
        -> And once all the value become '0', we will return that number of query.
        
        // Complexity:
            -> TC: O(Q * (Q + n))
            -> SC: O(n)

    
    // Better Solution:
        -> With Difference Array technique, we will use binary search.
        -> We can use binary search, because in question they were given that "after processing first k queries in sequence.." which directly saying queries are in order..
        -> we will query only those portions query with comparing the results of difference array technique & we can save our time to not query all the queries.

        
        // Complexity: 
            -> TC: O(log(Q) * (Q + n))
            -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Better Solution:

class Solution {
private:
    int n, Q;
    bool checkWithDiffArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        // Generate difference value from given query:
        for(int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            // Array Difference Technique:
            diff[l] += x;
            if(r + 1 < n) {
                diff[r + 1] -= x;
            }
        }

        // Now Generate Commutative Sum from difference array:
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;

            // if nums[i] still positive after subtracting 'k' queries values: -> return false then, we can't form zero array.
            if(nums[i] - diff[i] > 0) {
                return false;
            }
        }

        return true;    // else return true, means we can form '0' array.
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) { // TC: O(log(Q) * ( Q + n))
        n = nums.size();
        Q = queries.size();

        // Case: if all the values of nums is already '0'
        // lambda function which will helps us to compare the value:
        auto lambda = [] (int x) {
            return (x == 0);    // compare x with '0'
        };

        if(all_of(begin(nums), end(nums), lambda)) {  // STL CPP function to check nums have '0' or not with passing lambda
            return 0;   // no queries required, because all the values of nums is already '0'
        } 
        
        // Using Binary Search:
        int l = 0;      // first index of query
        int r = Q - 1;  // last index of query
        int k = -1;     // kth value which we have to return:

        while(l <= r) {     // TC: O(log(Q))
            int mid = l + (r - l) / 2;

            if(checkWithDiffArrayTeq(nums, queries, mid) == true) { // TC: O(Q + n)
                k = mid + 1;    // possible answer
                // Now decrease the size, by set last value as "mid - 1" & explore in left side
                r = mid - 1;    
            }else { // if result is false: means we need further more queries.
                l = mid + 1;    // increase the range of mid
            }
        }

        return k;
    }
};

// Good Solution:
class Solution {
private:
    int n, Q;
    bool checkWithDiffArrayTeq(vector<int>& nums, vector<vector<int>>& queries, int k) {
        vector<int> diff(n, 0);

        // Generate difference value from given query:
        for(int i = 0; i <= k; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = queries[i][2];

            // Difference Array Technique:
            diff[l] += x;
            if(r + 1 < n) {
                diff[r + 1] -= x;
            }
        }

        // Now Generate Commutative Sum from Difference array:
        int cumSum = 0;
        for(int i = 0; i < n; i++) {
            cumSum += diff[i];

            diff[i] = cumSum;

            // if nums[i] still positive after subtracting 'k' queries values: -> return false then, we can't form zero array.
            if(nums[i] - diff[i] > 0) {
                return false;
            }
        }

        return true;    // else return true, means we can form '0' array.
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n = nums.size();
        Q = queries.size();

        // Case: if all the values of nums is already '0'
        // lambda function which will helps us to compare the value:
        auto lambda = [] (int x) {
            return (x == 0);    // compare x with '0'
        };

        if(all_of(begin(nums), end(nums), lambda)) {  // STL CPP function to check nums have '0' or not with passing lambda
            return 0;   // no queries required, because all the values of nums is already '0'
        } 


        for(int i = 0; i < Q; i++) {
            if(checkWithDiffArrayTeq(nums, queries, i) == true) {
                return i + 1;    // return i + 1, because of 1-based indexing.
            }
        }

        return -1;  // else return -1, because not possible.
    }
};

// Bruteforce Solution:
class Solution {
private:
    bool allZeroes(vector<int> &nums) { // TC: O(n)
        for(auto &it: nums) {
            if(it != 0) return 0;
        }
        return 1;
    }
    void decrementRange(vector<int> &nums, int l, int r, int val) {  // decrement by 1: TC: O(n)
        for(int i = l; i <= r; i++) {
            nums[i] -= val;
        }
        // Now for all negative value in range (l, r): make them '0'
        for(int i = l; i <= r; i++) {
            if(nums[i] < 0) nums[i] = 0;
        }
    }
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        
        // Edge case: initially if given nums is zero array:
        if(allZeroes(nums)) return 0;

        int qSize = queries.size();

        int k = 0;
        for(int i = 0; i < qSize; i++) {    // O(Q) * (O(n) + O(n)) => O(Q * n)
            int l = queries[i][0];
            int r = queries[i][1];
            int val = queries[i][2];

            // Now perform queries:
            decrementRange(nums, l, r, val);     // O(n)
            k++;

            // Last check if nums become zero or not?
            if(allZeroes(nums)) return k;   // O(n)
        }

        // last check out of the Scope:
        for(auto &it: nums) cout << it << " ";
        cout << endl;
        return (allZeroes(nums)) ? k : -1;
    }
};