/*

//  3310. Remove Methods From Project


//  Problem Statement: 
    - You are maintaining a project that has n methods numbered from 0 to n - 1.
    - You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi.
    - There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
    - A group of methods can only be removed if no method outside the group invokes any methods within it.
    - Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.

 
// Example:
    Example 1:
        Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
        Output: [0,1,2,3]
        Explanation: Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.

    Example 2:
        Input: n = 5, k = 0, invocations = [[1,2],[0,2],[0,1],[3,4]]
        Output: [3,4]
        Explanation: Methods 0, 1, and 2 are suspicious and they are not directly invoked by any other method. We can remove them.

    Example 3:
        Input: n = 3, k = 2, invocations = [[1,2],[0,1],[2,0]]
        Output: []
        Explanation: All methods are suspicious. We can remove them.

 

// Constraints:
    1 <= n <= 1e5
    0 <= k <= n - 1
    0 <= invocations.length <= 2 * 1e5
    invocations[i] == [ai, bi]
    0 <= ai, bi <= n - 1
    ai != bi
    invocations[i] != invocations[j]



// Observations:
    - We are given n nodes from 0 to n.
    - we are given node 'k', which says to be infected..
    - and we are given invocations or say edges..
    - from node 'k' to all the possible path that leads to any node, we will consider them as infected.
    - Our goal is to remove all the infected node.
    - Exception: If there's is any safe node which leads to infected ones, then straight away return all all the nodes, because we can't remove any of them...
    - NOTE: graph can be distributed in multiple components, i thought of it and thought of returning only the infected component, but if exception occur, then we will are returning all of them, so we no need to worry about the multiple components..
    

    // Approach:
        - first get all the infected node from node 'k', using dfs/bfs.
        - once we have infected list, we will iterate in given "invocations", and check wether any safe node reaches to any infected node?
            - check if safeNode--reaches-->infectedNode:
            - If that's the case happening, return all the elements.
        - else remove all the infected ones, and return only safe nodes.

    // Complexity:
        - TC: O(V + E)
        - SC: O(V + E)
            - V = nodes
            - E = edges

*/

class Solution {
private:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, unordered_set<int>& infected) {
        vis[node] = 1;              // mark that node as visited.
        infected.insert(node);      // push that current node into the infected

        for(auto &v: adj[node]) {
            if(!vis[v]) {
                dfs(v, vis, adj, infected);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
        // Build Graph adj list:
        vector<vector<int>> adj(n);
        for(auto &it: invocations) {    // O(E)
            int u = it[0], v = it[1];
            adj[u].push_back(v);    // directed graph
        }

        vector<int> vis(n, 0);
        unordered_set<int> infected;
        dfs(k, vis, adj, infected); // O(V + E)

        // Check wether any safe node falls into the infected node path.
        for(auto &i: invocations) { // O(E + V)
            int u = i[0], v = i[1];
            // safe node reaches to infected ones:
            if(!infected.count(u) && infected.count(v)) {   // O(V), this runs only ones.
                // return the whole list:
                vector<int> ans;
                for(int i = 0; i < n; i++) ans.push_back(i);

                return ans;
            }
        }

        // Else return rest of the node, except the infected one..
        vector<int> ans;
        for(int i = 0; i < n; i++) {    // O(V)
            if(!infected.count(i)) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};

