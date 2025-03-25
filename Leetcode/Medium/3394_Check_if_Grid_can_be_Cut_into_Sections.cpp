/*

//  3394. Check if Grid can be Cut into Sections


//  Problem Statement: 
    -> You are given an integer n representing the dimensions of an n x n grid, with the origin at the bottom-left corner of the grid. You are also given a 2D array of coordinates rectangles, where rectangles[i] is in the form [start[x], start[y], end[x], end[y]], representing a rectangle on the grid. Each rectangle is defined as follows:
        -> (start[x], start[y]): The bottom-left corner of the rectangle.
        -> (end[x], end[y]): The top-right corner of the rectangle.
    -> Note that the rectangles do not overlap. Your task is to determine if it is possible to make either two horizontal or two vertical cuts on the grid such that:
        -> Each of the three resulting sections formed by the cuts contains at least one rectangle.
        -> Every rectangle belongs to exactly one section.
    -> Return true if such cuts can be made; otherwise, return false.


// Example: 

    Example 1:
        Input: n = 5, rectangles = [[1,0,5,2],[0,2,2,4],[3,2,5,3],[0,4,4,5]]
        Output: true
        Explanation: The grid is shown in the diagram. We can make horizontal cuts at y = 2 and y = 4. Hence, output is true.

    Example 2:
        Input: n = 4, rectangles = [[0,0,1,1],[2,0,3,4],[0,2,2,3],[3,0,4,3]]
        Output: true
        Explanation: We can make vertical cuts at x = 2 and x = 3. Hence, output is true.

    Example 3:
        Input: n = 4, rectangles = [[0,2,2,4],[1,0,3,2],[2,2,3,4],[3,0,4,2],[3,2,4,4]]
        Output: false
        Explanation: We cannot make two horizontal or two vertical cuts that satisfy the conditions. Hence, output is false.

        
// Observations: 
    -> This Question is another variant of range overlapping problem.
    -> Just get the correct range & count the break points..


// Complexity: 
    -> TC: O(n * log(n))
    -> SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int getCuts(int n, vector<vector<int>> range) { // check possible cuts:
        int rangeSize = range.size();
        sort(begin(range), end(range));

        int cuts = 0;
        int prevStart = range[0][0], prevEnd = range[0][1];
        for(int i = 1; i < rangeSize; i++) {
            int currStart = range[i][0], currEnd = range[i][1];

            // check Overlapping & maximum Ends:
            if(prevEnd > currStart) {
                prevEnd = max(prevEnd, currEnd);    // store maximum range among them..
            }
            else {  // prevEnd <= currStart
                cuts += 1;  // make one cuts

                prevStart = currStart;
                prevEnd = currEnd;                
            }
        }
        // NOTE: No need to check last cuts, as it's on boundary line 'n' & we are also not counting the starting cuts that found in '0'

        return cuts;
    }
public:
    bool checkValidCuts(int n, vector<vector<int>>& rec) {
        int rSize = rec.size();
        vector<vector<int>> xRange;
        vector<vector<int>> yRange;
        
        for(int i = 0; i < rSize; i++) {
            xRange.push_back({rec[i][0], rec[i][2]});
            yRange.push_back({rec[i][1], rec[i][3]});
        }
       
        if(getCuts(n, xRange) > 1) return true; // vertical cuts

        if(getCuts(n, yRange) > 1) return true; // horizontal cuts

        return false;
    }
};