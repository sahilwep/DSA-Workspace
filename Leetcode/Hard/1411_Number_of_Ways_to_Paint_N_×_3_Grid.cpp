/*

//  1411. Number of Ways to Paint N × 3 Grid


//  Problem Statement: 
    - You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
    - Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

 
// Example:
    Example 1:
        Input: n = 1
        Output: 12
        Explanation: There are 12 possible way to paint the grid as shown.

    Example 2:
        Input: n = 5000
        Output: 30228214


// Observations:
    - Type 1: ABA type colors
    - Type 2: ABC type colors.
    
        Example: n = 1
            colors: ABC
                Type 1: ABA, ACA, BAB, BCB, CAC, CBC
                Type 2: ABC, ACB, BAC, BCA, CAB, CBA
        
        Example: n = 2
            Colors: ABC

                Type1: 
                    with ABA: 
                            ABA     ABA     ABA     ABA     ABA
                            ACA     BAB     BCB     CAC     ......

                    with ACA:
                            ACA     ACA     ACA     ACA     ACA
                            ABA     BAB     BCB     CAC     .......

                    ....
                    ....
                    ....
                    with CBA:
                            CBA     CBA     CBA     CBA     CBA
                            ABA     ACA     BAB     BCB     ......

        - Similarly for larger 'n' values, we will do the same:
        - One thing is sure that:
            as we are fixed with "col size"
            It can only be of 3 size
                ABA || ACA || ...
        
        - These are the First Row possible cols which are fixed
            ABA, ACA, BAB, BCB, CAC, CBC
            ABC, ACB, BAC, BCA, CAB, CBA

        - now we need to explore the rest "n - 1" rows...
        - To generate first Row Possible Cols:
            - we can write a recursive function, or directly store the above list..
            - we only have these 3 colors on which we have to generate all the possible states we can fill with first row: {'A', 'B', 'C'}
            - Recursive function looks something like: 
            
                        colLen = 3; // given in constrains
                        vector<string> firstRowStates;
                        void generateFirstRowPossibleStates(string curr, int len, char prevChar) {
                            if(curr.size() == colLen) { // if we have some pattern with size '3'
                                firstRowStates.push_back(curr);
                                return;
                            }

                            // Generate pattern from : {'A', 'B', 'C'}
                            for(char ch: {'A', 'B', 'C'}) {
                                if(ch == prevCh) continue;  // skip that
                                generateFirstRowPossibleStates(curr + ch, len + 1, ch);     // explore next state
                            }
                        }
                        
                - function call:
                    - for prevChar, we can send anything except {'A', 'B', 'C'}, as the first them when we are calling..
                        generateFirstRowPossibleStates("", 0, 'Z'); 

                - Logic is quite simple to understand, we will generate all the pattern for first state.
                - Now step 1: is done.

        - Step 2: 
            - We have to explore all the possible Filling, by simply iterating in firstRowStates, and sending every-state one-by-one as our first row, & try to genrate the grid filling..

                for(int i = 0; i < firstRowStates.size() ;i++) {
                    // send the currentState index
                    // send the remaining rows, that we have to explore.
                    solve(i, n - 1);        
                }

        - Step 3:
            - We can also do this by using recursion:
                
                    solve(int prevStateIdx, int remainingRows) {
                        // Base case:
                        if(remainingRows == 0) {
                            return 1;   // as we fill the whole grid, we need to return 1 ways as our answer..
                        }

                        // Decision Tree:
                        ways = 0;

                        string prevState = firstRowStates[prevStateIdx]; // we need to get the prev state pattern.

                        for(int i = 0; i < firstRowStates.size(); i++) {    // explore in firstRowStates & try filling..
                            if(i == prevStateIdx) continue;  // skip the prevState pattern.

                            string curr = firstRowStates[i];    // get the curr state pattern

                            // We have to check character-by-character, it's should no be matching..
                            bool isSafeToExplore = true;
                            for(int j = 0; j < curr.size(); i++) {    // because it's only limited to 3-size string.
                                if(preState[j] == curr[j]) {
                                    isSafeToExplore = false;
                                    break;
                                }
                            }

                            if(isSafeToExplore) {
                                ways += solve(i, remainingRows - 1);  // send curr index & "remaining - 1" for next explorations.
                            }
                        }

                        return ways;
                    }

        
        // Falls into TLE:
            - Multiple subproblem begin recomputed..

        // Optimizations:
            - memoizing the solve() func, as we have higher constrains & multiple subproblem are recomputed.
            - Variable values:
                prevStateIdx
                remainingRows

            - These are the values that are chaning
            - solve() return "int"

                make a key by combining 
                    key = to_string(prevStateIdx) + "@" + to_string(remainingRows)
                use map to store {key: value} works as memo-table..
                    u_map<string, int> t;

            - Check before gaining into Decision tree..
            - store the answer in dp table before returning the values..

            - using map is not being accepted, it's killing the performance, 
            - used 2D vector instead of size: 
                    solve(int prevStateIdx, int remainingRows)
                    
                    0 <= prevStateIdx <= firstRowStates.size()
                    0 <= remainingRows<= n
    



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    int n, m;
    int mod = 1e9 + 7;
    vector<string> firstRowStates;
    vector<vector<int>> t;   // memo-table
    void generateState(string curr, int len, char prevColor) {  // Function to generate the row possible patterns:
        if(len == m) {  // compare it with col size
            firstRowStates.push_back(curr);
            return;
        }

        for(char ch: {'R', 'G', 'B'}) {
            if(ch == prevColor) continue;
            generateState(curr + ch, len + 1, ch);
        }
    }
    int solve(int prevStateIdx, int remainingRows) {   // function to generate all possible patterns.
        if(remainingRows == 0) {
            return 1;   // we have filled the 2D array, return 1, as we found 1 way.
        }


        // Check in memo-table:
        if(t[prevStateIdx][remainingRows] != -1) {
            return t[prevStateIdx][remainingRows];
        }


        string prevState = firstRowStates[prevStateIdx];

        int ways = 0;

        for(int i = 0; i < firstRowStates.size(); i++) {
            if(i == prevStateIdx) continue; // skip current state

            string curr = firstRowStates[i];

            bool isValidToWalk = true;
            for(int j = 0; j < m; j++) {    // m cols: 
                if(prevState[j] == curr[j]) {
                    isValidToWalk = false;
                    break;
                }
            }
            
            if(isValidToWalk) {
                ways = (ways + solve(i, remainingRows - 1)) % mod;
            }
        }

        return t[prevStateIdx][remainingRows] = (ways % mod);
    }
public:
    int numOfWays(int rows) {
        n = rows;
        m = 3;
        

        // Step 1: Generate first col possible states from colors {'R', 'G', 'B}
        generateState("", 0, 'Z');

        t.resize(firstRowStates.size() + 1, vector<int> (n + 1, -1));

        
        // Step 2: From the generated state, try finding all the possible ways to fill Grid
        int res = 0;
        for(int i = 0; i < firstRowStates.size(); i++) {
            res = (res + solve(i, n - 1)) % mod;
        }

        return res;
    }
};