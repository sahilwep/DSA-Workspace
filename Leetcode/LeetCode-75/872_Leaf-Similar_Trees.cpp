/*

//  872. Leaf-Similar Trees

// Problem Statement:
    * Consider all the leaves of a binary tree, from left to right order, the values of those leaves form a leaf value sequence.
    * For example, in the given tree above, the leaf value sequence is (6, 7, 4, 9, 8).
    * Two binary trees are considered leaf-similar if their leaf value sequence is the same.
    * Return true if and only if the two given trees with head nodes root1 and root2 are leaf-similar.


// Example:
    Example 1:
        Input: root1 = [3,5,1,6,2,9,8,null,null,7,4], root2 = [3,5,1,6,7,4,2,null,null,null,null,null,null,9,8]
        Output: true

    Example 2:
        Input: root1 = [1,2,3], root2 = [1,3,2]
        Output: false



// Approach:
    -> Get the leaf of every tree
    -> Compare whether they are same or not?
    -> Order should be maintain.


*/

#include<bits/stdc++.h>
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
private:
    // Function to get the leaf of tree:
    void leafOfTree(TreeNode *root, vector<int> &list){ 
        // Base case:
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL){
            list.push_back(root->val);
            return;
        }

        // Recursive Case: decision tree -> recursively visit in left & right
        leafOfTree(root->left, list);
        leafOfTree(root->right, list);
    }
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Getting leaf of first tree:
        vector<int> list1;
        leafOfTree(root1, list1);

        // Getting leaf of second tree:
        vector<int> list2;
        leafOfTree(root2, list2);

        // Compare these two lists:
        if(list2.size() != list1.size()) return 0;  // if size is not same return false
        for(int i=0;i<list1.size();i++){
            if(list1[i] != list2[i]) return 0;  // if leaf values are not equal return false
        }

        return 1;   // else return true
    }
};