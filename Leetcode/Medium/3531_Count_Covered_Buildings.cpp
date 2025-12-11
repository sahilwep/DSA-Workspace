/*

//  3531. Count Covered Buildings


//  Problem Statement: 
    - You are given a positive integer n, representing an n x n city. You are also given a 2D grid buildings, where buildings[i] = [x, y] denotes a unique building located at coordinates [x, y].
    - A building is covered if there is at least one building in all four directions: left, right, above, and below.
    - Return the number of covered buildings.

 
// Example:
    Example 1:
        Input: n = 3, buildings = [[1,2],[2,2],[3,2],[2,1],[2,3]]
        Output: 1
        Explanation: Only building [2,2] is covered as it has at least one building:
                above ([1,2])
                below ([3,2])
                left ([2,1])
                right ([2,3])
            Thus, the count of covered buildings is 1.

    Example 2:
        Input: n = 3, buildings = [[1,1],[1,2],[2,1],[2,2]]
        Output: 0
        Explanation: No building has at least one building in all four directions.

    Example 3:
        Input: n = 5, buildings = [[1,3],[3,2],[3,3],[3,5],[5,3]]
        Output: 1
        Explanation: Only building [3,3] is covered as it has at least one building:
                above ([1,3])
                below ([5,3])
                left ([3,2])
                right ([3,5])
            Thus, the count of covered buildings is 1.


// Observations: 
    - give n x n size grid
    - given coordinates of buildings [i, j]
    - we need to find the number of total number of covered buildings.
    - covered building is a building that is covered from all 4 sides..
    
    // Bruteforce Approach:
        - initialize grid of size (n * n) & fill the coordinates.
        - after that for every given building check all 4 sides & if all 4 sides has building, means covered building..
        - falls into TLE


    // Efficient Approach:
        - for every covered building all (up & down) & (left & right) need to be building.
        - We can use hashing to hash rows & cols index:
        - for every rows:
            - for every rows index, wherever we have building in that row[] -> we need leftmost & rightmost building locations so that we can check..
        - similarly for every cols:
            - for every cols index, wherever we have build in that cols[] -> we need topmost & bottommost building locations so that we can check...
        - Once we have all the rows & cols hashed, we can check for every coordinates up, down, left, right..
            - if all have buildings in all the sides, we can count it as covered building...
        - I have analyze this all on paper & try to solve this on paper, we can understand this efficient approach very well..


        // Complexity: 
            - TC: O(k)
            - SC: O(k)
                - k = buildings.size(), we worse it can be 'n', but more precise 'k'


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Efficient Approach:
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        // hash the given coordinates:
        unordered_map<int, pair<int, int>> cols;
        unordered_map<int, pair<int, int>> rows;
        for(auto &it: buildings) {  // TC: O(k)
            int x = it[0], y = it[1];

            // Fill Rows:
            if(rows.count(x)) {
                rows[x].first = min(y, rows[x].first);
                rows[x].second = max(y, rows[x].second);
            } else {
                rows[x].first = y;
                rows[x].second = y;
            }


            // Fill Cols:
            if(cols.count(y)) {
                cols[y].first = min(x, cols[y].first);
                cols[y].second = max(x, cols[y].second);
            } else {
                cols[y].first = x;
                cols[y].second = x;
            }
        }

        // Debugging:
        // cout << "cols: " << endl;
        // for(auto &[key, val]: cols) {
        //     cout << key << ": " << val.first << ", " << val.second << endl;
        // }

        // cout << endl << "rows: " << endl;
        // for(auto &[key, val]: rows) {
        //     cout << key << ": " << val.first << ", " << val.second << endl;
        // }


        // Compute & check:
        int ans = 0;
        for(auto &it: buildings) {  // TC: O(k)
            int x = it[0], y = it[1];
            
            // cols: up & down
            int up = cols[y].first;
            int down = cols[y].second;
            if(up == down) continue;    // same up & down, skip
            
            // rows: left & right
            int left = rows[x].first;
            int right = rows[x].second;
            if(left == right) continue; // same left & right, skip

            // Compute the covered building:
            if(up < x && x < down && left < y && y < right) {
                ans++;
            }
        }

        return ans;
    }
};


// Bruteforce Approach:
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        
        // build the given grid:
        vector<vector<int>> grid(n, vector<int> (n, 0));
        for(auto &it: buildings) {
            int i = it[0] - 1, j = it[1] - 1;
            grid[i][j] = 1;
        }

        // Now find the covered buildings:
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    // Check up:
                    bool up = false;
                    for(int k = i - 1; k >= 0; k--) {
                        if(grid[k][j] == 1) {
                            up = true;
                            break;
                        }
                    }

                    // check down:
                    bool down = false;
                    for(int k = i + 1; k < n; k++) {
                        if(grid[k][j] == 1) {
                            down = true;
                            break;
                        }
                    }

                    // check left:
                    bool left = false;
                    for(int k = j - 1; k >= 0; k--) {
                        if(grid[i][k] == 1) {
                            left = true;
                            break;
                        }
                    }

                    // check right:
                    bool right = false;
                    for(int k = j + 1; k < n; k++) {
                        if(grid[i][k] == 1) {
                            right = true;
                            break;
                        }
                    }

                    // Check answer:
                    if(up == 1 && down == 1 && left == 1 && right == 1) {
                        ans++;
                    }
                }
            }
        }

        return ans;
    }
};