/*

//  144. Binary Tree Preorder Traversal


//  Problem Statement: 
    -> Given the root of a binary tree, return the preorder traversal of its nodes' values.


// Example:
    Example 1:
        Input: root = [1,null,2,3]
        Output: [1,2,3]
        Explanation:

    Example 2:
        Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
        Output: [1,2,4,5,6,7,3,8,9]
        Explanation:

    Example 3:
        Input: root = []
        Output: []

    Example 4:
        Input: root = [1]
        Output: [1]


// In-Order: 
    -> Print Root
    -> Explore left sub-tree
    -> Explore right sub-tree


    // Complexity:
        -> TC: O(N)
        -> SC: O(N)

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
    vector<int> ans;
    void solve(TreeNode* root) {
        if(root == NULL) return;
        
        ans.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        
        solve(root);

        return ans;
    }
};