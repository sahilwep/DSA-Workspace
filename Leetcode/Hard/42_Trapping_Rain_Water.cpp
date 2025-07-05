/*

//  42. Trapping Rain Water


//  Problem Statement: 
    -> Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.


// Example: 

    Example 1:
        Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
        Output: 6
        Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

    Example 2:
        Input: height = [4,2,0,3,2,5]
        Output: 9

 

// Observations: 
    -> After the rain, we need to count how much water can hold b/w the given heights.
    -> each cell has 1 unit size


// Approach: 
    -> Compute prefix min among prefix & suffix array.
    -> Subtract the given array size from prefix & suffix max.
    -> Add total, & that will be our answer
    -> Visualizations.


        0 1 0 2 1 0 1 3 2 1 2 1     -> Array
        0 1 2 3 4 5 6 6 7 8 9 10    -> array index.
        
        0 1 1 2 2 2 2 3 3 3 3 3     -> left to right => prefix max
        3 3 3 3 3 3 3 3 2 2 2 1     -> Right to left => suffix max


        0 0 1 0 1 2 1 0 0 1 0 0     -> get the min from (prefix-max, suffix-max) then subtract given array => get total hold on that block.


// Complexity:
    -> TC: O(N)
    -> SC: O(N)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Compute Prefix Max:
        vector<int> prefMax(n);
        prefMax[0] = height[0];
        for(int i = 1; i < n; i++) prefMax[i] = max(prefMax[i-1], height[i]);


        // Compute Suffix Max:
        vector<int> suffMax(n);
        suffMax[n-1] = height[n-1];
        for(int i = n - 2; i >= 0; i--) suffMax[i] = max(suffMax[i+1], height[i]);


        // Build answer by getting minimum from 
        int canHoldWater = 0;
        for(int i = 0; i < n; i++) {
            canHoldWater += min(prefMax[i], suffMax[i]) - height[i];
        }

        return canHoldWater;
    }
};