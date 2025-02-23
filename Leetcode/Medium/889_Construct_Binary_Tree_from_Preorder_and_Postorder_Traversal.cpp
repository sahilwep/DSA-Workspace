/*

//  889. Construct Binary Tree from Preorder and Postorder Traversal


//  Problem Statement: 
    -> Given two integer arrays, preorder and postorder where preorder is the preorder traversal of a binary tree of distinct values and postorder is the postorder traversal of the same tree, reconstruct and return the binary tree.
    -> If there exist multiple answers, you can return any of them.


// Example:

    Example 1:

        Input: preorder = [1,2,4,5,3,6,7], postorder = [4,5,2,6,7,3,1]
        Output: [1,2,3,4,5,6,7]

    Example 2:

        Input: preorder = [1], postorder = [1]
        Output: [1]



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private:
    TreeNode *solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder) {
        if(preStart > preEnd) {
            return NULL;
        }

        TreeNode *root = new TreeNode(preorder[preStart]);
        if(preStart == preEnd) {
            return root;
        }
        int nextNode = preorder[preStart + 1];  // root of the left subtree.

        int j = postStart;
        while(postorder[j] != nextNode) {
            j++;
        }

        int num = j - postStart + 1;

        root->left = solve(preStart + 1, postStart, preStart + num, preorder, postorder);
        root->right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder);

        return root;
    }
public:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n = preorder.size();

        return solve(0, 0, n-1, preorder, postorder);
    }
};