/*

//  836. Rectangle Overlap


//  Problem Statement: 
    - An axis-aligned rectangle is represented as a list [x1, y1, x2, y2], where (x1, y1) is the coordinate of its bottom-left corner, and (x2, y2) is the coordinate of its top-right corner. Its top and bottom edges are parallel to the X-axis, and its left and right edges are parallel to the Y-axis.
    - Two rectangles overlap if the area of their intersection is positive. To be clear, two rectangles that only touch at the corner or edges do not overlap.
    - Given two axis-aligned rectangles rec1 and rec2, return true if they overlap, otherwise return false.

 
// Example:
    Example 1:
        Input: rec1 = [0,0,2,2], rec2 = [1,1,3,3]
        Output: true

    Example 2:
        Input: rec1 = [0,0,1,1], rec2 = [1,0,2,1]
        Output: false

    Example 3:
        Input: rec1 = [0,0,1,1], rec2 = [2,2,3,3]
        Output: false

 

Constraints:
    rec1.length == 4
    rec2.length == 4
    -1e9 <= rec1[i], rec2[i] <= 1e9
    rec1 and rec2 represent a valid rectangle with a non-zero area.




// Observations:
    - given rectangle as a list {x1, y1, x2, y2} where (x1, y1) is the coordinate of it's bottom left corner and (x2, y2) is the coordinates of it's top right corner. it's top and bottom edges are paler to x-axis and it left and right edges are parallel to y-axis.

    - Two rectangle overlap if the area of their intersection is positive. To be clear two rectangle that only touches at the corner or edges do not overlap.
    
    - Given two axial aligned rectangle rec1 rec2, return true if they overlap, else return false.

    // Example:
        rec1 = [0, 0, 2, 2], rect2 = [1, 1, 3, 3]
        o/p: true

                |
                |
            3   L     _________
                |    |         |
                |    |         |
            2   L----------    |
                |    |    |    |
                |    |    |    |
            1   L    |_ __|____|
                |         |
                |____|____|____|____|___
              (0,0)  1    2    3   4



        rec1 = [0, 0, 1, 1], rec2 = [1, 0, 2, 1]
        o/p: false

                |
                |
            3   L
                |
                |
            2   L-----
                |    |
                |    |
            1   L-----
                |    |
                |____|____|____|____|____|____
            (0, 0)   1    2    3    4    5

        Both the rectangle should be intersect, 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        
        // First rect:
        int a = rec1[0], b = rec1[1]; // bottom left
        int c = rec1[2], d = rec1[3];  // top right

        // Second rect:
        int A = rec2[0], B = rec2[1];   // bottom left
        int C = rec2[2], D = rec2[3];   // top right

        // Calculate the intersected rectangle:
        int X1 = max(a, A); // bottom left X
        int Y1 = max(b, B); // bottom left Y

        int X2 = min(c, C); // top right X
        int Y2 = min(d, D); // top right Y

        // Check atleast we should have one rectangle, without forming a line:
        if(X1 < X2 && Y1 < Y2) return true; // forming a rectangle..

        return false;
    }
};