/*

//  Floyd Warshall

//  Problem Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
public:
    void floydWarshall(vector<vector<int>> &dist) {
        int V = dist.size();
        
        // Process Floyd Warshall:
        for(int k = 0; k < V; k++) {
            for(int u = 0; u < V; u++) {
                for(int v = 0; v < V; v++) {
                    if(dist[u][k] != 1e8 && dist[k][v] != 1e8) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }
        
    }
};
