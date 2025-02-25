/*

//  G-43: Find the City With the Smallest Number of Neighbors at a Threshold Distance

//  Problem Statement: 
    -> There are n cities labeled from 0 to n-1 with m edges connecting them. Given the array edges where edges[i] = [from[i] , to[i] ,weight[i]]  represents a bidirectional and weighted edge between cities from[i] and to[i], and given the integer distanceThreshold. 
    -> You need to find out a city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance.
    -> If there are multiple such cities, our answer will be the city with the greatest label.

    // Note: The distance of a path connecting cities i and j is equal to the sum of the edge's weights along that path.


// Example:
    Example 1:
        Input:
            n = 4, m = 4
            edges = [[0, 1, 3],
                    [1, 2, 1], 
                    [1, 3, 4],  
                    [2, 3, 1]]
            distanceThreshold = 4
        Output: 3
        Explaination:
            The neighboring cities at a distanceThreshold = 4 for each city are:
            City 0 -> [City 1, City 2] 
            City 1 -> [City 0, City 2, City 3] 
            City 2 -> [City 0, City 1, City 3] 
            City 3 -> [City 1, City 2] 
            Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.

    Example 2:
        Input: 
            n = 5, m = 6
            edges = [[0, 1, 2],
                    [0, 4, 8],
                    [1, 2, 3], 
                    [1, 4, 2], 
                    [2, 3, 1],
                    [3, 4, 1]]
            distanceThreshold = 2.
        Output: 0
        Explaination:
            The neighboring cities at a distanceThreshold = 2 for each city are:
            City 0 -> [City 1] 
            City 1 -> [City 0, City 4] 
            City 2 -> [City 3, City 4] 
            City 3 -> [City 2, City 4]
            City 4 -> [City 1, City 2, City 3] 
            The city 0 has 1 neighboring city at a distanceThreshold = 2.

// Your Task:
    -> You don't need to read input or print anything. Your task is to complete the function findCity() which takes a number of nodes n, total number of edges m and vector of edges and distanceThreshold. 
    -> and return the city with the smallest number of cities that are reachable through some path and whose distance is at most Threshold Distance. 
    -> If there are multiple such cities, return the city with the greatest label.

// Expected Complexity: 
    -> Expected Time Complexity: O(n2 + length(edges)*nlog(n) )
    -> Expected Auxiliary Space:  O(n3)


// Constraints:
    1  ≤  n ≤  100
    1 <= m <= n*(n-1)/2
    length(edges[i]) == 3
    0 <= from[i] < toi < n
    1 <= weight[i] distanceThreshold <= 10^4
    All pairs (from[i], to[i]) are distinct

// Observations: 
    -> we are given edges contains path u -----> v with their edge weight.
    -> we are also given distanceThreshold, which is another constrains to build our answer.
    -> We need to find the path from every city to every city, which limits inside the constrains "distanceThreshold".
    -> We will have to return the city that connects the minimum number of neighbour/city.
    -> If there were multiple such city with same number of minium neighbour, then return the largest numbered city.

    // Patterns:
        -> First we need to find the path from multiple source to multiple destinations, which directs us to multi-sourced shortest path algorithms.
        -> We will use "Floyd Warshall" to find that multisource path.


    // Approach:
        -> We are given edges of graph, which we need to convert in graph adj-matrix, which will help us to find the shortest path for multi-source to multi-destinations.
            -> NOTE: during Graph building for invalid path we will insert very large value near to infinity.
        -> After that we will use "Floyd Warshall" for solving that question.

// Solutions Complexity:
    -> TC: O(n^3), because of Floyd Warshall
    -> SC: O(n^2), because we are building the graph.


// Efficient Approach: 
    -> One efficient Approach is to use Dijkstra's Algorithm, to find shortest path for every node.
    -> and then Generate our answer.
    -> For every node run Dijkstra's & get the Distance for every node to every other nodes & build Such matrix.
    -> Last filter the given constrains & return answer.


    // Complexity:
        -> TC: O(V * (E * log(V)))
        -> SC: O(n^2), for building ajd-matrix & adj-list..


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

// Efficient: Dijkstra's Algorithm -> TC (V * (E * log(V)))
class Solution {
private:
    typedef pair<int, int> pr;
    vector<int> dijkstra(int src, vector<vector<pair<int, int>>> &adj, int n) { // Dijkstra's return distance from source to every node, TC: O(E * log(V))
        
        vector<int> dist(n, INT_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;
        dist[src] = 0;
        pq.push({0, src});  // push cost & source node
        
        
        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            
            int cost = it.first;
            int node = it.second;
            
            // Skip un-usual Iterations
            if(cost > dist[node]) continue;
            
            // Exploring Adj nodes:
            for(auto &it: adj[node]) {
                int v = it.first;
                int wt = it.second;
                
                if(cost + wt < dist[v]) {
                    dist[v] = cost + wt;
                    
                    pq.push({cost + wt, v});
                }
            }
        }
        
        return dist;
    }
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        // Building Graph Adj-List For Dijkstra's:
        vector<vector<pair<int, int>>> adj(n);
        
        for(auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // For undirected nodes:
            adj[u].push_back({v, wt});
            adj[v].push_back({u, wt});
        }
        
        // Dijkstra's call for every nodes: TC: O(V * (E * log(V)))
        vector<vector<int>> mat;
        for(int i = 0; i < n; i++) {
            mat.push_back({dijkstra(i, adj, n)});   // dijkstra's call for every_node
        }
        
        
        // Returning the answer From matrix:
        vector<int> city(n, 0); // Store every city
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && mat[i][j] <= distanceThreshold) {
                    city[i]++;
                }
            }
        }
        
        int ans = 0;    // Find the minimum city, let's assume city is '0' the first index
        for(int i = 1; i < city.size(); i++) {
            if(city[i] <= city[ans]) {
                ans = i;
            }
        }
        
        return ans;
    }
};


// BruteForce: Floyd Warshall -> TC: O(n^3)
class Solution {
public:
    int findCity(int n, int m, vector<vector<int>>& edges, int distanceThreshold) {
        
        // Building Graph Adj-matrix:
        vector<vector<int>> mat(n, vector<int> (n, 1e9));   //1e9, because that limits inside the constrains
        
        for(int i = 0; i < n; i++) {    // path of node to itself will be '0'
            mat[i][i] = 0;
        }
        
        for(auto &it: edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            
            // For undirected nodes:
            mat[u][v] = wt;
            mat[v][u] = wt;
        }
        
        
        // Floyd Warshall:
        for(int k = 0; k < n; k++) {    // Via every node:
            for(int u = 0; u < n; u++) {    // from 'u'
                for(int v = 0; v < n; v++) {    // to 'v'
                    // Calculating Cost:
                    mat[u][v] = min(mat[u][v], mat[u][k] + mat[k][v]);
                }
            }
        }
        
        // Returning the answer From matrix:
        vector<int> city(n, 0); // Store every city
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && mat[i][j] <= distanceThreshold) {
                    city[i]++;
                }
            }
        }
        
        int ans = 0;    // Find the minimum city, let's assume city is '0' the first index
        for(int i = 1; i < city.size(); i++) {
            if(city[i] <= city[ans]) {
                ans = i;
            }
        }
        
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
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
        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
        cout << "~" << "\n";
    }
}