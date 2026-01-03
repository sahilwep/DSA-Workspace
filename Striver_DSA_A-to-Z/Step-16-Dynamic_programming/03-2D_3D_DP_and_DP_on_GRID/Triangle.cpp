/*

//  120. Triangle


//  Problem Statement: 
    - Given a triangle array, return the minimum path sum from top to bottom.
    - For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


// Example:
        Example 1:
            Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
            Output: 11
            Explanation: The triangle looks like:
                       2
                      3 4
                     6 5 7
                    4 1 8 3
            
                The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).

        Example 2:
            Input: triangle = [[-10]]
            Output: -10

 
    // Observations:
        - Every time from the current level "idx" to next level it can go either "idx" or "idx + 1"

                       2
                      3 4
                     6 5 7
                    4 1 8 3
                   8 2 8 9 8
                  0 8 2 8 9 8
        
        - Also, Even if we go "idx + 1" in next level, we never go out of the range of that level.
        - because, everytime one value added into the level & we started from '0' so logically we always stays in bound..

        - It's just we need to check upon the choices:
            - C1 = go with same index on next level
            - C2 = go with one idx ahead on next level
            - Last return triangle[currLvl][idx] + min(c1, c2)
            
        // Recursive Solution:
            - We have to process with level & index
            - and from every current level we can go to next level by {idx | OR | idx + 1}

            // Function signature:
                - we have to return min sum.
                - everytime currentLvl & idx chances..

                    int solve(int currLvl, int idx, vector<vector<int>>& triangle) {
                        ...
                    }


            // base case:
                - if we reach to the last level, return that level current index value, so that we can add them up into our sum.
                    if(currLvl == n) {
                        return triangle[currLvl][idx];
                    }
            

            // Decision Tree:
                - and from every current level we can go to next level by {idx | OR | idx + 1}

                    int c1 = solve(currLvl + 1, idx);
                    int c2 = solve(currLvl + 1, idx + 1);

                    int ans = triangle[currLvl][idx] + min(c1, c2);

                    return ans;

            // Function Call:
                - Start from solve(0, 0, triangle)

            // Complexity:  
                - TC :O(2^n)
                - SC: O(n)  -> Depth of exploring all the level..


        // Memoization:
            - Variable values:
                    
                    0 <= currLvl <= n - 1

                    0 <= idx  <= m - 1      -> In worse we need to pick the last level size.

                    NOTE: m = triangle[n - 1].size()

            - Default values:

                    -1e4 <= triangle[i][j] <= 1e4

                    Put default vale as INT_MAX;    -> Because we are finding minimum value & it's beyond the erange for safety

            - Check the subproblems before going into decision tree.
            - Store the answer for the subproblems.
    

            // Complexity:
                - TC: O(n * m)  => m = the size of last level row.
                - SC: O(n * m)



        // Tabulations:
            - DP States:

                    0 <= currLvl <= n - 1
                    0 <= idx  <= m - 1      -> In worse we need to pick the last level size.

            - DP Transitions:

                    t[i][j] = triangle[i][j] + min(t[i][j + 1], t[i + 1][j + 1]);

            - Ranges:
                        n - 1 >= currLvl >= 0

                    triangle[currLvl - 1] >= idx >= 0

            - base case fill:
                    - Option 1: Out Side explicitly, we have to fill the last level of triangle value to the dp-table:
                        for(int i = 0; i < triangle[n - 1].size(); i++) {
                            t[n-1][i] = triangle[n-1][i];
                        }

                    - Option 2: inside the iterations:
                    
                        if(currLvl == n - 1) {
                                t[i][j] = triangle[i][j];
                                continue;
                        }

            - Return t[0][0]    => lvl = 0 & idx = 0, which is our starting point..


            // Complexity:
                - TC: O(n * m)  => m = the size of last level row.
                - SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Tabulations:
class Solution {
private:
    int n;
    vector<vector<int>> t;
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        int m = triangle[n - 1].size();

        t.resize(n + 1, vector<int> (m + 1, INT_MAX));

        // // Fill the baseCase here:
        // for(int i = 0; i < m; i++) {
        //     t[n-1][i] = triangle[n-1][i];
        // }

        for(int currLvl = n - 1; currLvl >= 0; currLvl--) {
            for(int idx = triangle[currLvl].size() - 1; idx >= 0; idx--) {
                // Or fill the base case here:
                if(currLvl == n - 1) {
                    t[currLvl][idx] = triangle[currLvl][idx];
                    continue;
                }

                // DP Transitions:
                int c1 = t[currLvl + 1][idx];
                int c2 = t[currLvl + 1][idx + 1];

                t[currLvl][idx] = triangle[currLvl][idx] + min(c1, c2);
            }
        }

        return t[0][0]; // return when level = 0 & idx = 0
    }
};


// Memoization:
class Solution {
private:
    int n;
    vector<vector<int>> t;
    int solve(int currLvl, int idx, vector<vector<int>> &triangle) {
        if(currLvl >= n - 1) {
            return triangle[currLvl][idx];   // can't go beyond 'n - 1' level
        }

        // Check in memo-table:
        if(t[currLvl][idx] != INT_MAX) return t[currLvl][idx];


        int c1 = solve(currLvl + 1, idx, triangle);     // Choice 1: Travel next lvl with same index
        int c2 = solve(currLvl + 1, idx + 1 , triangle);    // Choice 2: Travel next lvl with one index ahead, No need to check (idx + 1), because everytime one value added in level, & logically we started from '0', & even if one value get added, we never go out of the range..


        int ans = triangle[currLvl][idx] + min(c1, c2);
        return t[currLvl][idx] = ans;      // Return the minimum choice
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        int m = triangle[n - 1].size();

        t.resize(n + 1, vector<int> (m + 1, INT_MAX));

        return solve(0, 0, triangle);
    }
};


// Recursive Solution:
class Solution {
private:
    int n;
    int solve(int currLvl, int idx, vector<vector<int>> &triangle) {
        if(currLvl >= n - 1) {
            return triangle[currLvl][idx];   // can't go beyond 'n - 1' level
        }

        int c1 = solve(currLvl + 1, idx, triangle);     // Choice 1: Travel next lvl with same index
        int c2 = solve(currLvl + 1, idx + 1 , triangle);    // Choice 2: Travel next lvl with one index ahead, No need to check (idx + 1), because everytime one value added in level, & logically we started from '0', & even if one value get added, we never go out of the range..


        return triangle[currLvl][idx] + min(c1, c2);     // Return the minimum choice
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();

        return solve(0, 0, triangle);
    }
};



// Extra:
// Memoization: Correct & Accepted, badly written, just for the reference of my inital solution, how they looked :(
class Solution {
private:
    int n;
    vector<vector<int>> t;
    int solve(int currLvl, int prevIdx, vector<vector<int>> &triangle) {
        if(currLvl >= n) {
            return 0;   // can't go beyond 'n - 1' level
        }

        // Check in memo-table:
        if(t[currLvl][prevIdx] != INT_MAX) return t[currLvl][prevIdx];


        // Choice 1: can travel in same idx of current level?
        int c1 = triangle[currLvl][prevIdx] + solve(currLvl + 1, prevIdx, triangle);

        // Choice 2: can travel one idx ahead in current level ?: (We have to check the valid index to travel in current row)
        int c2 = (prevIdx + 1 < triangle[currLvl].size()) ? triangle[currLvl][prevIdx + 1] + solve(currLvl + 1, prevIdx + 1 , triangle) : INT_MAX;

        return t[currLvl][prevIdx] = min(c1, c2);      // Return the minimum choice
    }
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        n = triangle.size();
        int m = triangle[n - 1].size();

        t.resize(n + 1, vector<int> (m + 1, INT_MAX));

        return solve(0, 0, triangle);
    }
};