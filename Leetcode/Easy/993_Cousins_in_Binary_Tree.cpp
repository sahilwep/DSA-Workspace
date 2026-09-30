/*

//  993. Cousins in Binary Tree


//  Problem Statement: 
    - Given the root of a binary tree with unique values and the values of two different nodes of the tree x and y, return true if the nodes corresponding to the values x and y in the tree are cousins, or false otherwise.
    - Two nodes of a binary tree are cousins if they have the same depth with different parents.
    - Note that in a binary tree, the root node is at the depth 0, and children of each depth k node are at the depth k + 1.

    
// Example:
    Example 1:
        Input: root = [1,2,3,4], x = 4, y = 3
        Output: false

    Example 2:
        Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
        Output: true

    Example 3:
        Input: root = [1,2,3,null,4], x = 2, y = 3
        Output: false



// Observations:
    - Given root of the binary tre.
    - given two nodes x and y
    - return true if the nodes corresponding  to the value x a-nd y in the tree are the cousins or false otherwise.
    - Two node of a binary tree are cousin if they have the same depth with different parent.
    - note that binary tree.

    // Approach:
        - we will have to compute the level of those two nodes
            - if they are not same -> return false
        - also we will have to store the informations of their parent.
            - if they are same -> return false

    // Complexity:
        - TC: O(V)
        - SC: O(V)

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
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL) return false;

        queue<pair<TreeNode*, int>> q;
        q.push({root, -1});

        pair<int, int> X = {-1, -1}, Y = {-1, -1};      // <lvl, parent>

        int lvl = 0;
        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                auto [root, parent] = q.front();
                q.pop();


                if(root->val == x) {
                    X.first = lvl;
                    X.second = parent;
                }

                if(root->val == y) {
                    Y.first = lvl;
                    Y.second = parent;
                }

                if(root->left != NULL) q.push({root->left, root->val});
                if(root->right != NULL) q.push({root->right, root->val});
            }

            lvl++;
        }

    
        // Check conditions:
        if(X.first != Y.first) return false;    // not same level.
        if(X.second == Y.second) return false;  // both parent are same.

        return true;
    }
};
