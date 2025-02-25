/*

//  1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance


//  Problem Statement: 
    -> There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
    -> Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.
    -> Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.


// Example:

    Example 1:
        Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
        Output: 3
        Explanation: The figure above describes the graph. 
        The neighboring cities at a distanceThreshold = 4 for each city are:
        City 0 -> [City 1, City 2] 
        City 1 -> [City 0, City 2, City 3] 
        City 2 -> [City 0, City 1, City 3] 
        City 3 -> [City 1, City 2] 
        Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

    Example 2:
        Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
        Output: 0
        Explanation: The figure above describes the graph.
        The neighboring cities at a distanceThreshold = 2 for each city are:
        City 0 -> [City 1]
        City 1 -> [City 0, City 4]
        City 2 -> [City 3, City 4]
        City 3 -> [City 2, City 4]
        City 4 -> [City 1, City 2, City 3]
        The city 0 has 1 neighboring city at a distanceThreshold = 2.


// Dijkstra's Approach:
    -> Instead of going into O(n^3) with Floyd Warshall, we can generate shortest path with O(E * log(V)) with dijkstra's for every node.
    -> For all 'n' nodes it takes O(V * (E * log(V))), (V = node n)
    -> First Build adj-list for dijkstra's & generate our answer distance & store it into 2D-matrix.
    -> Rest logic is same...



// Complexity:
    -> TC: O(V * (E * log(V)))
    -> SC: O(n^2), for building adj-list & adj-matrix


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Approach: Dijkstra's Algorithm -> TC: O(V * (E * log(V)))
class Solution {
private:
    typedef pair<int, int> pr;
    vector<int> dijkstra(int src, int n, vector<vector<pr>> adj) {  // Dijkstra's For finding distance for ever node.
        vector<int> dist(n, 1e9);
        priority_queue<pr, vector<pr>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            for(auto &it: adj[node]) {
                if(it.second + cost < dist[it.first]) {
                    dist[it.first] = cost + it.second;
                    pq.push({cost + it.second, it.first});
                }
            }
        }

        return dist;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int disThr) {

        // Building Graph:
        vector<vector<pr>> adj(n);
        for(auto &it: edges) {  // for undirected-Graph
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        // Dijkstra's Call for every node:
        vector<vector<int>> mat;
        for(int i = 0; i < n; i++) {
            mat.push_back({dijkstra(i, n, adj)});
        }

        // Generating Answer from given constrains:
        vector<int> city(n);
        for(int i = 0; i < n; i++) {    // getting the city & their neighbour that falls into given constrains.
            for(int j = 0; j < n; j++) {
                if(i != j && mat[i][j] <= disThr) {
                    city[i]++;
                }
            }
        }

        int ans = 0;
        for(int i = 1; i < n; i++) {    // getting the smallest neighbour city:
            if(city[i] <= city[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};