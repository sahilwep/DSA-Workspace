/*

//  909. Snakes and Ladders


//  Problem Statement:
    -> You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.
    -> You start on square 1 of the board. In each move, starting from square curr, do the following:
        -> Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
            -> This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless of the size of the board.
        -> If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
        -> The game ends when you reach the square n2.
    -> A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.
    -> Note that you only take a snake or ladder at most once per dice roll. If the destination to a snake or ladder is the start of another snake or ladder, you do not follow the subsequent snake or ladder.
        -> For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder to square 3, but do not follow the subsequent ladder to 4.
    -> Return the least number of dice rolls required to reach the square n2. If it is not possible to reach the square, return -1.


 
// Example: 
    Example 1:

        Input: board = [[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,-1,-1,-1,-1,-1],[-1,35,-1,-1,13,-1],[-1,-1,-1,-1,-1,-1],[-1,15,-1,-1,-1,-1]]
        Output: 4
        Explanation: 
            In the beginning, you start at square 1 (at row 5, column 0).
            You decide to move to square 2 and must take the ladder to square 15.
            You then decide to move to square 17 and must take the snake to square 13.
            You then decide to move to square 14 and must take the ladder to square 35.
            You then decide to move to square 36, ending the game.
            This is the lowest possible number of moves to reach the last square, so return 4.

    Example 2:

        Input: board = [[-1,-1],[-1,3]]
        Output: 1




// Observations:
    -> The board is labeled in Boustrophedon style.
    -> We are allowed to move 1 to 6 steps in each turn (dice roll).
    -> Snakes and ladders act as instant teleporters but only applied once per roll.
    -> A BFS traversal is suitable since we are asked to find the minimum steps.


    // Intrusion:
        -> Model the board as a 1D array from 1 to n².
        -> Convert 1D position to 2D coordinates while respecting Boustrophedon pattern.
        -> Use BFS to find the shortest path to reach n².
        -> Use a visited matrix to avoid re-visiting squares.

    // Approach:
        -> Use a helper function `getCoord()` to convert a cell number to (row, col) on the board.
        -> Initialize a queue and perform BFS starting from cell 1.
        -> For each cell, roll the dice (from 1 to 6) and check each potential cell:
            -> If it has a snake or ladder, jump to the destination.
            -> If it is not visited, mark it and add to the queue.
        -> Return the number of steps once we reach cell n².

    // Solution:
        -> Use BFS (queue) to simulate every possible dice move from the current cell.
        -> Use a visited matrix to avoid revisiting cells.
        -> Track how many steps it takes to reach the last cell.


// Complexity: 
    -> TC: O(n * n)
    -> SC: O(n * n)
        


    
// Extra: 

    -> Let say we have matrix given of dimensions (n * m) with cell number (1 to (n * m))
    -> Example: 

        (0,0) => 1   (0,1) => 2   (0,2) => 3   (0,3) => 4
        (1,0) => 5   (1,1) => 6   (1,2) => 7   (1,3) => 8
        (2,0) => 9   (2,1) => 10  (2,2) => 11  (2,3) => 12

    // Convert CellNumber from given row & col:
        
        cellNumber = row * m + col + 1;

    // Convert row & col from given cellNo: 

        row = (cellNumber - 1) / m;
        col = (cellNumber - 1) % m;


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;



class Solution {
private: 
    int n;
    // Convert 1D cell number to 2D coordinates in Boustrophedon style
    pair<int, int> getCoord(int num) {  // Using cellNumber we can generate the row & col:
        // row from top: 
        int RT = (num - 1) / n; // with this formula we can get the "row number from top" using cellNumber

        int RB = (n - 1) - RT;  // subtracting from (n - 1) will get the "row number from bottom"


        int col = (num - 1) % n;    // get the column number from left to right

        // Check whether we have to move right to left || left to right by checking "n" & "RB"
        // if our cellNumbers are from right to left -> subtract col from (n - 1) to get the correct order
        if((n % 2 == 1 && RB % 2 == 1) || (n % 2 == 0 && RB % 2 == 0)) {    // right to left: if (n & RB) both are odd OR both are even
            col = (n - 1) - col;
        }

        return make_pair(RB, col);
    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();

        vector<vector<int>> vis(n, vector<int>(n, 0)); // Visited cells
        queue<int> q;
        q.push(1);  // Start at cell 1

        vis[n - 1][0] = 1;  // Mark starting cell as visited
        int steps = 0;      // Count number of dice rolls

        while (!q.empty()) {
            int size = q.size();

            // Process all nodes at current step level
            while (size--) {
                int curr = q.front();
                q.pop();

                // If we reached the end cell
                if (curr == n * n) return steps;

                // Try all dice rolls (1 to 6)
                for (int dice = 1; dice <= 6; dice++) {
                    int next = curr + dice;

                    if (next > n * n) break;  // Skip out-of-bound

                    auto [r, c] = getCoord(next);

                    if (vis[r][c]) continue;  // Skip already visited
                    vis[r][c] = 1;            // Mark as visited

                    // Move to snake/ladder destination if present
                    if (board[r][c] == -1) {
                        q.push(next);
                    } else {
                        q.push(board[r][c]);
                    }
                }
            }

            steps++; // Increase step after processing current level
        }

        return -1; // Not reachable
    }
};
