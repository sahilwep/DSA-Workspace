/*

//  3000. Maximum Area of Longest Diagonal Rectangle


//  Problem Statement: 
    -> You are given a 2D 0-indexed integer array dimensions.
    -> For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.
    -> Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.

 
// Example:
    Example 1:
        Input: dimensions = [[9,3],[8,6]]
        Output: 48
        Explanation: 
        For index = 0, length = 9 and width = 3. Diagonal length = sqrt(9 * 9 + 3 * 3) = sqrt(90) ≈ 9.487.
        For index = 1, length = 8 and width = 6. Diagonal length = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10.
        So, the rectangle at index 1 has a greater diagonal length therefore we return area = 8 * 6 = 48.

    Example 2:
        Input: dimensions = [[3,4],[4,3]]
        Output: 12
        Explanation: Length of diagonal is the same for both which is 5, so maximum area = 12.

 
// Observations: 
    -> We are given 2D indexed integer array dimensions.
    -> We need to compute the area of rectangle having the largest diagonal.
    -> If there are multiple rectangle with longest diagonal return the area of rectangle having maximum area.
    
    // Approach:
        -> Diagonal Formula: sqrt(l^2 + b^2)
            -> We will compute diagonalSquare, not diagonal, because comparing with squareroot we will introduce floating number, which will interfere with our answer.
        -> Compute the diagonal square: l * l + b * b
        -> Compute the square of rectangle: l * b
        -> Compare with previous diagonalSquare with previous stored, get the best one
        -> If multiple diagonalSquare are same, get the largest area rectangle.

        // Complexity:
            -> TC: O(n)
            -> SC: O(1)
                -> n = dimensions.size()

        // Extra:
            -> If we want to compare diagonal insted of diagonalSquare, we have to use double Type for precision.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// With Diagonal Square Logic:
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int bestArea = 0;
        int maxDiagSq = 0;
        for(auto& it: dimensions) {
            int l = it[0];
            int b = it[1];

            int diagSq = l * l + b * b;     // compute the diagonalSquare
            int area = l * b;               // compute the area

            // if diagonalSqr length is greater than previous computed ones || we have same diagonalSqr length, but newly found has larger area.
            if(diagSq > maxDiagSq || diagSq == maxDiagSq && area > bestArea) {
                maxDiagSq = diagSq;
                bestArea = l * b;
            }
        }

        return bestArea;
    }
};


// Extra: With Diagonal Logic:
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int bestArea = 0;
        double maxDiag = 0;
        for(auto& it: dimensions) {
            int l = it[0];
            int b = it[1];

            double diagonal = sqrt(l * l + b * b);      // compute the diagonal
            int area = l * b;                           // compute the area

            // if diagonal length is greater than previous || we have same diagonal length, but newly found has larger area.
            if(diagonal > maxDiag || diagonal == maxDiag && area > bestArea) {
                maxDiag = diagonal;
                bestArea = l * b;
            }
        }

        return bestArea;
    }
};