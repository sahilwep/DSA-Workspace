/*

//   G-40. Number of Ways to Arrive at Destination 

//  Problem Statement: 
    -> You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
    -> You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, time[i]] means that there is a road between intersections ui and vi that takes time[i] minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
    -> Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.


// Example:

    Example 1:
        Input: n=7, m=10
        edges= [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
        Output: 4
        Explanation:
            The four ways to get there in 7 minutes are:
            - 0  6
            - 0  4  6
            - 0  1  2  5  6
            - 0  1  3  5  6

    

    Example 2:
        Input: n=6, m=8
        edges= [[0,5,8],[0,2,2],[0,1,1],[1,3,3],[1,2,3],[2,5,6],[3,4,2],[4,5,2]]
        Output: 3
        Explanation:
            The three ways to get there in 8 minutes are:
            - 0  5
            - 0  2  5
            - 0  1  3  4  5


// Observations: 
    -> We are given source node as '0' & dest node as 'n-1', we need to find the number of ways to reach destination with shortest distance possible.
    -> First we will find the shortest path by using dijkstra's algorithm, & parallel, we will find the ways to reach with same node with shortest distance possible.


// Complexity:
    -> TC: O(E * log(V))
    -> SC: O(V)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


#define mod 1000000007
class Solution {
private:
    typedef long long ll;
    typedef pair<ll, int> lpr;
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int src = 0;
        int dest = n-1;
        
        // Convert roads to Un-directed adj graph list with edge weight.
        vector<vector<pair<int, int>>> adj(n);
        for(auto &it: roads){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Dijkstra's Algorithm:
        // Now find the shortest distance of every nodes & parallel find the ways to arrive that distance
        priority_queue<lpr, vector<lpr>, greater<>> pq; // structure: <distance, node>
        vector<ll> dist(n, LLONG_MAX);    // define distance with infinite value
        vector<ll> ways(n, 0);  // define ways to reach every n roads with '0' initially.
        
        pq.push({0, src});   // insert source node with distance as '0'
        dist[src] = 0;  // source distance = 0, initially
        ways[src] = 1;  // ways to reach source node is exactly 1
        
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            ll steps = it.first;
            int node = it.second;
            
            if (steps > dist[node]) continue;// If we already have a better distance, skip processing
            
            // Explore adjacent nodes:
            for(auto &i: adj[node]){
                
                int v = i.first;
                int wt = i.second;
                
                ll newDist = (steps + wt);
                
                if(newDist < dist[v]){  // if new distance is less than the previous distance of adjacent node
                    dist[v] = newDist;  // update new distance
                    
                    ways[v] = ways[node];   // update the destination reaching ways same as parent node ways, because this is for shortest distance we are updating.
                    
                    pq.push({newDist, v});   // push that node with new distance
                }
                
                else if(newDist == dist[v]){    // we get same distance as previous finding.
                    ways[v] = (ways[node] + ways[v]) % mod;    // update total no ways to reach that node with same shortest distance.
                }
            }
        }
        
        
        return ways[dest] % mod;
    }
};



int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
        cout << "~" << "\n";
    }

    return 0;
}