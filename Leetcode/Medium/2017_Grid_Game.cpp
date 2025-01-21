/*

//  2017. Grid Game

//  Problem Statement: 
    -> You are given a 0-indexed 2D array grid of size 2 x n, where grid[r][c] represents the number of points at position (r, c) on the matrix. Two robots are playing a game on this matrix.
    -> Both robots initially start at (0, 0) and want to reach (1, n-1). Each robot may only move to the right ((r, c) to (r, c + 1)) or down ((r, c) to (r + 1, c)).
    -> At the start of the game, the first robot moves from (0, 0) to (1, n-1), collecting all the points from the cells on its path. For all cells (r, c) traversed on the path, grid[r][c] is set to 0. Then, the second robot moves from (0, 0) to (1, n-1), collecting the points on its path. Note that their paths may intersect with one another.
    -> The first robot wants to minimize the number of points collected by the second robot. In contrast, the second robot wants to maximize the number of points it collects. If both robots play optimally, return the number of points collected by the second robot.


// Observation: 
    -> we can start from {0, 0}
    -> either we can move only left or only down,
    -> We can't move right & up, 
    -> Once we move down, we will have to collect all the points till end.

// Observation:
        ->  we exactly traverse 'n' cells in path.

        -> First robot want's to minimize the points collected by first robot.
        -> it has no greed to collect maximum path, but it has greed to move on that path, so that when robot2 will move, it will collect minimum point possible, & Both robot play optimally.


        -> If we observe the pattern, robot 1 will try to minimize the point of robot 2:
        -> Robot 2 will play optimally -> In every strategy that robot 1 takes, robot 2 will chose max whatever he has got.
        -> Robot 1 will play first:
            -> Robot 1 move depends how much point robot 2 will get.
            -> if we have long list of data, & if robot 1 will move down somewhere in middle by choosing the optimal move, robot 2 have only 2 way to go with either he move down before the mid or he will collect all the upper row points.
            -> Thinks it as prefix sum & suffix sum:
                    
                        [2,5,4] firstRowSum = 11
                        [1,5,1] secondRowSum = 7
                                secondRowRemainingSum => This one we also need to maintain, when we have cases to choose for robot 2, this will help there.
                
                Case 1: if Robot 1 move down at index 0:

                        2 + 7 = 9 => Robot 1 points
                        11 - 2 = 9 => Robot 2 points

                Case 2: if Robot 1 move down at index 2:

                        2 + 5 + 5 + 1 = 13 => Robot 1 points
                        Robot 2: options: 
                            11 - 2 - 5 = 4
                            7 - 5 - 1 = 1
                                Robot 2 will choose '4' maximum among all the possible path.

                Case 3: if Robot 1 move down at index 2:
                        11 + 1 = 12 => Robot 1 points
                        7 - 1 = 6 => Robot 2 points

                Now, for all the three cases, robot 1 will choose those path that bring robot 2 the minimum points possible.
                So minimum points he get as 3: 

            -> In simple, we will maintain: firstRowSum => This will help us to iterate & find the remaining sum from first row.
            -> We will maintain remainingFirstRowSum => This will store the remaining sum for first row, when we move down.
            -> We will maintain remainingSecondRowSum => This will store the remaining sum for second row, when we not move down for certain index, this sum will store the sum value till that index.
            -> & We need to choose the maximum among the remainingFirstRowSum & remainingSecondRowSum for robot 2
            -> And from both of them we will take minimum form all possible cases.


// Complexity: 
    -> TC: O(n)
    -> SC: O(1)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

typedef long long ll;
class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();    // that's the grid size we will travel:

        ll firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
        ll secondRowRemainSum = 0;

        long long minimizedRobot2Sum = LONG_LONG_MAX;

        for(int r1 = 0; r1 < n; r1++){
            // Robot 1 tooks this strategy:
            firstRowRemainSum -= grid[0][r1];

            // Robot 2 will try to do best after robot 1, has taken above strategy:
            // this is what robot2 got: max(firstRowRemainSum, secondRowRemainSum)
            ll bestOfR2 = max(firstRowRemainSum, secondRowRemainSum);


            // robot 1, will choose min among all the cases:
            minimizedRobot2Sum = min(minimizedRobot2Sum, bestOfR2);

            // Add remaining Value into seconRowRemaining:
            secondRowRemainSum += grid[1][r1];
        }


        return minimizedRobot2Sum;
    }
};