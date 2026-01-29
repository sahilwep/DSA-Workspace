/*

//  2976. Minimum Cost to Convert String I


//  Problem Statement: 
    - You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
    - You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
    - Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
    - Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

 
// Example:
    Example 1:
        Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
        Output: 28
        Explanation: To convert the string "abcd" to string "acbe":
        - Change value at index 1 from 'b' to 'c' at a cost of 5.
        - Change value at index 2 from 'c' to 'e' at a cost of 1.
        - Change value at index 2 from 'e' to 'b' at a cost of 2.
        - Change value at index 3 from 'd' to 'e' at a cost of 20.
        The total cost incurred is 5 + 1 + 2 + 20 = 28.
        It can be shown that this is the minimum possible cost.

    Example 2:
        Input: source = "aaaa", target = "bbbb", original = ["a","c"], changed = ["c","b"], cost = [1,2]
        Output: 12
        Explanation: To change the character 'a' to 'b' change the character 'a' to 'c' at a cost of 1, followed by changing the character 'c' to 'b' at a cost of 2, for a total cost of 1 + 2 = 3. To change all occurrences of 'a' to 'b', a total cost of 3 * 4 = 12 is incurred.

    Example 3:
        Input: source = "abcd", target = "abce", original = ["a"], changed = ["e"], cost = [10000]
        Output: -1
        Explanation: It is impossible to convert source to target because the value at index 3 cannot be changed from 'd' to 'e'.

        
// Observations:
    - If we observe the given original and changed we will found out it's a directed graph, and cost associate to travel from u -> v
    - We have to find out shortest distance from every possible nodes.
    - so that we can build source to target transitions.
    - In simple:
        - Build directed graph with given weight cost.
        - Find shortest path from every possible source: multi-source shortest path
            - floyd warshall
                - Floyd warshall used to compute the multi-source path.
            - dijkstra's
                - We can compute dijkstra's from all the possible source & build matrix.


    // Dijkstra's Complexity:
            - TC: O(E)
            - SC: O(V)

    // Dijkstra's Complexity:
            - TC: O(E)
            - SC: O(1)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


// Floyd warshall:
class Solution {
private:
    typedef long long ll;
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        // Build Directed weighted graph adj matrix:
        vector<vector<ll>> mat(26, vector<ll> (26, LLONG_MAX));
        for(int i = 0; i < n; i++) {
            int u = (original[i] - 'a');
            int v = (changed[i] - 'a');
            int wt = cost[i];

            mat[u][v] = min(mat[u][v], (ll)wt);
        }

        for(int i = 0; i < 26; i++) mat[i][i] = 0;  // self node reaches with cost '0'
        
        // Build multi-source path - Floyd Warshall:
        for(int k = 0; k < 26; k++) {
            for(int u = 0; u < 26; u++) {
                for(int v = 0; v < 26; v++) {
                    if(mat[u][k] != LLONG_MAX && mat[k][v] != LLONG_MAX) {
                        ll newCost = mat[u][k] + mat[k][v];
                        mat[u][v] = min(mat[u][v], newCost);
                    }
                }
            }
        }

        // Check for negative cycle:
        for(int i = 0; i < 26; i++) {
            if(mat[i][i] < 0) {
                return -1;  // negative cycle found
            }
        }

        // Find the cost of shortest path for every possible chance in source -> target:
        ll totalCost = 0;
        int srcSize = source.size();
        for(int i = 0; i < srcSize; i++) {
            if(source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                ll cost = mat[u][v];

                if(cost == LLONG_MAX) return -1;  // not reachable

                totalCost += cost;
            }
        }

        return totalCost;
    }
};


// Dijkstra's impl:
class Solution {
private:
    typedef long long ll;
    typedef pair<ll, ll> pr;    // cost, node
    vector<ll> dijkstra(int src, vector<vector<pair<int, int>>> adj) {  // since cost is not -ve we used dijkstra's
        
        vector<ll> dist(26, LLONG_MAX);
        priority_queue<pr, vector<pr>, greater<>> pq;

        pq.push({0, src});
        dist[src] = 0;

        while(!pq.empty()) {
            auto [cost, node] = pq.top();
            pq.pop();

            if(cost > dist[node]) continue; // not need check heavy cost.

            for(auto &[v, wt]: adj[node]) {
                ll newCost = cost + (ll)wt;
                if(newCost < dist[v]) {
                    dist[v] = newCost;
                    pq.push({newCost, v});
                }
            }
        }

        return dist;
    }
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();

        // Build Directed weighted graph adj list:
        vector<vector<pair<int, int>>> adj(26); // at max we have 26 characters
        for(int i = 0; i < n; i++) {
            int u = (original[i] - 'a');
            int v = (changed[i] - 'a');
            int wt = cost[i];
            adj[u].push_back({v, wt});
        }
        
        // Build multi-source shortest path for all a-z characters:
        vector<vector<ll>> multiDist;
        for(char ch = 'a'; ch <= 'z'; ch++) {
            int src = (ch - 'a');
            vector<ll> dist = dijkstra(src, adj);
            multiDist.push_back(dist);
        }

        // Find the cost of shortest path for every possible chance in source -> target:
        ll totalCost = 0;
        int srcSize = source.size();
        for(int i = 0; i < srcSize; i++) {
            if(source[i] != target[i]) {
                int u = source[i] - 'a';
                int v = target[i] - 'a';
                ll cost = multiDist[u][v];

                if(cost == LLONG_MAX) return -1;  // not reachable

                totalCost += cost;
            }
        }

        return totalCost;
    }
};