/*

//  CSES: Round Trip

//  Problem Statement:
    -> Byteland has n cities and m roads between them. Your task is to design a round trip that begins in a city, goes through two or more other cities, 
    -> and finally returns to the starting city. Every intermediate city on the route has to be distinct.

// Input:
    -> The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,....,n.
    -> Then, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
    -> Every road is between two different cities, and there is at most one road between any two cities.

// Output
    -> First print an integer k: the number of cities on the route. Then print k cities in the order they will be visited. You can print any valid solution.
    -> If there are no solutions, print "IMPOSSIBLE".

// Constraints
    1 <= n <= 10^5
    1 <= m <= 2 * 10^5
    1 <= a,b <= n

// Example
    Input:
        5 6
        1 3
        1 2
        5 3
        1 5
        2 4
        4 5

    Output:
        4
        3 5 1 3

    Input:
        5 4
        1 3
        1 2
        5 3
        2 4

    Output:
        IMPOSSIBLE


// Observations:
    -> We are given an undirected graph with `n` nodes and `m` edges.
    -> Our goal is to detect a cycle in the graph and, if found, print the cycle path.
    
// Cycle Detection in an Undirected Graph:
    -> For each visited adjacent node:
        -> If the adjacent node is not the parent of the current node, then a cycle is detected.

// Approach:
    -> A simple DFS approach to detect a cycle in the graph.
    -> While backtracking, store the path.
    -> If a cycle is detected, store the nodes forming the cycle before returning.
    -> If no cycle is found from a given starting point, check for other unvisited nodes.
    -> A visited array ensures each node is processed only once.
    -> Direct DFS may lead to TLE, so we optimize it by:
        -> Detecting the cycle and finding the cycle node first.
        -> Once a cycle node is found, tracing back to form the cycle path.


// Complexity:
    -> TC: O(V + 2E)
    -> SC: O(V + 2E)

*/


#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Optimized DFS: TC: O(V + 2E)
class Solution {
private:
    int size;
    int cycleNode = -1;
    bool isCycle(int node, int parent, vector<vector<int> > &adj, vector<int> &vis) {   // first find the cycle node:
        vis[node] = 1;
        
        for(auto &it: adj[node]) {
            if(!vis[it]) {
                if(isCycle(it, node, adj, vis)) {
                    return true;
                }
            }
            else if(it != parent) {
                cycleNode = it;
                return true;
            }
        }
        
        return false;
    }
    bool printPath(int node, int parent, int dest, vector<vector<int> > &adj, vector<int> &vis, vector<int> &path) {    // then find the cycle path
        vis[node] = 1;
        
        // explore adjacent nodes:
        for(auto &ngbr: adj[node]) {
            if(!vis[ngbr]) {
                if(printPath(ngbr, node, dest, adj, vis, path) == true) {
                    path.push_back(ngbr);
                    return true;
                }
            }
            // if neighbour node is already visited before and
            // neighbour node is not the parent, means we occur a cycle.
            // also we need to make sure we won't revisit the path from where we are coming to reach destination.
            else if(ngbr != parent && ngbr == dest) {
                path.push_back(ngbr);
                return true;
            }
        }
        
        return false;   // no cycle, means not possible..
    }
public:
    void solve(vector<vector<int> > &adj) {
        size = adj.size();

        vector<int> vis(size, 0);

        for(int i = 1; i < size; i++) {
            if(!vis[i]) {
                if(isCycle(i, -1, adj, vis)) {
                    // We have found the cycle:
                    // Now we need to print the path only.
                    vector<int> path;
                    vector<int> tmpVis(size, 0);

                    printPath(cycleNode, -1, cycleNode, adj, tmpVis, path);

                    path.push_back(cycleNode);
                    cout << path.size() << endl;
                    for(auto &it: path) cout << it << " ";
                    return;
                }
            }
        }

        cout << "IMPOSSIBLE" << endl;
    }
};



// DFS Solution is correct, but it leads to TLE: TC: O(V * (V + 2E))
class Solution_Brute {
private:
    bool isCycle(int node, int parent, int dest, vector<vector<int> > &adj, vector<int> &vis, vector<int> &path) {
        vis[node] = 1;
        
        // explore adjacent nodes:
        for(auto &ngbr: adj[node]) {
            if(!vis[ngbr]) {
                if(isCycle(ngbr, node, dest, adj, vis, path) == true) {
                    path.push_back(ngbr);
                    return true;
                }
            }
            // if neighbour node is already visited before and
            // neighbour node is not the parent, means we occur a cycle.
            // also we need to make sure we won't revisit the path from where we are coming to reach destination.
            else if(ngbr != parent && ngbr == dest) {
                path.push_back(ngbr);
                return true;
            }
        }
        
        return false;   // no cycle, means not possible..
    }
public:
    void solve(vector<vector<int> > &adj) {
        int size = adj.size();
        
        vector<int> path;
        bool isPossible = false;
        

        for(int i = 1; i < size ;i++) {
            vector<int> vis(size, 0);
            if(isCycle(i, -1, i,  adj, vis, path) == true) {
                path.push_back(i);  // if found push it into path
                isPossible = true;  // mark it true
                break;  // break out.
            }
        }

        
        if(isPossible) {
            cout << path.size() << endl;
            reverse(begin(path), end(path));
            for(auto &it: path) cout << it << " ";
            cout << endl;
        }else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
};



int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int> > adj(n + 1);    // creating (n + 1) size of graph list, because of 1 based indexing.
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    obj.solve(adj);

}