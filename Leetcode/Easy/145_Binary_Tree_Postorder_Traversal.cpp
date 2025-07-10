/*

//  145. Binary Tree Postorder Traversal


//  Problem Statement: 
    -> Given the root of a binary tree, return the postorder traversal of its nodes' values.

    

    Example 1:
        Input: root = [1,null,2,3]
        Output: [3,2,1]
        Explanation:

    Example 2:
        Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
        Output: [4,6,7,5,2,9,8,3,1]
        Explanation:

    Example 3:
        Input: root = []
        Output: []

    Example 4:
        Input: root = [1]
        Output: [1]


// Post-Order: 
    -> Explore left sub-tree
    -> Explore right sub-tree
    -> Print Root


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
private:
    vector<int> ans;
    void solve(TreeNode* root) {
        if(root == NULL) return;
        
        solve(root->left);
        solve(root->right);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        solve(root);

        return ans;
    }
};