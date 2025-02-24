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

// Observation: 
    -> We are given edges of nodes that denotes undirected edge from node u ---> v with their weights.
    -> We need to find such city that has smallest number of neighbors, that limit in given constrains Threshold Distance.
    -> If we have multiple city with same number of neighbors, then return the higher numbered of city from that list.


// Complexity:
    -> TC: O(n^3), because of Floyd Warshall
    -> SC: O(n^2), as we are minupalting the given input & for building the adj matrix.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int disThr) {
        // Forming Adj Matrix:
        vector<vector<int>> mat(n, vector<int> (n, 1e9));
        for(int i = 0; i < n; i++) mat[i][i] = 0;
        for(auto &it: edges) {  // filling for undirected graph.
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            mat[u][v] = wt;
            mat[v][u] = wt;
        }

        // Using Floyd Warshall:
        for(int k = 0; k < n; k++) {    // via every node
            for(int i = 0; i < n; i++) {    // from u
                for(int j = 0; j < n; j++) {    // to v
                    // Getting the minimum cost to reach the destination u ---> v via 'k'
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        /*
        // Extra-Dubug Logic:
        vector<vector<int>> city(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << mat[i][j] << " ";
                if(i != j && mat[i][j] <= disThr) {
                    city[i].push_back(j);
                }
            }
            cout << endl;
        }
        cout << endl;

        for(int i = 0; i < city.size(); i++) {
            cout << i << ": ";
            for(int j = 0; j < city[i].size(); j++) {
                cout << city[i][j] << " ";
            }
            cout << endl;
        }
        //---------
        */

        // Now Storing the details form the city.
        vector<int> city(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && mat[i][j] <= disThr) {
                    city[i]++;
                }
            }
        }

        // This logic will store the minimum count of city from the largest city available.
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(city[i] < city[ans]) {
                ans = i;
            }
            else if(city[i] == city[ans]) {
                ans = i;
            }
        }

        return ans;
    }
};