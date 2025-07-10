/*

//  112. Path Sum


//  Problem Statement: 
    -> Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
    -> A leaf is a node with no children.

 
// Example: 
    Example 1:
        Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
        Output: true
        Explanation: The root-to-leaf path with the target sum is shown.

    Example 2:
        Input: root = [1,2,3], targetSum = 5
        Output: false
        Explanation: There are two root-to-leaf paths in the tree:
        (1 --> 2): The sum is 3.
        (1 --> 3): The sum is 4.
        There is no root-to-leaf path with sum = 5.

    Example 3:
        Input: root = [], targetSum = 0
        Output: false
        Explanation: Since the tree is empty, there are no root-to-leaf paths.


// Observations: 
    -> We need to compute the sum from the path starting from root & goes up till leaf node
    -> Return true if ther's some path exist.


    // Approach: 
        -> If we reaches till NULL position return false
        -> If we reaches at node where
            -> left & right are null, generally considered as leaf node
            -> & including that value will makes up sum
            -> return true

        -> Explore all possible case and take OR || from all the branch, if any return true, we will get true as our answer, else return false..

    
    // Complexity: 
        -> TC: O(N)
        -> SC: O(H)
            -> H = height of tree, Generally
            -> In worse O(N) Skewed tree

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
    bool solve(TreeNode* root, int targetSum) {
        if(root == NULL) return false;  // if we reach to NULL return won't able to make sum

        // If it's a leaf node, check if remaining targetSum equals its value || target - sum == 0
        if(root->left == NULL && root->right == NULL && targetSum - root->val == 0) return true;

        // Explore all possible branches: if any return true OR -> return true
        return solve(root->left, targetSum - root->val) || solve(root->right, targetSum - root->val);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        
        return solve(root, targetSum);
    }
};