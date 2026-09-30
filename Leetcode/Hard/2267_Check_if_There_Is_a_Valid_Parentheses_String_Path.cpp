/*

//  2267. Check if There Is a Valid Parentheses String Path


//  Problem Statement: 
    - A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
        - It is ().
        - It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
        - It can be written as (A), where A is a valid parentheses string.

    - You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
        - The path starts from the upper left cell (0, 0).
        - The path ends at the bottom-right cell (m - 1, n - 1).
        - The path only ever moves down or right.
        - The resulting parentheses string formed by the path is valid.

    - Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

 
// Observations:
    - given non-empty grid consisting only '(' ')'. it is valid if any of the following conditions is true:
        - it is ()
        - it can be write as AB (A conscanted with B), where A and B are valid parenthesis string.
        - it can be written as (A), where A is a valid parenthesis string.
    - We are given n x m matrix of parenthesis grid. A valid parenthesis string path in the grid is a path satisfying all the following conditions:
        - path srtt from (0, 0)
        - end with (n - 1, m - 1)
        - path only moves down and right.
        - resulting parenthesis string formed by the path is valid.
    - return true if theres exist a valid parenthesis string path in the grid. otherwise return false.


    // Approach:
        - number of open brackets and closed brackets.
        - one thing we are sure while exploring, that number of open brackets should be grater equal to number of closed brackets.
        - we will explore the path through recursion, and check for every cells wether we have number of open brackets is grater or equal to current closed or not?
            - if they are then we will explore further.
        - at the end when we reach to the destinations, cell, we will check wether at the destinations cell number of open and closed are equal or not?
        - we will use 


        ["(","(","(","(","("]
        ["(","(",")",")",")"]
        [")","(",")",")","("]
        ["(","(",")",")",")"]

        here is a path from (0,0)-(1,0)-(2,0)-(3,0)-(3,1)-(3,2)-(3,3)-(3,4)


        - Recursive solution falls into TLE, we will have to optimize this..
        - we have 4 variable values:
            (row, col, open, closed)

            1 <= n, m <= 100

        - if we initialize the 4D matrix, that definitely gives us MLE..

            we only care about the "open >= closed"
                we can simply store the informations about the open >= closed or not?

                    let say:
                        balance is '0'
                            ')' -> balance++
                            '(' -> balance--
                            ')' -> balance++
                            ')' -> balance++

                        
                    while going into the decision tree, we will simply check the number of closed and open:
                        which is nothing but (balance >= 0)


                -> notice: balanced can be any value: 1,2,3,4,..,-1,-2,-4...

                        and we are have to preserve the conditions: 
                            balanced >= 0

                                so, if(balanced < 0) return false;  as not useful to explore..

                -> now what's the erange of balanced?
                    - we are constrain to go only: right & down:
                        so right => m
                            down => n

                        - we have "n + m + 1" as the size of this path... 

    // Complexity:
        - TC: O(n * m)
        - SC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimal Solution:
class Solution {
private:
    int n, m;
    vector<vector<vector<int>>> t;
    bool solve(int row, int col, int balanced, vector<vector<char>>& grid) {
        // compute the current cell open/close cnt:
        if(grid[row][col] == '(') balanced++; 
        else balanced--;

        // Invalid case, when closed parenthesis is grater than the open one:
        if(balanced < 0) return false;


        // fetch value form the DP table and return directly..
        if(t[row][col][balanced] != -1) return t[row][col][balanced];


        // Do we reach destinations:
        if(row == n - 1 && col == m - 1 && balanced == 0) return t[row][col][balanced] = true;
    
        // Explore Down:
        if(row + 1 < n && balanced >= 0) {
            if(solve(row + 1, col, balanced, grid)) return t[row][col][balanced] = true;
        }

        // Explore Right:
        if(col + 1 < m && balanced >= 0) {
            if(solve(row, col + 1, balanced, grid)) return t[row][col][balanced] = true;
        }

        return t[row][col][balanced] = false;   // not reach to destinations.
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Edge case:
        if(grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;

        // initialize the dp table: -1 uncomputed, 0 false, 1 true
        t.resize(n + 1, vector<vector<int>> (m + 1, vector<int> (n + m + 1, -1)));

        return solve(0, 0, 0, grid);
    }
};





// Recursive Solution:
class Solution {
private:
    int n, m;
    bool solve(int row, int col, int open, int close, vector<vector<char>>& grid) {
        // compute the current cell open/close cnt:
        if(grid[row][col] == '(') open++;
        else close++;

        // Do we reach destinations:
        if(row == n - 1 && col == m - 1) return (open == close);
    
        // Explore Down:
        if(row + 1 < n && open >= close) {
            if(solve(row + 1, col, open, close, grid)) return true;
        }

        // Explore Right:
        if(col + 1 < m && open >= close) {
            if(solve(row, col + 1, open, close, grid)) return true;
        }

        return false;   // not reach to destinations.
    }
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        // Edge case:
        if(grid[0][0] == ')' || grid[n - 1][m - 1] == '(') return false;


        return solve(0, 0, 0, 0, grid);
    }
};