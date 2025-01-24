/*

//  1976. Number of Ways to Arrive at Destination



//  Problem Statement: 
    -> You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. 
    -> The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
    -> You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, time[i]] means that there is a road between intersections ui and vi that takes time[i] minutes to travel. 
    -> You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
    -> Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.



//  Example:

    Example 1:
        Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
        Output: 4
        Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
        The four ways to get there in 7 minutes are:
        - 0 ➝ 6
        - 0 ➝ 4 ➝ 6
        - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
        - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6

    Example 2:
        Input: n = 2, roads = [[1,0,10]]
        Output: 1
        Explanation: There is only one way to go from intersection 0 to intersection 1, and it takes 10 minutes.




// Observations: 
    -> We are given source node & dest node.
    -> find the number of ways to reach destination with shortest distance.
    -> There can be multiple path that reaches destination with shorted distance.
    -> We need to find all of them, & return their count.
    -> We will use dijkstra's algorithm.
        -> Graph path is undirected.
        -> We will use priority queue with structure, queue<midDist,< node, cnt>>
        -> we will maintain distance array which will help us to find the shortest path.
        -> we will maintain an array that will also maintain the number of ways to reach particular nodes.
        -> Once all the possible paths has traversed, then only we will return the count.

        // Key Observations: 
            -> if there is a node say x, that has number of ways = 5 & there is another node say 'y'
            -> Shortest path to reach 'y' goes via 'x', then for 'y' number of ways = 5.
            -> Because shortest path goes via 'x' & for 'y' we have same number of ways as 'x' has, quite logical...
            -> This is because all paths from 'x' to 'y' are included in the shortest path.


            -> In simple: 
                -> When we found shortest distance from previous once, we will update ways[currNode] as ways[prevNode]
                -> If we found the same distance again:
                    -> we will update: ways = ways[PrevNode] + ways[CurrNode];
                    -> ways[PrevNode] -> The the previous found ways.
                    -> Ways[currNode] -> extra path we found to reach currNode..




// Complexity: 
    -> TC: O(E * log(V))
    -> SC: O(E + V)


*/

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long


class Solution {
private:
    typedef pair<ll, int> pr;
public:
    int countPaths(int n, vector<vector<int>>& roads) { 
        int src = 0;    // source node
        int des = n-1;  // destinations node

        // Convert roads into graph adjacency list:
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0;i<roads.size();i++){ 
            int u = roads[i][0];
            int v = roads[i][1];
            int wt = roads[i][2];

            // now Push that node & weight for undirected graph:
            adj[u].push_back({v, wt}); 
            adj[v].push_back({u, wt});
        }

        // Dijkstra's algo:
        priority_queue<pr, vector<pr>, greater<>> pq; // min heap to process all the path with shortest distance.
        vector<ll> dist(n, 1e18);  // use to maintain the shortest path, & initialize with 1e18 or LLONG_MAX (in programming 1e18 is used to represent infinity, which will prevent us from edge case if we take LLONG_MAX).
        vector<ll> ways(n, 0); // number of ways to reach the desired destinations..

        pq.push({0, src}); // push source with distance '0', & source node
        dist[src] = 0;  // mark source node with '0' distance 
        ways[src] = 1;  // there is only 1 way to reach source.


        while(!pq.empty()){
            auto [steps, node] = pq.top();
            pq.pop();

            for(auto [v, wt]: adj[node]){    // explore adjacent nodes.

                // Get the new distance:
                long long newDist = steps + wt;

                // If new distance is lesser than the current distance:
                if(newDist < dist[v]){
                    dist[v] = newDist;  // update it.
                    ways[v] = ways[node] % mod; // update ways, as previous nodes ways, because that much ways we can reach dest, through shortest path.
                    pq.push({newDist, v});  // push into queue {new-distance & destination node} into priority queue.
                }
                // else if new-distance is equal to the current shortest distance.
                else if(newDist == dist[v]){
                    ways[v] = (ways[node] + ways[v]) % mod;    // update previous node ways + current node found ways.
                }
            }
        }

        // Debug:
        // for(auto i: dist) cout << i << " ";  // use to print distance of every nodes.
        // cout << endl;

        // for(auto i: ways) cout << i << " ";  // use to print ways of every nodes.
        // cout << endl;

        return ways[des] % mod; // last return the number of ways to reach destinations.
    }
};