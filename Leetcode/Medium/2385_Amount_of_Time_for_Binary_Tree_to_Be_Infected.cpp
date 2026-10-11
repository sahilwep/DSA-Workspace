/*

//  2385. Amount of Time for Binary Tree to Be Infected


//  Problem Statement: 
You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

    The node is currently uninfected.
    The node is adjacent to an infected node.

Return the number of minutes needed for the entire tree to be infected.


// Example:
    Example 1:
        Input: root = [1,5,3,null,4,10,6,9,2], start = 3
        Output: 4
        Explanation: The following nodes are infected during:
        - Minute 0: Node 3
        - Minute 1: Nodes 1, 10 and 6
        - Minute 2: Node 5
        - Minute 3: Node 4
        - Minute 4: Nodes 9 and 2
        It takes 4 minutes for the whole tree to be infected so we return 4.

    Example 2:
        Input: root = [1], start = 1
        Output: 0
        Explanation: At minute 0, the only node in the tree is infected so we return 0.




// Observations:
    - Given root of binary tree, with unique evaluates, and integer start. at minute 0 an infections start from the node with value start.
    - each minutes nodes become infected if:
        - the node is currently uninfected.
        - the node is adjacent to an infected node.
    - Return the number of minutes needed for the entire tree to be infected..

    // Approach:    
        - simple approach is to run BFS from the given START, and find the depth of the given graph.
            - but given root of the binary tree.
            - so it's kind of complicated to find the depth from the certain node.
            - what i think of converting the tree into edge list.
            - and form the edge list build graph adj list:
                - and find the Depth of the graph.
            - Or rather, we can directly build the adj list:
                - as we grow from root:

                        [root]
                        /    \
                    left     right

                - we will build the adj list:
                    left:
                        adj[root].push_back(left)
                        adj[left].push_back(root)
                    right:
                        adj[root].push_back(right)
                        adj[right].push_back(root)

                - this way we can build the graph adj list:
                - it's just we need to run any bfs/dfs from tree root node, and build graph adj list,
                    - and after that we can write the BFS, and find the max_depth of graph...

        // Complexity:
            - TC: O(V + E)
            - SC: O(V + E)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
private:
    void inOrder(TreeNode* root, unordered_map<int, vector<int>>& adj) {
        if(root == NULL) return;

        int u = root->val;
        
        if(root->left != NULL) {
            int v = root->left->val;

            adj[u].push_back(v);
            adj[v].push_back(u);

            inOrder(root->left, adj);
        }

        if(root->right != NULL) {
            int v = root->right->val;
            
            adj[u].push_back(v);
            adj[v].push_back(u);

            inOrder(root->right, adj);
        }
    }
public:
    int amountOfTime(TreeNode* root, int start) {
        
        // Build graph adj list:
        unordered_map<int, vector<int>> adj;
        inOrder(root, adj);

        // Process BFS: find the max_level:
        queue<int> q;
        unordered_set<int> vis;

        q.push(start);
        vis.insert(start);

        int lvl = 0;

        while(!q.empty()) {
            int size = q.size();
            bool isNewLvlFound = false;

            while(size--) {
                int node = q.front();
                q.pop();

                // Explore adj neighbors:
                for(auto &ngbr: adj[node]) {
                    if(!vis.count(ngbr)) {
                        q.push(ngbr);
                        vis.insert(ngbr);
                        isNewLvlFound = true;
                    }
                }
            }

            if(isNewLvlFound) lvl++;
        }

        return lvl;
    }
};