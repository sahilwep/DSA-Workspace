/*

//  11. Container With Most Water


//  Problem Statement: 
    -> You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
    -> Find two lines that together with the x-axis form a container, such that the container contains the most water.
    -> Return the maximum amount of water a container can store.
    -> Notice that you may not slant the container.

//  Example: 

    Example 1:
        Input: height = [1,8,6,2,5,4,8,3,7]
        Output: 49
        Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

    Example 2:
        Input: height = [1,1]
        Output: 1


// Observations: 
    -> given an integer array height of length n,
    -> there are n vertical lines, ith line represent height[i]
    -> find two lines together on the x-axis from a container, such that the container contains the most water.
    -> Water capacity = min(height[i], height[j]) * (j - i)

    // BruteForce Solution: 
        -> Use nested loop & explore all the possibility.

        // Complexity: 
            -> TC: O(n^2)
            -> SC: O(1)


    // Efficient: Two pointer approach
        -> First pointer at 0
        -> Second pointer at n-1
        -> move both pointer to each other, until we not explore all the possibility
        -> Get the minimum height from both the pointers & get the distance b/w them & compute the water hold capacity..   

        // Complexity: 
            -> TC: O(n)
            -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// BruteForce Solution: 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int maxCap = 0;;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int maxH = min(height[i], height[j]);
                int len = j - i;
                int cap = maxH * len;

                maxCap = max(maxCap, cap);
            }
        }


        return maxCap;
    }
};


// Efficient Solution: 
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int i = 0;
        int j = n - 1;
        int maxCap = 0;
        while(i < j) {
            // Get height, length, & compute capacity:
            int maxHeight = min(height[i], height[j]);
            int length = j - i;
            int cap = maxHeight * length;

            // Get the maximum capacity among all the possible cases:
            maxCap = max(maxCap, cap);

            // Move pointer, to find longer height:
            if(height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }


        return maxCap;
    }
};