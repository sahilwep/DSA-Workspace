/*

//  2258. Escape the Spreading Fire


//  Problem Statement: 
-> You are given a 0-indexed 2D integer array grid of size m x n which represents a field. Each cell has one of three values:
    -> 0 represents grass,
    -> 1 represents fire,
    -> 2 represents a wall that you and fire cannot pass through.
-> You are situated in the top-left cell, (0, 0), and you want to travel to the safehouse at the bottom-right cell, (m - 1, n - 1). Every minute, you may move to an adjacent grass cell. After your move, every fire cell will spread to all adjacent cells that are not walls.
-> Return the maximum number of minutes that you can stay in your initial position before moving while still safely reaching the safehouse. If this is impossible, return -1. If you can always reach the safehouse regardless of the minutes stayed, return 109.
-> Note that even if the fire spreads to the safehouse immediately after you have reached it, it will be counted as safely reaching the safehouse.
-> A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).

//  Example: 
    Example 1:

        Input: grid = [[0,2,0,0,0,0,0],[0,0,0,2,2,1,0],[0,2,0,0,1,2,0],[0,0,2,2,2,0,2],[0,0,0,0,0,0,0]]
        Output: 3

    Example 2:

        Input: grid = [[0,0,0,0],[0,1,2,0],[0,2,0,0]]
        Output: -1

    Example 3:

        Input: grid = [[0,0,0],[2,2,0],[1,2,0]]
        Output: 1000000000


// Observations: 
    -> Given grid of n x m
    -> represent 0 = empty cell, 1 = fire & 2 = obstacle
    -> Human is situated at source (0, 0) & wants to go at destinations (n - 1, m - 1), with a conditions that how much time he can wait at the src cell, so that he won't catch into fire..


// Logic 1 Observations: Fails for multiple Test Cases: 

    // Logic: 
        -> Initial Configure: 
            -> Change given ostrace from 2 to'-1', so that it won't matches with any levels.
        -> Flood the given given with fire level: 
                // Example: 
    
                                    Grid                        Initial Configurations                          Fire
                        [0,  2,  0,  0,  0,  0,  0]          [0,  X,  0,  0,  0,  0,  0]            [6,  X,  4,  3,  2,  1,  2]
                        [0,  0,  0,  2,  2,  1,  0]          [0,  0,  0,  X,  X,  1,  0]            [5,  4,  3,  X,  X,  0,  1]
                        [0,  2,  0,  0,  1,  2,  0]     =>   [0,  X,  0,  0,  1,  X,  0]     =>     [6,  X,  2,  1,  0,  X,  2]           
                        [0,  0,  2,  2,  2,  0,  2]          [0,  0,  X,  X,  X,  0,  X]            [7,  8,  X,  X,  X, 14,  X]
                        [0,  0,  0,  0,  0,  0,  0]          [0,  0,  0,  0,  0,  0,  0]            [8,  9, 10, 11, 12, 13, 14]

        -> Now find the human reaching to destinations with minimum time possible: 
            -> Once we get the human time at the destinations cell:

                -> Flooded view of human levels:
                
                        [0,  X,  4,  5,  6,  7,  8]
                        [1,  2,  3,  X,  X,  8,  9]
                        [2,  X,  4,  5,  6,  X, 10]
                        [3,  4,  X,  X,  X, 10,  X]
                        [4,  5,  6,  7,  8,  9, 10]


        -> Now once we get the arrival time of Human & fire at the destinations, we can build our answer:     
        -> Arrival time at Destinations: 

                    HumanArrivalTime = 10
                    FireArrivalTime = 14
        
        -> We can build our answer: 
                TotalWaitTime = FireArrivalTime - (HumanArrivalTime - 1)
                        -> "-1" because human should always need to be one step ahead of fire

        // Edge Cases 
            -> What if the human is not able to reach the destinations.
            -> What if the fire is not able to reach the destinations.
            -> what if the fire & human reaches at destinations at the same time..



        // Example Cases: 
            // Example 1:

                    GRID                            Configured                 FIRE                    Human
                [0, 2, 0, 0, 1]                 [0, X, 0, 0, 1]         [16, X, 2,  1, 0]       [0, X, 2,  1, 0]
                [0, 2, 0, 2, 2]                 [0, X, 0, X, X]         [15, X, 3,  X, X]       [1, X, 3,  X, X]
                [0, 2, 0, 0, 0]                 [0, X, 0, 0, 0]         [14, X, 4,  5, 6]       [2, X, 4,  5, 6]
                [0, 0, 2, 2, 0]                 [0, 0, X, X, 0]         [13,12, X,  X, 7]       [3, 0, X,  X, 7]
                [0, 0, 0, 0, 0]                 [0, 0, 0, 0, 0]         [12,11, 10, 9, 8]       [4, 5, 6,  7, 8]

                                                        Human arrival time: 8
                                                        Fire arrival time: 8

                                                        Wait = 0
                                                        Expected = 0

            // Example 2: 

                -> Edge as: for same point we will have to return '0', because subtracting from fireArrival & one step extra will negative our values.

                        GRID                        Configured              Fire                            Human:
                    [0, 0, 0, 0, 0]             [0, 0, 0, 0, 0]         [5,  4,  3,  4,  5]        [0,  4,  3,  4,  5]
                    [0, 2, 0, 2, 0]             [0, X, 0, X, 0]         [6,  X,  2,  X,  6]        [1,  X,  2,  X,  6]
                    [0, 2, 0, 2, 0]             [0, X, 0, X, 0]         [7,  X,  1,  X,  7]        [2,  X,  1,  X,  7]
                    [0, 2, 1, 2, 0]             [0, X, 1, X, 0]         [8,  X,  1,  X,  8]        [3,  X,  1,  X,  8]
                    [0, 2, 2, 2, 0]             [0, X, X, X, 0]         [9,  X,  X,  X,  9]        [4,  X,  X,  X,  9]
                    [0, 0, 0, 0, 0]             [0, 0, 0, 0, 0]         [10, 11, 12, 11, 10]       [5,  6,  7,  8, 10]

                                                        Human Arrival:  9
                                                        Fire Arrival:   10

                                                        Wait: 1
                                                        Expected: 1

            // Example 3: 

                            GRID                                Configured                          Fire                                    Human
                    [0,  2,  0,  0,  0,  0,  0]         [0,  X,  0,  0,  0,  0,  0]         [6,  X,  4,  3,  2,  1,  2]         [0,  X,  4,  3,  2,  1,  2]
                    [0,  0,  0,  2,  2,  1,  0]         [0,  0,  0,  X,  X,  1,  0]         [5,  4,  3,  X,  X,  0,  1]         [1,  4,  3,  X,  X,  0,  1]
                    [0,  2,  0,  0,  1,  2,  0]         [0,  X,  0,  0,  1,  X,  0]         [6,  X,  2,  1,  0,  X,  2]         [2,  X,  2,  1,  0,  X,  2]
                    [0,  0,  2,  2,  2,  0,  2]         [0,  0,  X,  X,  X,  0,  X]         [7,  8,  X,  X,  X, 14,  X]         [3,  8,  X,  X,  X, 10,  X]
                    [0,  0,  0,  0,  0,  0,  0]         [0,  0,  0,  0,  0,  0,  0]         [8,  9, 10, 11, 12, 13, 14]         [4,  5,  6,  7,  8,  9, 10]

                                                        Human Arrival: 10
                                                        Fire Arrival: 14

                                                        wait = 4
                                                        Expected = 3


                -> IT fails here, idk why, logic seems correct, but it fails for this Test case:
                -> Even if we compare the testCase: 1 & 3, human reaching destinations, & with same logic our expected answer are different.

                // Problems: 
                    -> It may be possible that we there may be some multiple path reaching to destinations with same cost & we have some fire, which also computing same from any of the way but with other way it won't reach with that cost.....
                    -> We need to observe more on that cells: 

                                {(n - 1), (m - 1)}  -> last cell
                                {(n - 2), (m - 1)}  -> above
                                {(n - 1), (m - 2)}  -> left
                                
                    -> and build our edge case accordingly....


// Approach 1: Linear Checks from Wait times: -> Accepted:
    -> Instead of human arriving at destinations & comparing the destinations cost with the fireSpread cost
        -> we can change the starting point of human itself from 0 to 1e9 given constrains & try to find the maximum wait point..
            |------|----|-------|-|------|------|---------------|
            0      T    T       T F      F      F               1e9 OR (n * m)

            (n * m) => This could be our last range, because at max we will have this much time we can wait...
        
        -> This way we can find the maximum wait point on 0 to 1e9 scale, & return that..

    // Complexity: 
        -> TC: O((n * m) + ((n * m) * (n * m)))
        -> SC: O(n * m)

// Optimized Approach 1 With BFS: BFS + BS Solution
    -> Instead of checking range linearly, we can wrap it up with binary search...
    -> This will improve the time drastically



    // Complexity: 
        -> TC: O((n * m) + (log(n*m)*(n*m)))
        -> SC: O(n * m)                       



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized Approach 1 With BFS: BFS + BS Solution
class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;   // dimensions
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // all 4 directions.
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    vector<vector<int>> fireFlood(vector<vector<int>>& grid) {

        vector<vector<int>> vis(n, vector<int>(m, 0));          // used to track visited cell
        vector<vector<int>> fireSpread(n, vector<int>(m, 1e9)); // initial value of fire Spread will be 1e9, used to check the valid constrains..
        queue<ppr> q;

        // BFS Mult-Source 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {   // change every obstacle to -1
                    grid[i][j] = -1;
                }
                if(grid[i][j] == 1) {   // for every fire   
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            // Update fireSpreading Cost: 
            fireSpread[row][col] = lvl;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                // valid bound, not yet visted, & valid path.
                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    q.push({lvl + 1, {r, c}});
                    vis[r][c] = 1;
                }
            }

        }

        return fireSpread;
    }
    bool isReachable(int startTime, vector<vector<int>>& grid, vector<vector<int>>& fireSpread) {

        // Initial Checks: 
        if(startTime > fireSpread[0][0]) return false;  // cell value is grater not possible move forward.

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<ppr> q;

        vis[0][0] = 1;
        q.push({startTime,{0, 0}});  // given starting time &  initial coordinates <0, 0>

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            // Destinations Checks: 
            if((row * m + col) == (n * m - 1)) return true;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    // Check the fire cell Cost with human Cell reaching cost:
                    // if fire & human reaching to dst at the same or lesser cost || human cost reaching to dst should always lesser for valid path for human
                    if((((r * m + c) == (n * m - 1)) && (lvl + 1 <= fireSpread[r][c])) || (lvl + 1 < fireSpread[r][c])) {
                        q.push({lvl + 1, {r, c}});
                        vis[r][c] = 1;
                    }
                }
            }
        }

        return false;   // never reaches to destinations.
    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> fireSpread = fireFlood(grid);

        // Binary Search: 
        int maxWaitTime = -1;
        int low = 0, high = n * m;
        while(low <= high) {
            int mid = low + (high - low) / 2;

            if(isReachable(mid, grid, fireSpread)) {
                maxWaitTime = mid;
                low = mid + 1;  // explore on right side for more upper range of wait time..
            } else {
                high = mid - 1;    // close the range, we will have to look on left.
            }
        }

        // Edge case: if Human never reaches to destinations:
        if(maxWaitTime == -1) return -1;    // no reachable to destinations.

        // Edge case: if fire is not reachable to dest, NOTE: this should be checked after the above conditions, because it fails for one testcase...
        if(fireSpread[n-1][m-1] == 1e9) return 1e9;     // human can wait for infinite time..

        // return wait time, as if it's grater than the 1e9, then return the 1e9 as valid constrains range : return answer
        return (maxWaitTime >= 1e9) ? 1e9 : maxWaitTime ; 
    }
};


// Approach 1: Linear Checks from Wait times: -> Accepted:
class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
    int n, m;   // dimensions
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}}; // all 4 directions.
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    vector<vector<int>> fireFlood(vector<vector<int>>& grid) {

        vector<vector<int>> vis(n, vector<int>(m, 0));          // used to track visited cell
        vector<vector<int>> fireSpread(n, vector<int>(m, 1e9)); // initial value of fire Spread will be 1e9, used to check the valid constrains..
        queue<ppr> q;

        // BFS Mult-Source 
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {   // change every obstacle to -1
                    grid[i][j] = -1;
                }
                if(grid[i][j] == 1) {   // for every fire   
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            // Update fireSpreading Cost: 
            fireSpread[row][col] = lvl;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                // valid bound, not yet visted, & valid path.
                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    q.push({lvl + 1, {r, c}});
                    vis[r][c] = 1;
                }
            }

        }

        return fireSpread;
    }
    bool isReachable(int startTime, vector<vector<int>>& grid, vector<vector<int>>& fireSpread) {

        // Initial Checks: 
        if(startTime > fireSpread[0][0]) return false;  // cell value is grater not possible move forward.

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<ppr> q;

        vis[0][0] = 1;
        q.push({startTime,{0, 0}});  // given starting time &  initial coordinates <0, 0>

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            // Destinations Checks: 
            if((row * m + col) == (n * m - 1)) return true;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c) && !vis[r][c] && !grid[r][c]) {
                    // Check the fire cell Cost with human Cell reaching cost:
                    // if fire & human reaching to dst at the same or lesser cost || human cost reaching to dst should always lesser for valid path for human
                    if((((r * m + c) == (n * m - 1)) && (lvl + 1 <= fireSpread[r][c])) || (lvl + 1 < fireSpread[r][c])) {
                        q.push({lvl + 1, {r, c}});
                        vis[r][c] = 1;
                    }
                }
            }
        }

        return false;   // never reaches to destinations.
    }

public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> fireSpread = fireFlood(grid);

        int maxWaitTime = -1;
        for(int i = n*m; i >= 0; i--) { // start with grid constrains maxi
            if(isReachable(i, grid, fireSpread)) {
                maxWaitTime = i;
                break;  // no need to explore backword, this will be our maximum..
            }
        }

        // Edge case: if Human never reaches to destinations:
        if(maxWaitTime == -1) return -1;    // no reachable to destinations.

        // Edge case: if fire is not reachable to dest, NOTE: this should be checked after the above conditions, because it fails for one testcase...
        if(fireSpread[n-1][m-1] == 1e9) return 1e9;     // human can wait for infinite time..

        // return wait time, as if it's grater than the 1e9, then return the 1e9 as valid constrains range : return answer
        return (maxWaitTime >= 1e9) ? 1e9 : maxWaitTime ; 
    }
};



// Logic 1: Fails for few testCases => NOT ACCEPTED => WRONG || MISSING EDGE CASES
class Solution {
private:
    typedef pair<int, pair<int, int>> ppr;
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    vector<vector<int>> fire(vector<vector<int>>& grid) {

        vector<vector<int>> vis(n, vector<int> (m, 0));
        vector<vector<int>> fireSpread(n, vector<int> (m, 1e9));
        queue<ppr> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    q.push({0, {i, j}});
                    vis[i][j] = 1;
                }
                if(grid[i][j] == 2) {
                    grid[i][j] = -1;
                }
            }
        }
        
        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            fireSpread[row][col] = lvl;

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];
                
                if(isValid(r, c) && !vis[r][c] && grid[r][c] == 0) {
                    q.push({lvl + 1, {r, c}});
                    vis[r][c] = 1;
                }
            }
        }

        return fireSpread;
    }
    int humanArrival(vector<vector<int>>& grid, vector<vector<int>>& fireSpread) {

        vector<vector<int>> vis(n, vector<int> (m, 0));
        queue<ppr> q;

        q.push({0, {0, 0}});
        vis[0][0] = 1;

        int time = -1;

        while(!q.empty()) {
            auto [lvl, cor] = q.front();
            q.pop();

            int row = cor.first;
            int col = cor.second;

            if((row * m + col) == (n * m - 1)) {
                time = lvl;
                break;
            }

            // Explore all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c) && !vis[r][c] && grid[r][c] == 0)  {
                    if( (r == n - 1 && c == m - 1) &&  (lvl + 1 <= fireSpread[r][c]) || (lvl + 1 < fireSpread[r][c])) {
                        vis[r][c] = 1;
                        q.push({lvl + 1, {r, c}});
                    }
                }
            }
        }

        return time;
    }
public:
    int maximumMinutes(vector<vector<int>>& grid) {
        n = grid.size(), m = grid[0].size();

        vector<vector<int>> fireSpread = fire(grid);
        int humanArrivalTime = humanArrival(grid, fireSpread);
        int fireSpreadTime = fireSpread[n-1][m-1];

        if(fireSpreadTime == 1e9) return 1e9;   // can wait for infinite time.
        if(humanArrivalTime == -1) return -1;   // not able to reach destinations.

        if(humanArrivalTime > fireSpreadTime) return -1;    // human arrives after fire, eaten
        if(humanArrivalTime == fireSpreadTime) return 0;    // both arrived destinations at the same time.

        return fireSpreadTime - humanArrivalTime - 1;
    }
};