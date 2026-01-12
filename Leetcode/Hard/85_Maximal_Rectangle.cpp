/*

//  85. Maximal Rectangle


//  Problem Statement: 
    - Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
 

// Example:
    Example 1:
        Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
        Output: 6
        Explanation: The maximal rectangle is shown in the above picture.

    Example 2:
        Input: matrix = [["0"]]
        Output: 0

    Example 3:
        Input: matrix = [["1"]]
        Output: 1

// Observations:
    - We are given 2D grid where we have 1's and 0's
    - We need to return the maximum area of rectangle where it can be formed usign 1's


    // Key Observations:
        -> If we observe this carefully:

                [1, 0, 1, 0, 0]
                [1, 0, 1, 1, 1]
                [1, 1, 1, 1, 1]
                [1, 0, 0, 1, 0]

            -> lets observe this in 1D format:
                    
                    [1, 0, 1, 1, 0, 1, 1, 1, 1, 0]

                - If we have to find the largest rectangle, then how we find that:

                    [1, 0, 1, 1, 0, 1, 1, 1, 1, 0]      ---> let's say height of every cell is 1
                    [1] 0 [2  2] 0 [4  4  4  4] 0       ---> Here we have rectangle width of connected rectangle.
                                       |
                                       |
                        for this '1', it has 1 in his left & 2 in his right
                        Total width is 4, height = 1
                        area = 4 * 1 = 2

            -> If we have something, like 1D array with height differ than '1'

                    [1, 0, 2, 3, 0, 2, 2, 2, 2, 0]  -> Let's say we have different height this time.
                    [1] 0 [4][3] 0 [8  8  8  8] 0   -> width of every cells, it can grow in left side & right side
                           |
                           |
                        for this '2' it has '3' in his right, so it can grow with '2' with staying in limit.
                        So total width for this is: 2 + 2 = 4
                        area = 4 * 2 = 8

                Similarly:
                    [1, 0, 2, 3, 0, 2, 2, 2, 2, 0]  -> Let's say we have different height this time.
                    [1] 0 [4][3] 0 [8  8  8  8] 0   -> width of every cells, it can grow in left side & right side
                                       |
                                       |
                        for this '2' it can grow left side with same height '2' and adds 2 & right with '2' and adds '4', & total includeing with them is 8
                        So, total width for this is: 2 + 2 + 2 + 2 = 8
                        area = 2 * 8 = 16

            -> So If we have something like heights, then we can easily find the largest rectangle:
                - How we can get height:
                    -> for every row of grid:
                        - we can compute height very easily:
                            - create a vector height with default value '0'
                            - Whenever you have '1', just add that jth index of height with '1'
                            - If you have '0', then you can reset for later explorations:   

                            Grid:                               height:
                                [1, 0, 1, 0, 0]                     [1, 0, 1, 0, 0]
                                [1, 0, 1, 1, 1]                     [2, 0, 2, 1, 1]
                                [1, 1, 1, 1, 1]                     [3, 1, 3, 2, 2]
                                [1, 0, 0, 1, 0]                     [4, 0, 0, 0, 0]

                 
                                If we extract row 2: 
                                
                                                height: [3, 1, 3, 2, 2]

                                                    From this We can easily find the rectangle:

                                                        [3, 1, 3, 2, 2]     -> heights
                                                         3  5  3  6  6      -> width for every cell, that it can extends in left & right

                - So after every iterations of row, when we build our heights, 
                - we can easily compute our maximum area by using this above intrusion.
                
                // Approach:    
                    - Initialize a height of length m with '0' as default value:
                    - for every i:
                        for every j:
                            if grid[i][j] is 1: height[j]++     // to increment the above incrementing height
                            else height[j] = 0;                 // reseting the above incrementing height.
                        When we build our height at every level:
                            we can try to find the longest rectangle from that level:
                            

                    // How to find the longest rectangle on every height: 
                        - for every height[i], we will find:
                            - left side blockage
                            - right side blockage
                            - Then we can build our current height[i]
                        
                        - It's more like:
                            - For every index i:
                                - Try to extend left side, until a smaller height blocks us.
                                - Try to extend right side, until a smaller height blocks us.
                                - every index width has size = 1
                                - and find width by (right - left + 1)
                                - And find area by area = height[i] * width.
                            - This will take somewhere: O(m^2), because for every 'i', we check in left & right side whole.
                            - It's bruteforce approach to find the largest rectangle.
                        
                        - This is the exact problem: LC: 84. Largest Rectangle in Histogram
                        - Solution: https://github.com/sahilwep/DSA-Workspace/blob/309f5589d4ace8ba6a8eebb501a58d93ceabf588/Leetcode/Hard/84_Largest_Rectangle_in_Histogram.cpp
                        - The solution show how we have optimized the problem of finding Largest rectangle in histogram in O(m) time using monotonic stack.


        // Efficient Solution Complexity:
            - TC: O(n * (m + m)) => O(n * m)
            - SC: O(m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {    // largest rectangle in histogram
        int n = heights.size();

        // find left:
        vector<int> left(n, 0);
        stack<int> st;
        for(int i = 0; i < n; i++) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) left[i] = 0;
            else left[i] = st.top() + 1;
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // find Right:
        vector<int> right(n, 0);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            if(st.empty()) right[i] = n - 1;
            else right[i] = st.top() - 1;
            st.push(i);
        }

        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            int area = (right[i] - left[i] + 1) * heights[i];
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {    // TC: O(n * m)
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(m, 0);
        for(int i = 0; i < n; i++) {    // TC: O(n * m)
            for(int j = 0; j < m; j++) {    // TC: O(m)
                if(matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {    // if we have '0', means the above height will be invalid for the current heights[i], this is why we have set it as '0'
                    heights[j] = 0;
                }
            }
            int currArea = largestRectangleArea(heights);   // TC: O(m)
            maxArea = max(currArea, maxArea);
        }


        int currArea = largestRectangleArea(heights);
        maxArea = max(currArea, maxArea);

        return maxArea;
    }
};



// BruteForce Solution:
class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {    // O(m^2)
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
public:
    int maximalRectangle(vector<vector<char>>& matrix) {    // TC: O(n * m^2)
        int n = matrix.size();
        int m = matrix[0].size();

        int maxArea = 0;
        vector<int> heights(m, 0);
        for(int i = 0; i < n; i++) {    // TC: O(n * m^2)
            for(int j = 0; j < m; j++) {    // TC: O(m)
                if(matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {    // if we have '0', means the above height will be invalid for the current heights[i], this is why we have set it as '0'
                    heights[j] = 0;
                }
            }
            // for(auto &it: heights) cout << it << " ";
            // cout << endl;
            int currArea = largestRectangleArea(heights);   // TC: O(m^2)
            maxArea = max(currArea, maxArea);
        }


        int currArea = largestRectangleArea(heights);
        maxArea = max(currArea, maxArea);

        return maxArea;
    }
};