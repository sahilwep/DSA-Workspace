/*

//  110. Balanced Binary Tree


//  Problem Statement: 
    - Given a binary tree, determine if it is height balanced.
    - Hight balance: A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

 
// Example:
    Example 1:
        Input: root = [3,9,20,null,null,15,7]
        Output: true

    Example 2:
        Input: root = [1,2,2,3,3,null,null,4,4]
        Output: false

    Example 3:
        Input: root = []
        Output: true

 
// Observations:
    - Given root binary tree
    - we need to find if it's height balanced or not?

    // Approach:
        - For every branch we will calculate the depth
        - for every node if the sub-tree nodes depth difference more than 1, say not balanced.
        - else balanced.
        - We can use something like dfs, which will help us to find the depth of binary tree.

    // Complexity:
        - TC: O(n)
        - SC: O(h)
            - n = total number of nodes
            - h = maximum height of binary tree, that's the depth.


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
    bool ans;
    int solve(TreeNode* root) {
        // Base case: if no-branches further, nothing found return 0;
        if(root == NULL) return 0;

        // Explore left & right:
        int left = solve(root->left) + 1;
        int right = solve(root->right) + 1;

        // Height balanced Conditions check:
        if(abs(right - left) > 1) {
            ans = false;
        }

        return max(left, right);    // return the maximum height find so far in branch.
    }
public:
    bool isBalanced(TreeNode* root) {
        ans = true; // assume the tree is balanced

        solve(root);    // check if tree is really balanced.

        return ans;     // return ans
    }
};