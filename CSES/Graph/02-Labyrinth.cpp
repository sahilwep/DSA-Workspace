/*

//  CSES: Labyrinth


// Observation:
    -> We have to find the shortest path from A to B.
    -> if we are reachable to the destination, we will print "YES" : otherwise "NO"
    -> also we need to find the path, means direction also.


// Example

    Input:
        5 8
        ########
        #.A#...#
        #.##.#B#
        #......#
        ########
    
    Output:
        YES
        9
        LDDRRRRRU


// Observations: 
    -> we need to find the shortest path b/w 'A' & 'B'
    -> if it's reachable print "YES", Steps to reach that path, & directions in which we are traveling the path.
    -> BFS will find the shortest path, because it's proceeding level wise, & whenever we got the result for the first, that is our shortest path.


// Bruteforce Approach:
    -> For bruteforce approach, we use BFS normal queue with structure: <cost, <directions, <row, col>>>
    -> This leads to TLE, because we are processing the string inside the queue & when the iteration will be large, string concatenation will leads to TLE.


// Efficient Approach:
    -> Instead of storing the cost & path inside the queue, what we can do, we will store them into any outside another container, & queue structure will be handling only [row, col]
    -> This will reduce the time complexity, by not concenating the string everytimes.
    -> Also, we will fix the extra line of logic to get the directions, by simplifying it with normal array.
    -> TC: O(n * m)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Approach:


class Solution {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    char moves[4] = {'L', 'R', 'U', 'D'};
    
    bool isValid(int r, int c) {
        return (r >= 0 && r < n  && c >= 0 && c < m);
    }
public:
    void path(vector<vector<char>> &grid, int sr, int sc, int dr, int dc) {
        n = grid.size();
        m = grid[0].size();
        
        // finding the path using BFS:
        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>> (m, {-1, -1}));  // Storing the parent coordinates
        vector<vector<char>> direction(n, vector<char>(m)); // store the direction.
        queue<pair<int, int>> q;    // queue
        int isFound = false;
        
        q.push({sr, sc});
        vis[sr][sc] = 1;
        
        
        while(!q.empty()) {
            auto [row, col] = q.front();
            q.pop();
            
            bool isFoundToBreak = false;
            
            // explore adjacent nodes:
            for(int i = 0; i < 4; i++) {
                
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                // Check all necessary conditions:
                if(isValid(r, c) && !vis[r][c] && (grid[r][c] == '.' || grid[r][c] == 'B')) {
                    vis[r][c] = 1;  // mark that path as visited.
                    parent[r][c] = {row, col};  // store the parent locations for every cell, where they are coming from.
                    direction[r][c] = moves[i];
                    q.push({r, c});
                    
                    // Check wether we reach to destinations or not?
                    if(grid[r][c] == 'B') {
                        isFoundToBreak = true;
                        isFound = true;
                        break;
                    }
                    
                    
                }
            }
            if(isFoundToBreak) {
                break;
            }
        }
        
        // When we found the path:
        if(isFound) {
            // Backtrack to the parent grid & print the path:
            cout << "YES" << endl;
            string path;
            int r = dr, c = dc; // Declare this variable 
            
            while(r != sr || c != sc) {
                path += direction[r][c];   // store the path from direction grid.
                
                // Now, changing to their parent of current cell
                auto [pr, pc] = parent[r][c];
                r = pr;
                c = pc;
            }
            
            reverse(begin(path), end(path));
            cout << path.size() << endl;
            cout << path << endl;
        }
        else{   // else print NO:
            cout << "NO" << endl;
        }
    }
};


// BruteForce Approach:
class Solution_Brute {
private:
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    // location:      left      righ   up,    down
    bool isValid(int r, int c) {return (r >= 0 && r < n  && c >= 0 && c < m);}
public:
    void path(vector<vector<char>> &grid, int sr, int sc, int dr, int dc) {
        n = grid.size();
        m = grid[0].size();
        
        // finding the path using BFS:
        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<pair<int, pair<string, pair<int, int>>>> q;
        bool isFound = false;
        int pathCost = -1;
        string foundPath = "";
        
        q.push({0,{"", {sr, sc}}});
        vis[sr][sc] = 1;
        
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            
            int cost = it.first;
            string way = it.second.first;
            int row = it.second.second.first;
            int col = it.second.second.second;
            
            bool isFoundToBreak = false;
            
            // explore adjacent nodes:
            for(int i = 0; i < 4; i++) {
                int dirRow = dir[i][0];
                int dirCol = dir[i][1];
                
                int r = row + dirRow;
                int c = col + dirCol;
                
                // Check all the necessary conditions:
                if(isValid(r, c) && !vis[r][c] && (grid[r][c] == '.' || grid[r][c] == 'B')) {
                    
                    // first find out the directions that we have taken:
                    char move;
                    if(dirRow == 0 && dirCol == -1) {
                        move = 'L';
                    }else if(dirRow == 0 && dirCol == 1) {
                        move = 'R';
                    }else if(dirRow == -1 && dirCol == 0) {
                        move = 'U';
                    }else if(dirRow == 1 && dirCol == 0) {
                        move = 'D';
                    }
                    
                    // Check if we reach to final destination or not?
                    if(grid[r][c] == 'B') {
                        isFound = true;
                        isFoundToBreak = true;
                        pathCost = cost + 1;
                        way += move;    // first update with the directions that we have taken.
                        foundPath = way;    // now update in the way.
                        break;
                    }
                    
                    // last mark path as visited & push that new path into the queue.
                    vis[r][c] = 1;  // mark that path as visited.
                    q.push({cost + 1, {way + move, {r, c}}}); // move next direction to queue.
                    
                }
            }
            if(isFoundToBreak) {
                break;
            }
        }
        
        if(isFound) {
            cout << "YES" << endl << pathCost << endl << foundPath << endl;
            
        }else{
            cout << "NO" << endl;
        }
    }
};


int main(){
    
    int n, m;
    cin >> n >> m;
    
    int sr, sc, dr, dc;
    vector<vector<char>> grid(n, vector<char> (m));
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> grid[i][j];
            
            if(grid[i][j] == 'A') {
                sr = i;
                sc = j;
            }
            if(grid[i][j] == 'B') {
                dr = i;
                dc = j;
            }
        }
    }
    
    Solution obj;
    obj.path(grid, sr, sc, dr, dc);
    
    return 0;
}