/*

//  3195. Find the Minimum Area to Cover All Ones I


//  Problem Statement: 
    -> You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
    -> Return the minimum possible area of the rectangle.

 
// Example: 
    Example 1:
        Input: grid = [[0,1,0],[1,0,1]]
        Output: 6
        Explanation: The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.

    Example 2:
        Input: grid = [[1,0],[0,0]]
        Output: 1
        Explanation: The smallest rectangle has both height and width 1, so its area is 1 * 1 = 1.

 
// Observation:
    -> 
    -> For rectangle, try to find the 4 points for every '1'
        -> column: {minLeft, maxRight}
        -> row: {minTop, maxBottom}

    -> At last simply compute the area of rectangle:
        -> Area: (maxRight - minLeft + 1) * (maxBottom - minTop + 1)

        
// Complexity:
    -> TC: O(n * m)
    -> SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        // Column:
        int colMinLeft = INT_MAX;
        int colMaxRight = INT_MIN;

        // Row:
        int rowMinTop = INT_MAX;
        int rowMaxBottom = INT_MIN;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    int row = i;
                    int col = j;

                    // Store the minimum size for rectangle:
                    rowMinTop = min(row, rowMinTop);
                    rowMaxBottom = max(row, rowMaxBottom);

                    colMinLeft = min(col, colMinLeft);
                    colMaxRight = max(col, colMaxRight);
                }
            }
        }
        
        if(rowMinTop == INT_MAX || rowMaxBottom == INT_MIN || colMinLeft == INT_MAX || colMaxRight == INT_MIN) return 0;

        int length = rowMaxBottom - rowMinTop + 1;
        int breadth = colMaxRight - colMinLeft + 1;
        int area = length * breadth;
        
        return area;
    }
};