/*

// CSES: Cycle Finding


//  Problem Statement: 
    -> You are given a directed graph, and your task is to find out if it contains a negative cycle, and also give an example of such a cycle.
    // Input
        -> The first input line has two integers n and m: the number of nodes and edges. The nodes are numbered 1,2,...,n.
        -> After this, the input has m lines describing the edges. Each line has three integers a, b, and c: there is an edge from node a to node b whose length is c.
    // Output
        -> If the graph contains a negative cycle, print first "YES", and then the nodes in the cycle in their correct order. 
        -> If there are several negative cycles, you can print any of them. If there are no negative cycles, print "NO".

// Constraints

    1 <= n <= 2500
    1 <= m <= 5000
    1 <= a,b <= n
    -10^9 <= c <= 10^9


// Example
    Input:
        4 5
        1 2 1
        2 4 1
        3 1 1
        4 1 -3
        4 3 -2

    Output:
        YES
        1 2 4 1


// Observations:
    -> We are given a directed weighted graph, where we have to find wether the graph contains negative cycle or not?
    -> We don't need to return the cost of reaching destinations or something, it's just we need to print negative cycle is there or not, & if it's there then print the path.

    // Bellman-Ford Approach: 
        -> When negative cycle comes, bellman is our optimal options.
        -> Also we have to print the path of negative cycle, means we will maintain one extra parent vector, which will let us know where we are coming from.
        -> First we will find the negative cycle is there or not, & then by the decision we can print the path.

    // Visualization: 
        Input:
            4 5
            1 2 1
            2 4 1
            3 1 1
            4 1 -3
            4 3 -2
        Output:
            YES
            1 2 4 1
                            1
                    [1]----------->[2]
                     ↑↖             |
                     |  \           |
                     |    \         |
                    1|      \-3     | 1
                     |        \     |
                     |          \   |
                     |            \ ↓
                    [3]<-----------[4]
                            -2

            -> Initialize distance as '0', because we don't want to get the cost, we only want to know about cycle & path.
            -> initialize one more vector as parent with default value = -1
            -> After processing Bellman n times we find cycle:

                    dist[] = {-6, -4, -5, -3}
                               1   2   3   4
                
                    parent[] = {4, 1, 4, 2} 
                                1  2  3  4

                -> we will have our x at 3, denoting cycle.
                -> We will have to go back n times backword x at 4
                    simply loop from (1 to n): 
                                    x = parent[x];

                    X = 4

                -> Now we are at correct cycle locations, from we can backtrack & get the path of cycle

                    parent[] = {4, 1, 4, 2} 
                                1  2  3  4

                    Now create temp variable curr = x
                    until (curr != x) iterate backword & store the path.
                    last reverse & print..

    // Complexity: 
        -> TC: O(V * E)
        -> SC: O(V)

*/


#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

class Solution {
public:
    void solve(vector<vector<ll>>& edges, int n, int e) {
        vector<ll> dist(n, 0);      // Initialize with 0 for all (safe for cycle detection), we don't want the cost, we only wanted to print any cycle path if there is a cycle.
        vector<ll> parent(n, -1);   // used to store the parent of every node, where it's coming from
        int x = -1;                 // this will used to detect cycle

        // Bellman-Ford algorithm
        for(int i = 0; i < n; i++) {   // runs for exactly n times
            x = -1; // everytime we will initialize it with '-1', this will detect the cycle
            for(auto &it : edges) {
                int u = it[0], v = it[1], wt = it[2];
                if (dist[u] + wt < dist[v]) {   // at exactly "n-1" iteration if this block executed
                    dist[v] = dist[u] + wt;
                    parent[v] = u;
                    x = v;  // cycle detected at "n-1" & node store here in "x"
                }
            }
        }

        if(x == -1) {  // if there's no cycle
            cout << "NO\n";
            return;
        }

        // Found a negative cycle, reconstruct it:
        cout << "YES\n";
        // Go n steps back to guarantee getting into the cycle
        for(int i = 0; i < n; i++) {
            x = parent[x];
        }

        vector<int> cycle; // this will contains the cycle path.
        int cur = x;       // initialize curr = x for breaking point, means when it's get back to original node.
        // Using do-while, because it may be possible self pointing node is there & -ve contains cycle
        do {
            cycle.push_back(cur);
            cur = parent[cur];
        } while(cur != x);

        cycle.push_back(x); // last push the final node
        reverse(cycle.begin(), cycle.end());    // reverse it to get in currect directed path order


        for (auto &it : cycle) cout << it+1 << " ";  // Convert back to 1-based index
        cout << "\n";
    }
};

int main() {
    int n, e;
    cin >> n >> e;
    vector<vector<ll>> edges;
    for (int i = 0; i < e; i++) {
        ll u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back({u - 1, v - 1, wt}); // Make 0-based
    }

    Solution obj;
    obj.solve(edges, n, e);

    return 0;
}
