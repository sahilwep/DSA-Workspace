/*

//  873. Length of Longest Fibonacci Subsequence


//  Problem Statement: 
    -> A sequence x1, x2, ..., xn is Fibonacci-like if:
        n >= 3
        xi + xi+1 == xi+2 for all i + 2 <= n

    -> Given a strictly increasing array arr of positive integers forming a sequence, return the length of the longest Fibonacci-like subsequence of arr. If one does not exist, return 0.
    -> A subsequence is derived from another sequence arr by deleting any number of elements (including none) from arr, without changing the order of the remaining elements. For example, [3, 5, 8] is a subsequence of [3, 4, 5, 6, 7, 8].

 
// Example: 

    Example 1:
        Input: arr = [1,2,3,4,5,6,7,8]
        Output: 5
        Explanation: The longest subsequence that is fibonacci-like: [1,2,3,5,8].

    Example 2:
        Input: arr = [1,3,7,11,12,14,18]
        Output: 3
        Explanation: The longest subsequence that is fibonacci-like: [1,11,12], [3,11,14] or [7,11,18].



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization Solution: 
class Solution {
private:
    int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp, vector<vector<int>> &t) {
        int target = arr[k] - arr[j];

        if(t[j][k] != -1) return t[j][k];

        // If we are able to find the target in map & it must be less than 'j'
        if(mp.count(target) == 1 && mp[target] < j) {
            int i = mp[target]; // make i which hold target value.

            // call i & j as k, to find next possible target.
            return t[j][k] = solve(i, j, arr, mp, t) + 1;    // + 1 because we have found 1 element.
        }

        return t[j][k] = 2;   // beacuse we are sure about 2 element that form fibonacci sequence.
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        vector<vector<int>>  t(n, vector<int> (n, -1));
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int max_length = 0;
        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp, t);

                if(length >= 3) {
                    max_length = max(length, max_length);
                }
            }
        }
        
        return max_length;
    }
};

// BruteForce Solution: 
class Solution {
private:
    int solve(int j, int k, vector<int> &arr, unordered_map<int, int> &mp) {
        int target = arr[k] - arr[j];

        // If we are able to find the target in map & it must be less than 'j'
        if(mp.count(target) == 1 && mp[target] < j) {
            int i = mp[target]; // make i which hold target value.

            // call i & j as k, to find next possible target.
            return solve(i, j, arr, mp) + 1;    // + 1 because we have found 1 element.
        }

        return 2;   // because we are sure about 2 element that form fibonacci sequence.
    }
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        int n = arr.size();

        unordered_map<int, int> mp;
        for(int i = 0; i < n; i++) {
            mp[arr[i]] = i;
        }

        int max_length = 0;
        for(int j = 1; j < n; j++) {
            for(int k = j + 1; k < n; k++) {
                int length = solve(j, k, arr, mp);

                if(length >= 3) {
                    max_length = max(length, max_length);
                }
            }
        }
        
        return max_length;
    }
};
