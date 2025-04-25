/*

//  2662. Minimum Cost of a Path With Special Roads

//  Problem Statement: 
    -> You are given an array start where start = [startX, startY] represents your initial position (startX, startY) in a 2D space. 
    -> You are also given the array target where target = [targetX, targetY] represents your target position (targetX, targetY).
    -> The cost of going from a position (x1, y1) to any other position in the space (x2, y2) is |x2 - x1| + |y2 - y1|.
    -> There are also some special roads. You are given a 2D array specialRoads where specialRoads[i] = [x1i, y1i, x2i, y2i, cost[i] indicates that the ith special road goes in one direction from (x1i, y1i) to (x2i, y2i) with a cost equal to cost[i]. 
    -> You can use each special road any number of times.
    -> Return the minimum cost required to go from (startX, startY) to (targetX, targetY).

 
// Example: 
    Example 1:
        Input: start = [1,1], target = [4,5], specialRoads = [[1,2,3,3,2],[3,4,4,5,1]]
        Output: 5
        Explanation:
                (1,1) to (1,2) with a cost of |1 - 1| + |2 - 1| = 1.
                (1,2) to (3,3). Use specialRoads[0] with the cost 2.
                (3,3) to (3,4) with a cost of |3 - 3| + |4 - 3| = 1.
                (3,4) to (4,5). Use specialRoads[1] with the cost 1.
            So the total cost is 1 + 2 + 1 + 1 = 5.

    Example 2:
        Input: start = [3,2], target = [5,7], specialRoads = [[5,7,3,2,1],[3,2,3,4,4],[3,3,5,5,5],[3,4,5,6,6]]
        Output: 7
        Explanation:
            It is optimal not to use any special edges and go directly from the starting to the ending position with a cost |5 - 3| + |7 - 2| = 7.
            Note that the specialRoads[0] is directed from (5,7) to (3,2).

    Example 3:
        Input: start = [1,1], target = [10,4], specialRoads = [[4,2,1,1,3],[1,2,7,4,4],[10,3,6,1,2],[6,1,1,2,3]]
        Output: 8
        Explanation:
            (1,1) to (1,2) with a cost of |1 - 1| + |2 - 1| = 1.
            (1,2) to (7,4). Use specialRoads[1] with the cost 4.
            (7,4) to (10,4) with a cost of |10 - 7| + |4 - 4| = 3.



// BruteForce Solution: MLE
    -> First build the matrix.
    -> Store the given special road somewhere so that we can access them in less time.
    -> now compute the time with dijkstra's algorithm, & compute the shortest distance.
    -> Solution gives MLE due to it's constrains 1e5*1e5 => somewhat 40gb of allocations
    -> TC: O((n * m) * log(n * m))


// Efficient Approach: 
    -> Replace matrix with map.
    -> Store distance in map.
    -> use dijkstra's to compute shortest path.


    // Complexity: 
        -> TC: (n * log(n))
        -> SC: (n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution: 
class Solution {
private: 
    typedef pair<int, pair<int, int>> ppr;
public:
    int minimumCost(vector<int>& src, vector<int>& dst, vector<vector<int>>& specialRoads) {
        
        // If start & end is same: 
        if(src[0] == dst[0] && src[1] == dst[1]) return 0;   // min cost = 0, needed

        // use map to store the minimum distance for every coordinate from source:
        map<pair<int, int>, int> mp;    // Structure: {{X-coordinates, Y-Coordinate}:  minCost}

        mp[{src[0], src[1]}] = 0;   // starting coordinates
        mp[{dst[0], dst[1]}] = INT_MAX; // initially un-reachable.

        // Dijkstra's Solution:
        priority_queue<ppr, vector<ppr>, greater<>> pq;
        pq.push({0, {src[0], src[1]}});

        while(!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int row = cor.first, col = cor.second;

            // check Destinations: 
            if(row == dst[0] && col == dst[1]) return cost;


            // Check directly reachable to destinations every time & update minimum as possible
            if(mp[{dst[0], dst[1]}] > cost + abs(row - dst[0]) + abs(col - dst[1]))  {
                // Total Cost = current cost + |X1 - x2| + |Y2 - y1|
                mp[{dst[0], dst[1]}] = cost + abs(row - dst[0]) + abs(col - dst[1]);
                pq.push({mp[{dst[0], dst[1]}], {dst[0], dst[1]}});
            }

            // Via special road:
            for(auto &it: specialRoads) {
                int Sr = it[0], Sc = it[1], Dr = it[2], Dc = it[3], cost_ = it[4];
                int newCost = cost + abs(row - Sr) + abs(col - Sc) + cost_;
                // if destinations cost is not there or destinations cost is grater than the newCost in map:
                if(mp.find({Dr, Dc}) == mp.end() || mp[{Dr, Dc}] > newCost) {
                    mp[{Dr, Dc}] = newCost;
                    pq.push({newCost, {Dr, Dc}});
                }
            }
        }

        return abs(src[0] - dst[0]) + abs(src[1] - dst[1]);     // in worse case we will choose manhattan distance from src to dst as minimum.
    }
};


// BruteForce SolutioN: 
class Solution {
private: 
    int n, m;
    int dir[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    bool isValid(int r, int c) {return (r >= 0 && r < n && c >= 0 && c < m);}
    typedef pair<int, pair<int, int>> ppr;
public:
    int minimumCost(vector<int>& start, vector<int>& target, vector<vector<int>>& specialRoads) {
        
        map<pair<int, int>, vector<vector<int>>> mp;
        for(auto &it: specialRoads) {
            mp[{it[0], it[1]}].push_back({it[2], it[3], it[4]});    // send multiple values, if we have multiple direct route from any cell:

            // get the maximum range to build matrix
            n = max(it[0], it[2]);  // max among row
            m = max(it[1], it[3]);  // max among col
        }

        // Build matrix: 
        // Get the maximum range:
        n = max(start[0], target[0]) + 5;   // make final maximum range + 5 as buffer point.
        m = max(start[1], target[1]) + 5;   // make final maximum range + 5 as buffer point.

        // Dijkstra's Solution:
        vector<vector<int>> dist(n + 1, vector<int> (m + 1, INT_MAX));   // initialize it with infinity.
        priority_queue<ppr, vector<ppr>, greater<>> pq;

        dist[start[0]][start[1]] = 0;
        pq.push({0, {start[0], start[1]}});


        while(!pq.empty()) {
            auto [cost, cor] = pq.top();
            pq.pop();

            int row = cor.first;
            int col = cor.second;

            // Check destinations: 
            if(row == target[0] && col == target[1]) return cost;   // return cost

            // skip expensive calls: 
            if(dist[row][col] < cost) continue;

            // Check special road: 
            if(mp.count({row, col})) {    // special cost found: 
                vector<vector<int>> spRoad = mp[{row, col}];
                // Iterate in all the multiple special path: 
                for(auto &it: spRoad) {
                    int r_ = it[0], c_ = it[1], cost_ = it[2];
                    if(isValid(r_, c_)) {
                        // Check cost:
                        if(cost + cost_ < dist[r_][c_]) {
                            dist[r_][c_] = cost + cost_;    // update cost
                            pq.push({cost + cost_, {r_, c_}});  // send the destinations of special road in pq
                        }
                    }
                }
            }

            // Explore in all 4 directions: 
            for(int i = 0; i < 4; i++) {
                int r = row + dir[i][0];
                int c = col + dir[i][1];

                if(isValid(r, c)) {
                    // Now Compute the cost:
                    int adjMovingCost = abs(r - row) + abs(c - col);    // cost to move any adjacent cell
                    if(cost + adjMovingCost < dist[r][c]) {
                        dist[r][c] = cost + adjMovingCost;
                        pq.push({cost + adjMovingCost, {r, c}});
                    }
                }
            }
        }

        return dist[target[0]][target[1]];
    }
};