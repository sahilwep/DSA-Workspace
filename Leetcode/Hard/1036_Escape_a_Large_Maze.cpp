/*

//  1036. Escape a Large Maze


//  Problem Statement: 
    - There is a 1 million by 1 million grid on an XY-plane, and the coordinates of each grid square are (x, y).
    - We start at the source = [sx, sy] square and want to reach the target = [tx, ty] square. There is also an array of blocked squares, where each blocked[i] = [xi, yi] represents a blocked square with coordinates (xi, yi).
    - Each move, we can walk one square north, east, south, or west if the square is not in the array of blocked squares. We are also not allowed to walk outside of the grid.
    - Return true if and only if it is possible to reach the target square from the source square through a sequence of valid moves.

 
// Example:
    Example 1:
        Input: blocked = [[0,1],[1,0]], source = [0,0], target = [0,2]
        Output: false
        Explanation: The target square is inaccessible starting from the source square because we cannot move.
        We cannot move north or east because those squares are blocked.
        We cannot move south or west because we cannot go outside of the grid.

    Example 2:
        Input: blocked = [], source = [0,0], target = [999999,999999]
        Output: true
        Explanation: Because there are no blocked cells, it is possible to reach the target square.


// Observation:
    - given grid of size 1_million x 1_million on x-y plane.
    - given source and target
    - given blocked: considering blocked cells..
        - we will have to reach destinations from src coordinates without passing any blocked coordinates.
    - if it's possible return true.
    - else return false.


    // Approach:    
        - src and target is given
        - we can move in all 4 directions..
        - it's just we are given extra blocked, which we have to check..
        - we will try reaching destinations without falling into blocked coordinates..
        - if it's possible return true.
        - else return false.
        - to explore all the possible node, we wil use BFS, as moving from one cell to another is constant, and using bfs we can find wether it's possibe or not

        - we will have to optimize the lookup for blocked coordinates, as we explore further..
            - we can optimage this by inserting into set.

        - Exploration in all 4 directions:

                           ^
                           |
                  <------[x, y] ----->
                           |
                           V

                    - we can iterate in all 4 directions
                    - we will have to check the valid coordinates:
                        x >= 0 && y >= 0 


                        *               |
                                        |
                        ----------------|


                                            *


        - Plain BFS -> gives TLE as path can have large path to explore..


        -> Optimizations:
            - we will have to find the cycle around the src or target
            - if there's a cycle around the src or target, it's not possible to reach from src to target.
            - it is noticed that the circle wrt manhattan distance in fact a diamond.
                - since there are at most b = 200 blocked grid.
                - we can write bfs/dfs for solving 1M^2 size maze, either up to (b (b + 1) / 2) visited grid, or up to manhattan distance to the initial point larger or equal to B.

            // In simple:
                - we will process the same BFS
                - it's just we will have to check the blocked range:
                    - How can BFS know whether we are trapped?
                        - this is where range comes in, suppose we have b = 4 cells.
                        - we perform BFS, and eventually BFS stops:
                            - queue become empty, then obviously source was trapped.
                        - But, Suppose BFS keep expanding:
                                        .
                                      . . .
                                    . . S . .
                                      . . .
                                        .

                        - how long should we continue?
                            - we obviously cna't continue until reaching the other point because the destinations might be: [900000, 900000]
                            - Thats defeats the whole purpose.
                        - So we ask a different question, with b blocked cells, what is the max number of open cell they could possibly trap?
                        - If the maximum is say 19,900, and our bfs has already visited 19,901 cells:
                        - Then there is important conclusion:
                        - There's no way these 200 blocker have enclosed me, because no enclosure made from 200 blockers could contains this many cells.
                        - Therefore we can stop BFS and say RETURN TRUE.


                        - Now let's see how we can compute the diagonal wall?

                                            GRID BOUNDARY
                                            ↓
                                            +----------------------
                                            | . . . . B
                                            | . . . B
                                            | . . B
                                            | . B
                                            | B
                                            |
                                            ↑
                                            GRID BOUNDARY

                            - blockers forming a diagonal wall.
                            - one efficient way to trap a large number of cells with very few blocked cells is to take advantage of the grid boundary.
                            - The boundary itself acts like a giant free wall.
                            - The B from the diagonal barrier, while the top/left edges of the grid provide the other walls for free.
                            - This triangular arrangement gives the important bound.
                                - Imagine we have blockers arranged so the trapend region grows like triangle.
                                - with each additional blocker, we can potentially add another "row", of cells to the enclosed area
                                - The row have size aproxy:
                                    1
                                    2
                                    3
                                    4
                                    5
                                    ...
                                    b - 1

                                    So, maximum enclosed cells are bounded by:
                                        1 + 2 + 4 + ... + (b - 1)
                                    
                                    1 + 2 + 3 + 4 + 5 + .. + n  => n * (n + 1) / 2
                                    
                                    n = b - 1

                                        (b - 1) ((b - 1)  + 1) / 2
                                        (b - 1) * b / 2
                                        range = b * (b - 1) / 2



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized Solution:
class Solution {
private:
    bool isValidDim(int r, int c) {return (r >= 0 && r < 1000000 && c >= 0 && c < 1000000);}  // both should be in positive coordinates..
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
    bool bfs(int row, int col, int range, set<pair<int, int>>& st, vector<int>& dst) {
        // process BFS:
        queue<pair<int, int>> q;
        set<pair<int, int>> vis;

        q.push({row, col});
        vis.insert({row, col});

        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            if(vis.size() > range) return true;

            // reached at destinations:
            if(row == dst[0] && col == dst[1]) return true;     // reached destinations..
            
            // Explore in all 4 directions:
            for(auto &[x, y]: dir) {
                int r = row + x;
                int c = col + y;

                // if valid dimension, and not yet visited, and not in 
                if(isValidDim(r, c) && !st.count({r, c}) && !vis.count({r, c})) {
                    q.push({r, c});
                    vis.insert({r, c}); 
                }
            }
        }

        return false;   // not possible..
    }
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& src, vector<int>& dst) {

        if(blocked.empty()) return true;

        // Push all the blocked into set:
        set<pair<int, int>> st;
        for(auto &i: blocked) {
            st.insert({i[0], i[1]});
        }

        // Edge cases:
        if(src[0] == dst[0] && src[1] == dst[1]) return true;                       // if src == dst => reached.
        if(st.count({src[0], src[1]}) || st.count({dst[0], dst[1]})) return false;  // if src or dst is blocked -> not possible.


        int b = blocked.size();
        int range = b * (b - 1)/2;

        return bfs(src[0], src[1], range, st, dst) && bfs(dst[0], dst[1], range, st, src);
    }
};


// BruteForce:


class Solution {
private:
    bool isValidDim(int r, int c) {return (r >= 0 && c >= 0);}  // both should be in positive coordinates..
    vector<pair<int, int>> dir = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};    // dir: left, right, above, below.
public:
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& src, vector<int>& dst) {

        if(blocked.empty()) return true;

        // Push all the blocked into set:
        set<pair<int, int>> st;
        for(auto &i: blocked) {
            st.insert({i[0], i[1]});
        }

        // Edge cases:
        if(src[0] == dst[0] && src[1] == dst[1]) return true;                       // if src == dst => reached.
        if(st.count({src[0], src[1]}) || st.count({dst[0], dst[1]})) return false;  // if src or dst is blocked -> not possible.


        int b = blocked.size();
        int range = (b * (b + 1) / 2);

        // process BFS:
        queue<pair<int, int>> q;
        q.push({src[0], src[1]});

        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();
            if(lvl > range) return true; // it can reach, as constrains is only 200, and "(b * (b + 1)/2)"

            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                // reached at destinations:
                if(row == dst[0] && col == dst[1]) return true;     // reached destinations..
                
                // Explore in all 4 directions:
                for(auto &[x, y]: dir) {
                    int r = row + x;
                    int c = col + y;

                    if(isValidDim(r, c)) {
                        if(st.count({r, c})) continue;  // if it's blocked, skip that.

                        // else include that coordinate as possible path:
                        q.push({r, c});

                        st.insert({r, c});  // insert into blocked, as already processed.
                    }
                }
            }

            lvl++;
        }

        return false;   // not possible..
    }
};