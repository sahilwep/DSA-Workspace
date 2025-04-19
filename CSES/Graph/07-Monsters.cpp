/*

//  CSES: Monsters


//  Problem Statement: 
    -> You and some monsters are in a labyrinth. When taking a step to some direction in the labyrinth, each monster may simultaneously take one as well. Your goal is to reach one of the boundary squares without ever sharing a square with a monster.
    -> Your task is to find out if your goal is possible, and if it is, print a path that you can follow. Your plan has to work in any situation; even if the monsters know your path beforehand.

// Input
    -> The first input line has two integers n and m: the height and width of the map.
    -> After this there are n lines of m characters describing the map. Each character is . (floor), # (wall), A (start), or M (monster). There is exactly one A in the input.

// Output
    -> First print "YES" if your goal is possible, and "NO" otherwise.
    -> If your goal is possible, also print an example of a valid path (the length of the path and its description using characters D, U, L, and R). You can print any path, as long as its length is at most n \cdot m steps.

// Constraints

    1 <= n,m <= 1000

// Example
    Input:
        5 8
        ########
        #M..A..#
        #.#.M#.#
        #M#..#..
        #.######

    Output:
        YES
        5
        RRDDR

    Input: 
        8 8
        ###MMMMM
        #.AMMMMM
        #.#MMMMM
        #.#MMMMM
        #.#MMMMM
        #.#MMMMM
        #..MMMMM
        #.#MMMMM
    Output:
        NO
    
    Input:
        8 8
        ########
        #.....A#
        #.######
        #......#
        #.####.#
        #....#.#
        #.##.#.#

    Output: 
        NO

    Input:
        8 8
        ########
        #.....A#
        #.######
        #......#
        #.####.#
        #....#.#
        #.##.#.#
        #.#M.#.#
    Output:
        YES
        16
        LLLLLDDRRRRRDDDD


            Observations: 

                    Grid                    Monster                                 Human
                # # # # # # # #         # #  #  #  #  #  #  #                 #  #  #  #  #  #  #  #
                # . . . . . A #         # 10 11 12 13 14 15 #                 #  5  4  3  2  1  A  #
                # . # # # # # #         # 9  #  #  #  #  #  #                 #  6  #  #  #  #  #  #
                # . . . . . . #         # 8  9  10 11 12 13 #                 #  7  8  9 10  11 12 #
                # . # # # # . #         # 7  #  #  #  #  14  #                #  8  #  #  #  #  13 #
                # . . . . # . #         # 6  5  4  3  #  15  #                #  9  10 11 12 #  14 #
                # . # # . # . #         # 7  #  #  2  #  16  #                #  10 #  #  13 #  15 #
                # . # M . # . #         # 8  #  M  1  #  17  #                #  11 #  M  14 #  16 #

        -> Human is always 1 step forward to monster..

    Input: 
        15 15
        ###############
        #M#...#...#...#
        #A#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #.#.#.#.#.#.#.#
        #...#...#...#.#
        #############.#

    Output: 
        YES
        96
        DDDDDDDDDDDRRUUUUUUUUUUUURRDDDDDDDDDDDDRRUUUUUUUUUUUURRDDDDDDDDDDDDRRUUUUUUUUUUUURRDDDDDDDDDDDDD






// Observations: 
    -> Question depicts like "Rotten Oranges" question pattern.
        -> Multisource BFS.

    -> Directions: we can move in all possible 4 directions:

                                               [-1, 0]
                                                 |
                                    [0, -1] <- [0, 0] -> [0, 1]
                                                 |
                                               [1, 0]

    -> Store parent path & directions of every cell.
    -> While backtracking the original path to source, we can store the path, & reversed to get the original path to exit..

    // Approach:
        -> Flood the grid with monster path.
        -> Now Compute human path reaching destinations with lesser time than the monster.
            -> Whenever we reaches to boundary cell: 
                -> Backtrack to the original source & print that path.


// Complexity: 
    -> TC: O(n * m) + O(n * m) + O(n * m)   => O(n * m)
        -> First for flooding monster throughout the grid.
        -> Second for Exploring human reaching any boundary cell
        -> Third for backtracking entire grid, in worse case..
    -> SC: O(n * m)
        -> AS: O(n * m ) -> BFS computations.

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Solution:
class Solution {
private: 
    typedef pair<int, int> pr;
    typedef pair<int, pr> ppr;
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // dir: left, right, up down
    char dirL[4] = {'L', 'R', 'U', 'D'};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
public: 
    void solve(vector<vector<char> > &grid, int huStartRow, int huStartCol) {
        n = grid.size(), m = grid[0].size();

        // Multi-Sourced BFS: 
        // Step 1: Compute Master path:
        vector<vector<int> > mostPath(n, vector<int> (m, 1e9)); // mark that monster path as infinite
        vector<vector<int> > vis(n, vector<int> (m, 0));
        queue<ppr> q;

        // Push all the monster source into the the queue:
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'M') {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        // Process queue & fill monsters levels: 
        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            mostPath[row][col] = lvl;

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c] && grid[r][c] == '.') {  // valid bound, Not yet visited, & valid path.
                    vis[r][c] = 1;
                    q.push({lvl + 1, {r, c}});
                }
                
            }
        }

        // Step 2: Now process Human Path & return our answer: 
        for(auto &rows: vis) {
            for(auto &i: rows) i = 0;
        }
        while(!q.empty()) q.pop();


        vector<vector<pr> > parent(n, vector<pr> (m, {-1, -1}));    // This will store the parent path
        vector<vector<char> > path(n, vector<char> (m, 'X'));       // this will store the directions like 'U', 'R'...


        q.push({0, {huStartRow, huStartCol}});
        vis[huStartRow][huStartCol] = 0;
        parent[huStartRow][huStartCol] = {huStartRow, huStartCol};


        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            // Destinations Check: 
            if(row == 0 || row == n - 1  || col == 0 || col == m - 1) {
                cout << "YES" << endl << lvl << endl;

                // backtrack into parent & get the path:
                string way = "";
                int lRow = row, lCol = col;
                
                while(lRow != huStartRow || lCol != huStartCol) {
                    way += path[lRow][lCol];     // Store directions

                    // Update new backtracking path.
                    auto [pr, pc] = parent[lRow][lCol];
                    lRow = pr;
                    lCol = pc;
                }
                
                reverse(begin(way), end(way));
                cout << way << endl;

                return; // return from function call
            }

            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c] && grid[r][c] == '.') {  // valid bound, Not yet visited, & valid path.
                    // Now check human reaching at any cell should be lesser than monster or not?
                    if(lvl + 1 < mostPath[r][c]) {
                        path[r][c] = dirL[i];           // store the path
                        parent[r][c] = {row, col};      // store the parent
                        
                        vis[r][c] = 1;                  // mark as visited
                        q.push({lvl + 1, {r, c}});      // push that coordinates & level into queue.
                    }
                }
            }
        }

        cout << "NO" << endl;   // Human not reaching to end:
    }
};

int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char> (m));

    int sr, sc;
    for(int i = 0; i < n ;i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if(grid[i][j] == 'A') {
                sr = i;
                sc = j;
            }
        }
    }

    Solution obj;
    obj.solve(grid, sr, sc);


    return 0;
}