/*

//  Chocolate Pickup 

//  Problem Statement: 
    - You are given a 2D matrix grid[][] of size n*m, where each cell grid[i][j] represents the number of chocolates available at position (i, j).
    - Two robots are collecting chocolates from this grid:
        - Robot 1 starts at the top-left corner (0, 0)
        - Robot 2 starts at the top-right corner (0, m - 1)
    - Your task is to determine the maximum total number of chocolates both robots can collect while following these rules:
        - From a cell (i, j), robots can move to cell (i + 1, j - 1), (i + 1, j), or (i + 1, j + 1).
        - When a robot visits a cell, it collects all the chocolates there.
        - If both robots land on the same cell, the chocolates in that cell are collected only once.
        - Robots cannot move outside the boundaries of the grid.
        - Both robots must continue moving until they reach the bottom row of the grid.

// Example:
    Input: grid[][] = [[4, 1, 2], [3, 6, 1], [1, 6, 6], [3, 1, 2]]
    Output: 32
        Explanation: The path followed by first robot is: (0, 0) -> (1, 0) -> (2, 1) -> (3, 0), so first robot collected: 4 + 3 + 6 + 3 = 16 chocolates.
        The path followed by second robot is: (0, 2) -> (1, 1) -> (2, 2) -> (3, 2), so second robot collected: 2 + 6 + 6 + 2 = 16 chocolates.
        Total both robots collected 16 + 16 = 32 chocolates.


// Observations:
    - alice is at (0, 0)
    - bob is at (0, m -1)
    - They need to go to the last row, & while going in path they needs to collect the chocolate in that path..
    - If both alice & bob, falls into same cell, then only one chocolate should be counted..
    - Both move on next level simaltiounsly.
    - each one have 3 choices to go: bottom_left, bottom, bottom_right:

        from current row 'i', they can move on next row cols as:
                 (0, 0)
                /  |  \
          (1,-1) (1,0) (1, 1)

        Rows remains constant, only the cols changes for both: {-1, 0, 1}
        we have 3 path to explore {-1, 0, 1} & there are two person alice & bob
        So we need to generate all the possible path they can move together:

            for(int da = -1; da <= 1; da++) {   // for alice
                for(int db = -1; db <= 1; db++) {   // for bob
                    int nextAlice = da + aliceIdx;
                    int nextBob = db + bobIdx;

                    if(isValidCols(nextAlice, nextBob)) {
                        ... explore the path
                    }
                }
            }

        Something like above we can generate all the combinations for {alice,bob} next move together..

    - Recursive solution will help us to find our answer.

    // Recursion
        // Function Signature:
            - we need total maximum collection in int value
            - We will have level/row
            - We will have aliceIdx, bobIdx

            int solve(int currLvl, int aliceIdx, int bobIdx, vector<vector<int>>& grid) {
                ... logic..
            }

        // Base case:
            if(currLvl == n - 1) {  // when we reached at last row:
                if(aliceIdx == bobIdx) return grid[currLvl][aliceIdx];  // as they are in same cell, return only one value, no need to add them up.
                else return grid[currLvl][aliceIdx] + grid[currLvl][bobIdx];
            }

        // Decision Tree:
            - we need to get the maximum chocolates we can collect from the branch:
                
                    int maxi = INT_MIN; // inital value of our total-Collection.

                    for(int da = -1; da <= 1; da++) {   // for alice
                        for(int db = -1; db <= 1; db++) {   // for bob
                            int nextAlice = da + aliceIdx;
                            int nextBob = db + bobIdx;

                            if(isValidCols(nextAlice, nextBob)) {
                                int future = solve(currLvl + 1, nextAlice, nextBob, grid);

                                maxi = max(maxi, future);
                            }
                        }
                    }

                    // check if alice & bob lies in same cell, if they add only one cell value : else add both.
                    int curr = (aliceIdx == bobIdx) ? grid[currLvl][aliceIdx] : grid[currLvl][aliceIdx] + grid[currLvl][bobIdx];

                    return curr + maxi;


        // Valid function:
            - This function will check the next move lies in valid column rang or not?
                bool isValidCol(int a, int b) { // return alice & bob lies in valid col-range:
                    return (a >= 0 && a < m && b >= 0 && b < m);
                }

        // Complexity:
            - TC: O(9^n)
            - SC: O(n)

        // Optimization:
            - Multiple Subproblem being recomputed, we can optimize this using memo-table
            - Variable values:
                    0 <= aliceIdx <= m - 1
                    0 <= bobIdx <= m - 1
                    0 <= currLvl <= n - 1

            - Create a 3D memo table of size (n * m * m)
            - Check in memo-table before computing any subproblem.
            - same the answer in memo-table before returning our answer.

        // Complexity:
            - TC: O(n * m^2)
            - SC: O(n * m^2)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Memoization:
class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> t;
    bool isValidCol(int a, int b) { return (a >= 0 && a < m && b >= 0 && b < m);}
    int solve(int currLvl, int aliceIdx, int bobIdx, vector<vector<int>>& grid) {
        
        // Base case:
        if(currLvl == n - 1) {
            if(aliceIdx == bobIdx) return grid[currLvl][aliceIdx];
            else return grid[currLvl][aliceIdx] + grid[currLvl][bobIdx];
        }
        
        // Check in memo-table:
        if(t[currLvl][aliceIdx][bobIdx] != -1) {
            return t[currLvl][aliceIdx][bobIdx];
        }
    
        // Try all 3x3 Moves:
        int maxi = INT_MIN;
        for(int da = -1; da <= 1; da++) {  // alice move: -1, 1, 1
            for(int db = -1; db <= 1; db++) {
                int nextAlice = da + aliceIdx;
                int nextBob = db + bobIdx;
    
                // Out-of-Bound check:
                if(isValidCol(nextAlice, nextBob)) {
                    int future = solve(currLvl + 1, nextAlice, nextBob, grid);
                    
                    maxi = max(maxi, future);
                }
            }
        }
    
        int curr = (aliceIdx == bobIdx) ? grid[currLvl][aliceIdx] : grid[currLvl][aliceIdx] + grid[currLvl][bobIdx];
    
        return t[currLvl][aliceIdx][bobIdx] = curr + maxi;
    }
public:
    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        t.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (m + 1, -1)));
        
        return solve(0, 0, m - 1, grid);
    }
};


// Recursive Solution:
class Solution {
private:
    int n, m;
    bool isValidCol(int a, int b) { return (a >= 0 && a < m && b >= 0 && b < m);}
    int solve(int currLvl, int aliceIdx, int bobIdx, vector<vector<int>>& grid) {
        
        // Base case:
        if(currLvl == n - 1) {
            if(aliceIdx == bobIdx) return grid[currLvl][aliceIdx];
            else return grid[currLvl][aliceIdx] + grid[currLvl][bobIdx];
        }
        

        // Try all 3x3 Moves:
        int maxi = INT_MIN;
        for(int da = -1; da <= 1; da++) {  // alice move: -1, 1, 1
            for(int db = -1; db <= 1; db++) {
                int nextAlice = da + aliceIdx;
                int nextBob = db + bobIdx;
    
                // Out-of-Bound check:
                if(isValidCol(nextAlice, nextBob)) {
                    int future = solve(currLvl + 1, nextAlice, nextBob, grid);
                    
                    maxi = max(maxi, future);
                }
            }
        }
    
        int curr = (aliceIdx == bobIdx) ? grid[currLvl][aliceIdx] : grid[currLvl][aliceIdx] + grid[currLvl][bobIdx];
    
        return curr + maxi;
    }
public:
    int maxChocolate(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        return solve(0, 0, m - 1, grid);
    }
};