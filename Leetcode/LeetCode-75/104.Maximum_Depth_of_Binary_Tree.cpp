/*

//  104. Maximum Depth of Binary Tree


//  Observations: 
    * We are given an binary tree, & we need to find the depth of it...

// Example:

    Input: root = [3,9,20,null,null,15,7]   
                                [3]
                               /   \
                             [9]   [20]
                                   / \
                               [15]  [7]

    Output: 3


    Input: root = [1,null,2]
    Output: 2


// Intrusion: 
    * For any given node, we have two options, left & right,
    * For any node, we need to find the maximum b/w left & right
    * at ever node we will increment the level by 1...
         
    * Writing Recursive Solution:
        * Recursive call to left & right.
        * At every level increment the result by 1.
        * when node become null return



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(){
        val = 0;
        left = right = nullptr;
    }
    TreeNode(int x){
        val = x;
        left = right = nullptr;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right){
        val = x;
        left = left;
        right = right;
    }
};


class Solution {
public:
    // Function to find the depth of tree:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};