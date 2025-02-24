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


// Observations: 
    -> Question depicts like "Rotten Oranges" question pattern.
    -> Directions: we can move in all possible 4 directions:

                                               [-1, 0]
                                                 |
                                    [0, -1] <- [0, 0] -> [0, 1]
                                                 |
                                               [1, 0]


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
int n, m;   // dimensions
int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // corresponding coordinates from (0,0)
int path[4] = {'L', 'R', 'U', 'D'}; // path corresponding to the directions.
typedef pair<int, int> pr;
bool isValid(int r, int c) {
    return (r >= 0 && r < n && c >= 0 && c < m);    // function to check valid bound.
}
public:
    void solve(vector<vector<char> > &grid, int sr, int sc) {   // function to check valid possible cases:
        n = grid.size();
        m = grid[0].size();

        vector<vector<int> > vis(n, vector<int> (m, 0)); // visited array
        queue<pr> q;

        q.push(make_pair(sr, sc));   // first push human into queue.

        // Initially push all the monster into the queue:
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 'M'){
                    vis[i][j] = 1;  // mark all the monster as visited.
                    q.push(make_pair(i, j)); // inserting them into queue.
                }
            }
        }

        int level = 0;
        // Process all of them Simultaneously:
        while(!q.empty()) {
            int size  = q.size();

            // process every level individually:
            while(size--) {
                auto [row, col] = q.front();
                q.pop();

                // Explore in all possible directions: 
                for(int i = 0; i < 4; i++) {
                    int r = dir[i][0];
                    int c = dir[i][1];

                    // if out of bound, return true:
                    if(!isValid(r, c)) {
                        cout << "YES" << endl;
                        cout << level << endl;
                        return;
                    }
                    // cases for valid bound & remaining case for traversal for further possible conditions..
                    else {
                        // Leftover conditions: 
                        // we will have to handel monster & human individually.
                        // also we need to take care of the path when monster & human move..
                        // and some more valid traversal conditions that we need in considerations..



                    }
                }
            }

            level++;
        }

        cout << "IMPOSSIBLE" << endl;
    }

};


int main(){

    int n, m;
    cin >> n >> m;
    vector<vector<char> > grid(n, vector<char> (m));

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