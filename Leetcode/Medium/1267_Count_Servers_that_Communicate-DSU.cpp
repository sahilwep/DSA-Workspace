/*

//  1267. Count Servers that Communicate


//  Problem Statement: 
    -> You are given a map of a server center, represented as a m * n integer matrix grid, where 1 means that on that cell there is a server and 0 means that it is no server. 
    -> Two servers are said to communicate if they are on the same row or on the same column.
    -> Return the number of servers that communicate with any other server.


// Example:

    Example 1:

        Input: grid = [[1,0],[0,1]]
        Output: 0
        Explanation: No servers can communicate with others.

    Example 2:

        Input: grid = [[1,0],[1,1]]
        Output: 3
        Explanation: All three servers can communicate with at least one other server.

    Example 3:

        Input: grid = [[1,1,0,0],[0,0,1,0],[0,0,1,0],[0,0,0,1]]
        Output: 4
        Explanation: The two servers in the first row can communicate with each other. The two servers in the third column can communicate with each other. The server at right bottom corner can't communicate with any other server.

// Observations: 
    -> We are given a grid, where we have servers in some given coordinates..
    -> We need to find how many servers are connecting with other servers.

    // Key Observations: 
        -> If more than 1 server shares same row/col -> Considered as group of servers..

    // DSU Approach: 
        -> As we have to connect the server which were in same row/col, we can use DSU.
        -> DSU will create Components from the given inputs.
        -> Then we can check the groups & find how many total servers in that groups, & somehow keep track of that groups.
        -> At last we will check which groups has more than 1 servers & we will sums up our answer with that..

        // Implementations: 
            -> As we are given 2D grid, we can create a offSet value which will acts as buffer point for col
            -> Then we can create DSU of that size.
            -> Step 1: First we will connect the components.
            -> Step 2: Second we will fetch the ultimate parent of every components & increase the count of server if we encounter during the traversal in grid.
                -> to keep track of the server groups, we can use map.
            -> Step 3: Last we will check which groups has more than 1 server, and we will sums up the Server Count.
    
// Complexity:
    -> TC: O(n * m)
    -> SC: O(n * m + offSet) => O(n * m)
    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// DSU:
class DSU {
public: 
    vector<int> size, parent;
    DSU(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 0; i < n + 1; i++) parent[i] = i;
    }
    int ultPar(int node) {
        if(parent[node] == node) return node;
        return parent[node] = ultPar(parent[node]);
    }
    void Union(int u_, int v_) {
        int u = ultPar(u_);
        int v = ultPar(v_);

        if(u == v) return;

        if(size[u] < size[v]) {
            parent[u] = v;
            size[v] += size[u];
        } else {
            parent[v] = u;
            size[u] += size[v];
        }
    }
};


// DSU Approcah:
class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        const int OFFSET = 251; // shift column indices to avoid collision
        int rows = grid.size(), cols = grid[0].size();

        DSU ds(rows + cols + OFFSET); // Total nodes = rows + columns (safely shifted)

        // Step 1: Union rows and columns for each server
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    int rowNode = i;
                    int colNode = j + OFFSET;
                    ds.Union(rowNode, colNode);
                }
            }
        }

        // Step 2: Count servers in each connected component
        unordered_map<int, int> componentSize;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j]) {
                    int root = ds.ultPar(i); // Could also use ultPar(j + OFFSET)
                    componentSize[root]++;
                }
            }
        }

        // Step 3: Count only servers in groups of size > 1
        int totalServers = 0;
        for (const auto& [root, size] : componentSize) {
            if (size > 1)
                totalServers += size;
        }

        return totalServers;
    }
};