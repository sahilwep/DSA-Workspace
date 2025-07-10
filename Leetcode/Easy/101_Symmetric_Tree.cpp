/*

//  101. Symmetric Tree


//  Problem Statement: 
    -> Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 
// Example: 

    Example 1:
        Input: root = [1,2,2,3,4,4,3]
        Output: true

    Example 2:
        Input: root = [1,2,2,null,3,null,3]
        Output: false

 
// Observations: 
    -> Given binary tree node, find wether it's symmetric if we cut them in half

    // Approach: 
        -> Start with two Iterators/Pointers starting from "root"
        -> If any pointer finish early return false
        -> If any pointers values are not same return false
        -> Explore all left & right calls with opposite directions sets for both the pointers
        

        // Complexity: 
            -> TC: O(N)
            -> SC: O(h)
                -> h = tree height
                    -> Due to recursion stack, In worse case (skewed tree), h = n, For balance tree, h = logn
                    

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
    bool solve(TreeNode* it1, TreeNode* it2) {
        if(it1 == NULL && it2 == NULL) return true; // If both finish at same time

        
        if(it1 == NULL || it2 == NULL || it1->val != it2->val) return false;    // If any one finish early.
        if(it1->val != it2->val) return false;  // values are not equal
        
        bool left = solve(it1->left, it2->right);
        bool right = solve(it1->right, it2->left);

        return (left && right);     // return true only if both the calls return true (AND case)
    }
public:
    bool isSymmetric(TreeNode* root) {
        
        // Create two Iterators
        TreeNode* it1 = root;
        TreeNode* it2 = root;


        return solve(it1, it2);
    }
};