/*

//  2965. Find Missing and Repeated Values


//  Problem Statement: 
    -> You are given a 0-indexed 2D integer matrix grid of size n * n with values in the range [1, n2]. Each integer appears exactly once except a which appears twice and b which is missing. The task is to find the repeating and missing numbers a and b.
    -> Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b.

// Example:

    Example 1:
        Input: grid = [[1,3],[2,2]]
        Output: [2,4]
        Explanation: Number 2 is repeated and number 4 is missing so the answer is [2,4].

    Example 2:
        Input: grid = [[9,1,7],[8,9,2],[3,4,6]]
        Output: [9,5]
        Explanation: Number 9 is repeated and number 5 is missing so the answer is [9,5].


// Observations: 
    -> We just have to count the frequency of the element.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<int> times(n*n + 1, 0);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < grid[i].size(); j++) {
                times[grid[i][j]]++;
            }
        }

        int repeated, missing;
        for(int i = 1; i < n*n + 1; i++) {
            if(times[i] == 0) missing = i;
            if(times[i] == 2) repeated = i;
        }

        return {repeated, missing};
    }
};