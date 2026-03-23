/*

//  103. Binary Tree Zigzag Level Order Traversal


//  Problem Statement: 
    - Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).
 
// Example:
    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: [[3],[20,9],[15,7]]

    Example 2:
        Input: root = [1]
        Output: [[1]]

    Example 3:
        Input: root = []
        Output: []


// Observations:
    - We are given root of the binary tree
    - and we have print the nodes in level-by-level in zig-zag pattern.

    // Approach:
        - BFS will let's us find the nodes in every level
        - it's just we need to reverse the nodes order in odd level, if we observe the example.

        // Complexity:
            - TC: O(n)
            - SC: O(n)
                - n = number of nodes

            // Extra:
                - BFS Complexity is:
                    - TC: O(V + E), V = vertices, E = edges
                    - here We have binary tree: 
                        means ever vertices at-most connected by 3 edges
                            one above, and two down.
                    - So, TC for binary tree is O(n * 3) => O(n)


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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        // Edge case:
        if(root == NULL) {
            return {};
        }
        
        // BFS:
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);
        int level = 0;
        while(!q.empty()) {
            int size = q.size();
            vector<int> nodes;
            
            while(size--) {
                TreeNode* root = q.front();
                q.pop();
                nodes.push_back(root->val);

                // Explore left
                if(root->left != NULL) q.push(root->left);

                // Explore right:
                if(root->right != NULL) q.push(root->right);
            }

            if(level % 2 != 0) reverse(begin(nodes), end(nodes));   // at every odd level, we will reverse the order.
            ans.push_back(nodes);

            level++;
        }

        return ans;
    }
};