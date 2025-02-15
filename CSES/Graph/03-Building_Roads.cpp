/*

//  CSES: Building Roads


//  Problem Statement:
    -> Byteland has n cities, and m roads between them. The goal is to construct new roads so that there is a route between any two cities.
    -> Your task is to find out the minimum number of roads required, and also determine which roads should be built.

// Input
    -> The first input line has two integers n and m: the number of cities and roads. The cities are numbered 1,2,\dots,n.
    -> After that, there are m lines describing the roads. Each line has two integers a and b: there is a road between those cities.
    -> A road always connects two different cities, and there is at most one road between any two cities.

// Output
    -> First print an integer k: the number of required roads.
    -> Then, print k lines that describe the new roads. You can print any valid solution.


// Approach: 
    -> We just need find the number of multiple components for which graph is broken.
    -> Also when we need to store the nodes where the components are breaking.

    
// Complexity:
    -> TC: O(V + 2E) -> Because of dfs calls.
    -> SC: O(V) -> Because of recursive calls.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    int V;
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis) {    // function to visit every node of from the given component
        vis[node] = 1;
        
        for(auto &it: adj[node]) {
            if(!vis[it]) {
                dfs(it, adj, vis);
            }
        }
    }
public:
    void solve(vector<vector<int>> &adj) {
        V = adj.size(); // this will return size of adj, & it's one more than given 'n', there is no-need to declare any V + 1 size of any vis & also no need to iterate till V.
        
        vector<int> vis(V, 0);
        
        vector<pair<int, int>> nds;
        int cnt = 0;
        for(int i = 1; i < V; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis);  
                if(i != 1) {    // we will not store the first node, as it's the starting point.
                    nds.push_back({i-1, i});
                    cnt++;
                }
            }
        }
        
        cout << cnt << endl;
        for(auto i: nds) {
            cout << i.first << " " << i.second << endl;
        }
    }
};


int main(){
    
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> adj(n+1);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    Solution obj;
    obj.solve(adj);
    
    
    return 0;
}