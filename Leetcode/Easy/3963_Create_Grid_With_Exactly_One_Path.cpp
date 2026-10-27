/*

//  3963. Create Grid With Exactly One Path


//  Problem Statement: 
    - You are given two integers m and n, representing the number of rows and columns of a grid.
    - Construct any m x n grid consisting only of the characters '.' and '#', where:
        '.' represents a free cell.
        '#' represents an obstacle cell.

    - A valid path is a sequence of free cells that:
        - Starts at the top-left cell (0, 0).
        - Ends at the bottom-right cell (m - 1, n - 1).
        - Moves only:
            - Right, from (i, j) to (i, j + 1), or
            - Down, from (i, j) to (i + 1, j).

    - Return any grid such that there is exactly one valid path from the top-left cell to the bottom-right cell.



//  Example:
    Example 1:
        Input: m = 2, n = 3
        Output: ["..#","#.."]
        Explanation: The only valid path is: (0,0) → (0,1) → (1,1) → (1,2)

    Example 2:
        Input: m = 3, n = 3
        Output: ["..#","#..","##."]
        Explanation: The only valid path is: (0,0) → (0,1) → (1,1) → (1,2) → (2,2)

    Example 3:
        Input: m = 1, n = 4
        Output: ["...."]
        Explanation: The only valid path is: (0,0) → (0,1) → (0,2) → (0,3)



        
// Observations:
    - given n and m
    - we will have to construct a grid that is having only single path from (0, 0) to (n - 1, m - 1)
    - we have '.' which is empty path, and '#' which is obstacle.

    // Approach:
        - initially all the cells are empty
        - we will try to find the path that reaches to (n - 1, m - 1), and somehow mark that cell as visited, and rest of the cell will be assigned with '#'
        - We can use any dfs/bfs.
        - We only have two move: right, down.
        - We only need to find a single path for which we find the destinations, and somehow mark them as visited, so that we can track that this is our valid path.


        // Complexity:
            - TC: O(n * m)
            - SC: O(n * m)

        // Extra:
            - we can also write BFS Solution, 
            - we can store the whole path into queue while exploring, 
            - and once we reach to destinations, we can mark all that places as '.' and rest with '#'





*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Cleaner DFS:
class Solution {
private:
    int n, m;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}};  // dir: right, down
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool dfs(int row, int col, vector<string>& path) {
        path[row][col] = '.';
        if(row == n - 1 && col == m - 1) {
            return true;
        }
        
        // Explore in all 2 directions:
        for(auto &[x, y]: dir) {
            int r = row + x;
            int c = col + y;

            if(isValidDim(r, c)) {
                if(dfs(r, c, path)) return true;

            }
        }

        // the path where we won't find the destinations, we mark mark it as false, or reset the value..
        path[row][col] = '#';    // unmark it again.
        return false;
    }
public:
    vector<string> createGrid(int n_, int m_) {
        n = n_;
        m = m_;

        vector<string> path(n, string(m, '#'));
        dfs(0, 0, path);

        return path;
    }
};




// BFS:
class Solution {
    int n, m;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}};  // dir: right, down.
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 &&c < m);}
public:
    vector<string> createGrid(int n_, int m_) {
        n = n_;
        m = m_;
        queue<vector<pair<int, int>>> q;

        q.push({{0, 0}});

        vector<string> ans(n, string(m, '#'));  // prefield with '#'

        while(!q.empty()) {
            int size = q.size();
            bool isDestFound = false;
            while(size--) {
                auto seq = q.front();
                q.pop();

                auto cor = seq.back();  // get the coordinates from the sequence, last one.
                int row = cor.first;
                int col = cor.second;


                // reaches to destinations:
                if(row == n - 1 && col == m - 1) {
                    for(auto &[row, col]: seq) {
                        ans[row][col] = '.';    // mark that path as valid to travel.
                    }

                    isDestFound = true;
                    break;
                }

                // Explore in all 2 directions:
                for(auto &[x, y]: dir) {
                    int r = row + x;
                    int c = col + y;

                    if(isValidDim(r, c)) {
                        seq.push_back({r, c});
                        q.push(seq);
                        seq.pop_back();
                    }
                }
            }

            if(isDestFound) break;
        }

        for(auto &rows: ans) {
            for(auto &i: rows) cout << i << " ";
            cout << endl;
        }

        return ans;
    }
};


// DFS
class Solution {
private:
    int n, m;
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}};  // dir: right, down
    bool isValidDim(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    bool dfs(int row, int col, vector<vector<int>>& vis) {
        vis[row][col] = 1;
        if(row == n - 1 && col == m - 1) {
            return true;
        }
        
        for(auto &[x, y]: dir) {
            int r = row + x;
            int c = col + y;

            if(isValidDim(r, c)) {
                if(dfs(r, c, vis)) return true;

            }
        }

        vis[row][col] = 0;
        return false;
    }
public:
    vector<string> createGrid(int n_, int m_) {
        n = n_;
        m = m_;

        vector<vector<int>> grid(n, vector<int>(m, 0));
        dfs(0, 0, grid);


        // Build path;
        vector<string> ans;
        for(auto &rows: grid) {
            string temp = "";
            for(auto &i: rows) {
                if(i == 0) {
                    temp.push_back('#');
                } else {
                    temp.push_back('.');
                }
            }
            ans.push_back(temp);
        }

        return ans;
    }
};