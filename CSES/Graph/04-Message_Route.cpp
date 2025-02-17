/*

//  CSES: Message Route

//  Problem Statement: 
    -> Syrjälä's network has n computers and m connections. Your task is to find out if Uolevi can send a message to Maija, and if it is possible, 
    -> what is the minimum number of computers on such a route.

// Input
    -> The first input line has two integers n and m: the number of computers and connections. The computers are numbered 1,2,....n. Uolevi's computer is 1 and Maija's computer is n.
    -> Then, there are m lines describing the connections. Each line has two integers a and b: there is a connection between those computers.
    -> Every connection is between two different computers, and there is at most one connection between any two computers.


// Output
    If it is possible to send a message, first print k: the minimum number of computers on a valid route. After this, print an example of such a route. You can print any valid solution.
    If there are no routes, print "IMPOSSIBLE".

// Constraints

    2 <= n  <= 10^5
    1 <= m  <= 2 \cdot 10^5
    1 <= a,b <= n

// Example
    Input:
        5 5
        1 2
        1 3
        1 4
        2 3
        5 4

    Output:
        3
        1 4 5


// Observations: 
    -> we are given n nodes & b/w them m edges..
    -> We need to find out how many nodes needs to reach from source to destinations.
    -> src = 1, and dest = 'n'
    -> If that path is reachable print the shortest distance, else print "IMPOSSIBLE"
    -> We also need to print the path.
    // Approach: 
        -> Why should we use BFS: because distance from one node to another is '1' for every nodes, and if we use dijkstra's, that also give
        -> Let's solve this using BFS, because of level order traversal, & whenever we reach to destination, we will get our answer.
        -> every path cost will be 1, because we have to count the number of nodes.

// Complexity: 
    -> TC: O(V + 2E)
    -> AS: O(V), for queue, parent, & visited.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

class Solution {
public:
    void solve(vector<vector<int>> &adj) {
        int size = adj.size();
        
        int src = 1;
        int dst = size - 1;


        // BFS:
        queue<pair<int, int>> q;
        vector<int> vis(size, 0);   // visited array
        vector<int> parent(size, -1);
        
        q.push({1, src});
        vis[src] = 1;
        parent[src] = src;  // source parent itself source.
        bool isFound = false;
        int totalCost = -1;

        
        while(!q.empty()) {
            auto [dist, node] = q.front();  // get the nodes & distance from the front of the queue.
            q.pop();    // pop out the element from the queue.

            bool isFoundTemp = false;
            // explore adjacent nodes:
            for(auto &it: adj[node]) {
                if(!vis[it]) {
                    vis[it] = 1;    // mark that visited
                    parent[it] = node;  // sotring the parent
                    q.push({dist + 1, it}); // push it into queue.
                    
                    // At any movement if we reach to the destinations, we will return the cost.
                    if(it == dst) {
                        totalCost = dist + 1;
                        isFound = true;
                        isFoundTemp = true;
                        break;
                    }
                    
                }
            }

            // Check if we found, & exit from the iterations.
            if(isFoundTemp) {
                break;
            }
        }

        // if we wont' be able to reach the destination, we will print "IMPOSSIBLE"
        if(isFound) {
            cout << totalCost << endl;
            // Now backtrack the path from parent vector:
            vector<int> path;
            int node = dst;
            while(parent[node] != node) {
                path.push_back(node);
                node = parent[node];
                
            }
            path.push_back(1);
            reverse(begin(path), end(path));
            for(auto &i: path) cout << i << " ";
            
        }else{
            cout << "IMPOSSIBLE" << endl;
        }
    }
};

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);    // creating (n + 1) size of graph list, because of 1 based indexing.
    
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    Solution obj;
    obj.solve(adj);

}