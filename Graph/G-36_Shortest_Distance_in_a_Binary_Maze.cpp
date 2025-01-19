/*

//  G-36. Shortest Distance in a Binary Maze


//  Problem Statement: 
    -> Given a n * m matrix grid where each element can either be 0 or 1. You need to find the shortest distance between a given source cell to a destination cell. The path can only be created out of a cell if its value is 1. 
    -> If the path is not possible between source cell and destination cell, then return -1.
    -> Note : You can move into an adjacent cell if that adjacent cell is filled with element 1. Two cells are adjacent if they share a side. In other words, you can move in one of the four directions, Up, Down, Left and Right. The source and destination cell are based on the zero based indexing. The destination cell should be 1.


// Example:

    Input:
    grid[][] = {{1, 1, 1, 1},
                {1, 1, 0, 1},
                {1, 1, 1, 1},
                {1, 1, 0, 0},
                {1, 0, 0, 1}}
    source = {0, 1} destination = {2, 2}
    Output: 3
    Explanation:
        1 1 1 1
        1 1 0 1
        1 1 1 1
        1 1 0 0
        1 0 0 1
        The highlighted part in the matrix denotes the 
        shortest path from source to destination cell.

    Example 2:

    Input:
    grid[][] = {{1, 1, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 1, 1, 1, 0},
                {1, 0, 1, 0, 1}}
    source = {0, 0} destination = {3, 4}
    Output: -1
    Explanation:
        The path is not possible between source and 
        destination, hence return -1.


// Approach:
    -> We are given source node & destinations node, & we need to find the shortest distance, but the case we can only visit the cell which has '1'.
    -> We can use dijkstra algorithm, but since the distance of every direction of adjacent node is 1, it won't affect much.
    -> If we take priority queue during the dijkstra algorithm implementation, it works like simple queue.
    -> Instead we can take queue & process the algorithm..
    -> We can implement simple Dijkstra BFS with queue, having some modifications...


// Complexity: 
    -> TC: O(n * m)
    -> SC: O(n * m)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    // Directions for moving in the grid: right, left, down, and up
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src, pair<int, int> dst) {
        int n = grid.size();
        int m = grid[0].size();
        
        // when source & destination is same:
        if(src.first == dst.first && src.second == dst.second){
            return 0;
        }
        
        queue<pair<int, pair<int, int>>> q; 
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        
        q.push({0, {src.first, src.second}});   // pushing the source node into queue:
        dist[src.first][src.second] = 0; // marking source distance as '0' in distance array.
        

        int ans = 0;
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int steps = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            
            // Check adjacent nodes in all possible 4 directions: 
            for(int i=0;i<4;i++){
                int nRow = row + dir[i][0];
                int nCol = col + dir[i][1];
                
                // checking bound, & have valid grid value && lower distance:
                if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 1 && steps + 1 < dist[nRow][nCol] ){   // if new distance is less than this current grid distance, then update:
                    
                    dist[nRow][nCol] = steps + 1;   // update new distance
                    
                    if(nRow == dst.first && nCol == dst.second) return steps + 1; // At any movement we are at destination: return the steps:
                    
                    q.push({steps+1, {nRow, nCol}});    // push that cell into queue
                }    
            }
        }
        
        return -1;  // when we are not able to find the destination.
    }
};




int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
        cout << "~" << "\n";
    }
}