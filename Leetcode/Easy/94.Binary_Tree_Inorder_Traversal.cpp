/*

//  94. Binary Tree Inorder Traversal


//  Observations: 
    * We are given a binary tree, & we need to traverse it in InOrder
    * InOrder: traversal order (left) -> (root) -> (right)


// Example 1:

    Input: root = [1,null,2,3]
                                [1]
                                  \
                                   [2]
                                   /
                                 [3]
    Output: [1,3,2]

    Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]
                            [1]
                             |
                        /--------\
                      [2]        [3]
                       |
                 /---------\
                [4]        [5]

    Output: [4,2,6,5,7,1,3,9,8]

    Input: root = []
    Output: []



// Intrusion:
    // Base Condition:
    // Decision Tree:




*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void inOrder(TreeNode *root, vector<int> &v){
        if(root != NULL){
            inOrder(root->left, v);
            v.push_back(root->val);
            inOrder(root->right, v);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inOrder(root, res);
        return res;
    }
};

