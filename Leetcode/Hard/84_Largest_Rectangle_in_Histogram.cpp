/*

//  84. Largest Rectangle in Histogram


//  Problem Statement: 
    - Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
 
// Example:
    Example 1:
        Input: heights = [2,1,5,6,2,3]
        Output: 10
        Explanation: The above is a histogram where width of each bar is 1.
        The largest rectangle is shown in the red area, which has an area = 10 units.

    Example 2:
        Input: heights = [2,4]
        Output: 4



// Observations: 
    - Given heights:
        - width of every cell is 1 & we are given height of every cell has height[i]
        - we have to return the largest rectangle in the histogram.

    // BruteForce Approach:

            // Example:
                             ___
                         ___| 6 |
                        | 5 |   |
                        |   |   |    ___
                 ___    |   |   |___| 3 |
                | 2 |___|   |   | 2 |   |
                |   | 1 |   |   |   |   |
                ---------------------------
                        <------->
                            b = 2
                            h = 5
                            area = 10


        - For every index i:
            - Try to extend left side, until a smaller height blocks us.
            - Try to extend right side, until a smaller height blocks us.
            - every index width has size = 1
            - and find width by (right - left + 1)
            - And find area by area = height[i] * width.
        
    // Optimizations:
        - For every index[i]: 
            - We compute the smallest_left blockage
            - We compute the smallest_right Blockage
            - and then computing every index 'i',
            - If we somehow already calculate the left & right somewhere, & use these in O(1) the our solution optimizes from O(n^2) to O(n)

            // Left Blockage:

                             ___
                         ___| 6 |
                        | 5 |   |
                        |   |   |    ___
                 ___    |   |   |___| 3 |
                | 2 |___|   |   | 2 |   |
            ____|   | 1 |   |   |   |   |____________
                  0   1   2   3   4   5 -> index

                for '2' left_blockage = 0th idx     ->      nothing behind
                for '1' left_blockage = 0th idx     ->      greater value behind, so we keep moving till we not find any lesser value, if nothing, means we will reach till 0th idx.
                for '5' left_blockage = 1st idx     ->      lesser value behind, so its 1st idx
                for '6' left_blockage = 2nd idx     ->      lesser value behind, so its 2nd idx
                for '2' left_blockage = 1st idx     ->      greater value behind, so will keep moving till we not find lesser value, which is exist on 1st index.
                for '3' left_blockage = 4th index   ->      lesser value behind, so it's 4th idx.

            - If we observe it carefully:
                - If have previous value as lesser, we assume that index as our blockage.
                - If we have previous grater value, we keep going backwords till we not find any lesser value & keep their index as our blockage..

                -> IF we observe carefully:
                    - We keep moving till the values are increasing, means previous values is smaller than current.
                    - Once we get some decreasing value, we keep moving backwords till se don't have grater value previous.
                    - This Basic observations gives us hints to use stack DS for this particular operations..

                - If we use Stack:
                    - For previous value: we can track it with stack top()
                    - If top is lesser value, we will keep their value index as our blockage
                    - If top is grater value, we will keep iterating backword till we not find any lesser value & keep that value index as our blockage..

                - So Stack will help us to Build this left Blockage
                - Also, if you observe more, we only store the increasing values, if any decreasing value occur, we keep back to the original value..


            // Right Blockage:
                - Similarly we will iterate from n - 1 to 0: 
                - And keep stack..
                - And perfrom the above steps in opposite manner.


            // Complexity:
                - TC: O(n)
                        left = O(n) + O(n) one for iterations, and other for stack
                        right = O(n) + O(n) one for iterations, and other for stack.
                        O(n) for iterating in heights[i] and building solution
                        Overall O(4*n) => O(n)

                - SC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // Build Left Blockage:
        vector<int> left(n, 0);
        stack<int> st;  // this will store the index, not value

        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();   // remove till we not find the blockage
            }

            if(st.empty()) {    // if stack has no value:
                left[i] = 0;    // 0th index is our blockage
            } else {
                left[i] = st.top() + 1;     // the blockage index + 1, because this will give us that index as barrier, means it's should not be incldued.
            }

            st.push(i);     // last push current index in stack.
        }

        while(!st.empty()) st.pop();    // clean stack

        // Find Right blockage:
        vector<int> right(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) {
                right[i] = n - 1;
            } else {
                right[i] = st.top() - 1;    // the blockage index - 1, because this will gives us the index barrier, means it's should not be included..
            }

            st.push(i); // last push current index in stack.
        }

        // Last calculate Area:
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            // Extend right until any smaller value blocks us:
            int l = left[i];
            
            // Extend right until any smaller value blocks us:
            int r = right[i];

            // Now find Breadth & calculate area:
            int width = r - l + 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;        
    }
};


// BruteForce Solution:
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            // Extend right until any smaller value blocks us:
            int left = i;
            while(left - 1 >= 0 && heights[left - 1] >= heights[i]) left--;   // move left pointer
            
            // Extend right until any smaller value blocks us:
            int right = i;
            while(right + 1 <= n - 1 && heights[right + 1] >= heights[i]) right++;    // move right pointer

            // Now find Breadth & calculate area:
            int width = right - left + 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;        
    }
};