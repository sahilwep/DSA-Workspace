/*

//  1042. Flower Planting With No Adjacent


//  Problem Statement: 
    - You have n gardens, labeled from 1 to n, and an array paths where paths[i] = [xi, yi] describes a bidirectional path between garden xi to garden yi. In each garden, you want to plant one of 4 types of flowers.
    - All gardens have at most 3 paths coming into or leaving it.
    - Your task is to choose a flower type for each garden such that, for any two gardens connected by a path, they have different types of flowers.
    - Return any such a choice as an array answer, where answer[i] is the type of flower planted in the (i+1)th garden. The flower types are denoted 1, 2, 3, or 4. It is guaranteed an answer exists.


//  Example:

    Example 1:
        Input: n = 3, paths = [[1,2],[2,3],[3,1]]
        Output: [1,2,3]
        Explanation:
            Gardens 1 and 2 have different types.
            Gardens 2 and 3 have different types.
            Gardens 3 and 1 have different types.
            Hence, [1,2,3] is a valid answer. Other valid answers include [1,2,4], [1,4,2], and [3,2,1].

    Example 2:
        Input: n = 4, paths = [[1,2],[3,4]]
        Output: [1,2,1,2]

    Example 3:
        Input: n = 4, paths = [[1,2],[2,3],[3,4],[4,1],[1,3],[2,4]]
        Output: [1,2,3,4]


// Observations:
    - Given n nodes, from 1 to n
    - given edges {u, v} undirected edges from node u to node v
    - for each node we want to color it by one of the 4 type of color {1, 2, 3, 4}
    - all node have at-most 3 directly edges.
    - we will have to choose the color type for each node, such that any two node connected have different color.
    - return any such a choice as an array answer, ware ans[i] => color of node.
    - The flower type are denotes 1,2,3,4... it is guarantee an answer exist.
    
                [1]-------------[2]------------[3]
                 |                              |
                 |______________________________|

                color are from 1 to 4
                        ClrNo = (i + 1) % 4
                    
    - This problem is simillar as bipartite, here we will have options to color it with 4 colors.
    - we can write any BFS/DFS to color the nodes of graph.
    - During every call: 
        - First we will will have to check which node adjacent neighbors are not yet colored:
            - we have 4 available color:
                - If adjacent neighbors are colored: 
                    - we will the used colors.

        - Now, From all the available colors:
            - we will pick the color that are not yet used.
                - we will color the current node with that color.

        - and we will check the current node adjacent neighbors:
            - and if it's not yet colored:
                - explore them..
   

    // Complexity:
        - TC: O(V + E)
        - SC: O(V + E)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution {
private:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& clr) {
        // Check which color used by neighbour:
        vector<bool> used(4, false);    // we are limit that at-max we can have 4 neighbors, and we have 4 colors to fill
        for(auto &ngbr: adj[node]) {
            if(clr[ngbr] != -1) {
                used[clr[ngbr]] = true;
            }
        }
        
        // pick the first available color and color it:
        for(int c = 0; c < 4; c++) {
            if(!used[c]) {
                clr[node] = c;
                break;
            }
        }

        for(auto &ngbr: adj[node]) {
            if(clr[ngbr] == -1) {
                dfs(ngbr, adj, clr);
            }
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        
        // Build graph adj list: making 0-based index.
        vector<vector<int>> adj(n);
        for(auto &i: paths) {
            adj[i[0] - 1].push_back(i[1] - 1);
            adj[i[1] - 1].push_back(i[0] - 1);
        }

        // Now fill colors:
        vector<int> clr(n, -1);
        for(int i = 0; i < n; i++) {
            if(clr[i] == -1) {
                dfs(i, adj, clr);
            }
        }

        // increment every value so that our answer in range [1..4]
        for(auto &i: clr) i++;

        return clr;
    }
};