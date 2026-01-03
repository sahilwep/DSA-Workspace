/*

//  1931. Painting a Grid With Three Different Colors


//  Problem Statement: 
    - You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
    - Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.

 
// Example:
    Example 1:
        Input: m = 1, n = 1
        Output: 3
        Explanation: The three possible colorings are shown in the image above.

    Example 2:
        Input: m = 1, n = 2
        Output: 6
        Explanation: The six possible colorings are shown in the image above.

    Example 3:
        Input: m = 5, n = 5
        Output: 580986


// Observations:
    - Type 1: ABA type colors
    - Type 2: ABC type colors.
    
        Example: n = 1, m = 3
            colors: ABC
                Type 1: ABA, ACA, BAB, BCB, CAC, CBC
                Type 2: ABC, ACB, BAC, BCA, CAB, CBA
        
        Example: n = 2, m = 3
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

        - Similarly for larger 'n' & 'm' values, we will do the same:
        - One thing is sure that:
            - Constrains of 'n' goes up till '5'
            - So if we first generate the possible states for the first col & store that into list
                - Then we only have to check for all possible states:
                    - place that into first col: 
                        - Explore the remaining generated ones for rest "m - 1" cols..


        - Once we generate the first cols possible states with given n-size:
        - now we need to explore the rest "m - 1" cols...
        - To generate first possibles cols:
            - we can write a recursive function, or directly store the above list..
            - Recursive function looks something like:
                        n = rows.size();
                        m = cols.size();
                        vector<string> firstColStates;
                        void generateFirstColPossibleStates(string curr, int len, char prevChar) {
                            if(curr.size() == n) { // comparing it with row size.
                                firstColStates.push_back(curr);
                                return;
                            }

                            // Generate pattern from : {'A', 'B', 'C'}
                            for(char ch: {'A', 'B', 'C'}) {
                                if(ch == prevCh) continue;  // skip that
                                generateFirstColPossibleStates(curr + ch, len + 1, ch);     // explore next state
                            }
                        }
                        
                - function call:
                    - for prevChar, we can send anything except {'A', 'B', 'C'}, as the first them when we are calling..
                        generateFirstColPossibleStates("", 0, 'Z'); 

                - Logic is quite simple to understand, we will generate all the pattern for first state.
                - Now step 1: is done.

        - Step 2: 
            - We have to explore all the possible Filling, by simply iterating in firstColStates, and sending every-state one-by-one as our first col, & try to fill rest of the  grid.

                for(int i = 0; i < firstColStates.size() ;i++) {
                    // send the currentState index
                    // send the remaining cols, that we have to explore.
                    solve(i, m - 1);        
                }

        - Step 3:
            - We can also do this by using recursion:
                
                    solve(int prevStateIdx, int remainingCols) {
                        // Base case:
                        if(remainingCols == 0) {
                            return 1;   // as we fill the whole grid, we need to return 1 ways as our answer..
                        }

                        // Decision Tree:
                        ways = 0;

                        string prevState = firstColStates[prevStateIdx]; // we need to get the prev state pattern.

                        for(int i = 0; i < firstColStates.size(); i++) {    // explore in firstColStates & try filling..
                            if(i == prevStateIdx) continue;  // skip the prevState pattern.

                            string curr = firstColStates[i];    // get the curr state pattern

                            // We have to check character-by-character, it's should no be matching..
                            bool isSafeToExplore = true;
                            for(int j = 0; j < n; i++) {
                                if(preState[j] == curr[j]) {
                                    isSafeToExplore = false;
                                    break;
                                }
                            }

                            if(isSafeToExplore) {
                                ways += solve(i, remainingCols - 1);  // send curr index & "remaining - 1" for next explorations.
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
        remainingCols

    - These are the values that are chaning
    - solve() return "int"

        make a key by combining 
            key = to_string(prevStateIdx) + "@" + to_string(remainingCols)
        use map to store {key: value} works as memo-table..
            u_map<string, int> t;

    - Check before gaining into Decision tree..
    - store the answer in dp table before returning the values..


// Simillar Question:
    LC: 1411        https://github.com/sahilwep/DSA-Workspace/blob/770b31cb172ed320781e8c0fc23fb9eee9766e81/Leetcode/Hard/1411_Number_of_Ways_to_Paint_N_%C3%97_3_Grid.cpp

    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private: 
    int mod = 1e9 + 7;
    int n, m;
    vector<string> firstColStates;
    unordered_map<string, int> t;   // memo-table
    void generateState(string curr, int len, char prevColor) {  // Function to generate the column possible patterns:
        if(len == n) {  
            firstColStates.push_back(curr);
            return;
        }

        for(char ch: {'R', 'G', 'B'}) {
            if(ch == prevColor) continue;
            generateState(curr + ch, len + 1, ch);
        }
    }
    int solve(int prevStateIdx, int remainingCols) {   // function to generate all possible patterns.
        if(remainingCols == 0) {
            return 1;   // we have filled the 2D arry, return 1, as we found 1 way.
        }

        // Check in memo-table:
        string key = to_string(prevStateIdx) + "@" + to_string(remainingCols);
        if(t.count(key)) {
            return t[key];
        }


        string prevState = firstColStates[prevStateIdx];

        int ways = 0;

        for(int i = 0; i < firstColStates.size(); i++) {
            if(i == prevStateIdx) continue; // skip current state

            string curr = firstColStates[i];

            bool isValidToWalk = true;
            for(int j = 0; j < n; j++) {
                if(prevState[j] == curr[j]) {
                    isValidToWalk = false;
                    break;
                }
            }
            
            if(isValidToWalk) {
                ways = (ways + solve(i, remainingCols - 1)) % mod;
            }
        }

        return t[key] = (ways % mod);
    }
public:
    int colorTheGrid(int row, int col) {
        n = row;
        m = col;

        // Step 1: Generate first col possible states from colors {'R', 'G', 'B}
        generateState("", 0, 'Z');  // Initially send any previous char apart from  {'R', 'G', 'B}


        // Step 2: From the generated state, try finding all the possible ways to fill Grid
        int res = 0;
        for(int i = 0; i < firstColStates.size(); i++) {
            // We have to start with all the possible generated firstColStates
            // We will send how many cols we have to fill, & current chose state.
            // m - 1, remaining cols to generate, i is the col that we have selected in firstColStates
            res = (res + solve(i, m - 1)) % mod;
        }

        return res;
    }
};