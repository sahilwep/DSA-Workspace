/*

//  863. All Nodes Distance K in Binary Tree


//  Problem Statement: 
    - Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
    - You can return the answer in any order.
 
// Example:
    Example 1:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
        Output: [7,4,1]
        Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

    Example 2:
        Input: root = [1], target = 1, k = 3
        Output: []

 
// Constraints:

    The number of nodes in the tree is in the range [1, 500].
    0 <= Node.val <= 500
    All the values Node.val are unique.
    target is the value of one of the nodes in the tree.
    0 <= k <= 1000



// Observations:
    - Given root of binary tree, and target, and integer k, return an array of value of all nodes that have a distance k, from the target node.

    // Approach:
        - convert the given tree into graph
            - we can use any BFS/DFS and simply fetch the adjacent nodes, and build edge list OR directly create graph adj list.
        - once we have adj list:
            - we can use BFS and find the node that are at level 'k', and return the list of nodes.

        // Complexity:  
            - TC: O(V + E) => O(V)
            - SC: O(V + E) => O(V)

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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        
        // Build graph adj list:
        unordered_map<int, vector<int>> adj;
        inOrder(root, adj);

        // Find the nodes at distance: k
        queue<int> q;
        unordered_set<int> vis;
        int lvl = 0;
        vector<int> ans;
        
        q.push(target->val);
        vis.insert(target->val);
        
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                int node = q.front();
                q.pop();

                if(lvl == k) ans.push_back(node);

                for(auto &ngbr: adj[node]) {
                    if(!vis.count(ngbr)) {
                        vis.insert(ngbr);
                        q.push(ngbr);
                    }
                }
            }
            

            lvl++;
            if(lvl > k) break;
        }

        return ans;
    }
};