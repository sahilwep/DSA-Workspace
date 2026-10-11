/*

//  815. Bus Routes


//  Problem Statement: 
    - You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.
        - For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.
    - You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.
    - Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 
// Example:
    Example 1:
        Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
        Output: 2
        Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

    Example 2:
        Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
        Output: -1



// Observations:
    - Given routes:
        - routes[i] is the bus routes that the ith bus reapers forevers.

    - Eg:
        routes[0] = {1, 5, 7}
            this means that the 0th bus travels in the sequence:
                1->5->7->1->5->7->1.... forever.
        
        - You will start at the bus stops source.
        - you are initially on any bus initially and you want to go to the bus stop target.
        - you can travel between bus stops by buses only.
        - return the least number of buses you must take to travel from source to target.
        - Return -1, if it is not possible.

    // Approach:
        routes: {{1, 2, 7}, {3, 6, 7}}, src = 1, dst = 6
        o/p: 2

             src
                [1]---------[2]
                 \          /
                  \        /
                   \      /
                    \    /
                      [7]--------[6] dst
                        \        /
                         \      /
                          \    /
                            [3]


            - we will start from src '1' -> '7' -> '6' 
            - '6' found at level 2
        - This gives hint of using BFS
        - we will use BFS to find the 'target'.
    - First we will have to build the route:
        - means the graph adj list:
        - as given: routes[i] = {a, b, c}
                a -> b -> c -> a
        
    
    s = 4, d = 21

    - I mistaken for that given routes has relationship of directed graph, but it's complete graph, where every node connected with everytoher nodes.
    
        // Approach: BFS + All Possible pair generation:
            - first build graph adj list:
                - for every routes[i]
                    - O(n^2) generate all possible pair..

            - Process BFS:
                - find the min_dist..
                - This is plain and simple..


            - fails for TLE & MLE..
                - constrains: 
                    (1 <= routes[i] <= 1e5)


        // Optimization:
            - one thing we can observe that every route[i] has consider into same group..
            - and when we move one group to another then only our level increases..
            - Instead of making every pair, can say:
                - let's treat every routes[i] has bus[i], single bus with all the values have same reachable distance..
                - Now we have total n bus:
                    n = routes.size()
                
                - Now Simply Build a list, that can query every node/stop inside that bus?
                - we will have to query this in O(1), and should not contains duplicate.
                    - unordered_set<int> handel this.
                - so, bus will be:

                        vector<unordered_set<int>> bus(n)

                - NOW, as we storing the informations into bus:
                    - we will have to make sure that we will push starting bus into queue, by comparing from src:
                        - if any stop/node is equal to src => consider that all the starting, and push all into queue.
                        - make sure to visit that bus[i], because we already processed every bus stop/node..

            - Now simply process BFS:
                - for every "node":
                    - we will have to check which next bus which is not yet visited has this node/stop:
                        - for the any bus found, just store all the informations into queue:
                            - and make sure to mark that bus as processed...

            - This is how we can simply optimize our current bruteforce...

            // complexity:
                - TC: O(n * k)
                    - n = routes.size();
                    - k = max(routes[i].size());

                - SC: O(n * k) 




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Efficient Solution:
class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int dst) {
        int n = routes.size();

        if(src == dst) return 0;

        // Build graph adj list & insert starring point:
        vector<unordered_set<int>> bus(n);
        queue<int> q;
        vector<int> vis(n, 0);
        for(int i = 0; i < n; i++) {
            vector<int> r = routes[i];
            bool srcFound = false;
            for(auto &node: r) {
                bus[i].insert(node);

                if(node == src) srcFound = true;
            }

            // If current route is has "src":
            if(srcFound) {
                for(auto &node: r) {    // push all nodes into queue.
                    q.push(node);
                }

                vis[i] = 1; // mark that bus as processed..
            }
        }

        // Now process BFS:
        int lvl = 1;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int node = q.front();
                q.pop();

                // Reach to destinations?
                if(node == dst) return lvl;

                // Explore all Bus:
                for(int i = 0; i < n; i++) {
                    // If current bus is not yet explored:
                    if(!vis[i]) {   
                        // if current node found in this current bus:
                        if(bus[i].count(node)) {
                            // insert all the node as possible path:
                            for(auto &v: bus[i]) {
                                q.push(v);
                            }

                            vis[i] = 1; // mark that current bus as visited.
                        }
                    }
                }
            }

            lvl++;
        }

        return -1;  // not reached to destinations..
    }
};


// BruteForce:
class Solution_ {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int src, int dst) {

        if(src == dst) return 0;

        // Build graph adj list:
        unordered_map<int, unordered_set<int>> adj;
        for(auto &r: routes) {
            // Generate every possible pair:
            for(int i = 0; i < r.size(); i++) {
                for(int j = i + 1; j < r.size(); j++) {
                    int u = r[i];
                    int v = r[j];

                    adj[u].insert(v);
                    adj[v].insert(u);
                }
            }
        }

        // Now process BFS:
        queue<int> q;
        unordered_set<int> vis;

        q.push(src);
        vis.insert(src);
        
        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int node = q.front();
                q.pop();

                // Reach to destinations?
                if(node == dst) return lvl;

                // Explore adj neighbors:
                for(auto &ngbr: adj[node]) {
                    if(!vis.count(ngbr)) {
                        q.push(ngbr);
                        vis.insert(ngbr);    
                    }
                }
            }

            lvl++;
        }

        return -1;  // not reached to destinations..
    }
};