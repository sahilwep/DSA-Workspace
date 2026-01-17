/*

//  3047. Find the Largest Area of Square Inside Two Rectangles


//  Problem Statement: 
    - There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.
    - You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.

        

    Example 1:
        Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
        Output: 1
        Explanation: A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

    Example 2:
        Input: bottomLeft = [[1,1],[1,3],[1,5]], topRight = [[5,5],[5,7],[5,9]]
        Output: 4
        Explanation: A square with side length 2 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 2 * 2 = 4. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.

    Example 3:
        Input: bottomLeft = [[1,1],[2,2],[1,2]], topRight = [[3,3],[4,4],[3,4]]
        Output: 1
        Explanation: A square with side length 1 can fit inside the intersecting region of any two rectangles. Also, no larger square can, so the maximum area is 1. Note that the region can be formed by the intersection of more than 2 rectangles.

    Example 4:
        Input: bottomLeft = [[1,1],[3,3],[3,1]], topRight = [[2,2],[4,4],[4,2]]
        Output: 0
        Explanation: No pair of rectangles intersect, hence, the answer is 0.


// Observations:
    - We need to find the largest area of square for the only overlapping rectangles.
    - For any two rectangle:
        - we will find the width & length
        - and we will take min of them so that we can build square sides.
        - lastly from all the maximum sides, we will compute our area.
    - This is simple maths geometry problem:

        y-axis
            |
            |
            |             ______________(x4,y4)
            |            |              |
            |    ________|_____(x2,y2)  |   
            |   |        |     |        |
            |   | (x3,y3)|_____|________|
            |   |              |
            |   |______________|
            | (x1, y1)
            |________________________________       x-axis

        - Overlapping rectangle we have:
            - to find the square: 
                     _____
                    |     | 
                    |_____| 

            - First we will have to find the width which being computed on x-axis:
                startingX = max(x1, x3)
                endingX = min(x2, x4)

                    width = endingX - startingX
            
            - Then we will find the length which is being computed on y-axis
                startingY = max(y1, y3)
                endingY = min(y2, y4)

                    length = endingY - startingY

            - Last we can compute the side:
                    side = min(width, length)   -> We will take min so that we can form the square with that size.
            
            - After computing all the possible sides, we will take maximum valid sides for forming square.
            - At last we will return the area by (side * side)

        - Given Constrains for (1 <= bottomLeft, topRight <= 10^3)
            - If we compute with O(n^2) => it goes up till  10^6  which is acceptable..

    // Complexity:
        - TC: O(n^2)
        - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    typedef long long ll;
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();

        int maxSide = 0;
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                // Find width:
                int x1 = bottomLeft[i][0];
                int x2 = topRight[i][0];

                int x3 = bottomLeft[j][0];
                int x4 = topRight[j][0];

                int startingX = max(x1, x3);
                int endingX = min(x2, x4);

                int width = endingX - startingX;

                // Find length:
                int y1 = bottomLeft[i][1];
                int y2 = topRight[i][1];

                int y3 = bottomLeft[j][1];
                int y4 = topRight[j][1];

                int startingY = max(y1, y3);
                int endingY = min(y2, y4);

                int length = endingY - startingY;

                int side = min(width, length);     // Calculate sides:

                maxSide = max(maxSide, side);   // Store maximum side
            }   
        }


        return 1ll * maxSide * maxSide; // return area of that side
    }
};