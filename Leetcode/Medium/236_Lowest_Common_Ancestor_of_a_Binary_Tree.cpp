/*

//  236. Lowest Common Ancestor of a Binary Tree


//  Problem Statement: 
    - Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
    - According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

 
// Example:
    Example 1:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
        Output: 3
        Explanation: The LCA of nodes 5 and 1 is 3.

    Example 2:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
        Output: 5
        Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

    Example 3:
        Input: root = [1,2], p = 1, q = 2
        Output: 1


// Observations:
    - This problem breaks into LCA Pattern: Lowest common Ancestors:
        - IN LCA:
            - we used to find the node that has common ancestors of p & q
            - We explore left & right of the tree & get the LCA by simply matching the common ancestors using p & q given nodes.
            - Logic like:

                    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
                        if(root == nullptr) return nullptr;
                        if(root == p || root == q) return root;
                            
                        TreeNode* left = lca(root->left, p, q);
                        TreeNode* right = lca(root->right, p, q);

                        if(left != nullptr && right != nullptr) return root;
                        if(left != nullptr) return left;
                        return right;
                    }

                Example: 
                    Let say p = 2, q = 1

                              3
                            /   \
                           5     1
                          /  \   / \
                         6    2 0   10
                        / \  / \
                       8  9 7   4  

                    This will give us node '3' as LCA means lowest common ancestors for (2, 1) as 3

                    lca(3) <- return 3, because left & right both are not null..
                        |
                        |---lca(5)  <- return 2
                        |       |
                        |       |---lca(6)  <- return null
                        |       |       |
                        |       |       |---lca(8)  <- return null
                        |       |       |       |
                        |       |       |       |---left <- null
                        |       |       |       |---right <- null
                        |       |       |
                        |       |       |---lca(9)
                        |       |           |---left <- null
                        |       |           |---right <- null
                        |       |
                        |       |---lca(2)  <- matched with 2 & return 2
                        |
                        |---lca(1)  <- matched with 1 return 1


        
                Another example:
                    Let say p = 5, q = 4

                              3
                            /   \
                           5     1
                          /  \   / \
                         6    2 0   10
                        / \  / \
                       8  9 7   4  

                    This will give us node '5' as lca means lowest common ancestors for (5, 4) as 5

                    lca(3) <- return 5
                        |
                        |---lca(5)  matched with '5' return '5' as lca, no further calls.
                        |
                        |---lca(1) <- return null
                            |
                            |---lca(0)
                            |       |
                            |       |---(Left) <- return null
                            |       |---(right) <- return null
                            |
                            |---lca(10)
                                    |
                                    |---(Left) <- return null
                                    |---(right) <- return null

        // Approach:
            - Simple DFS To perform explore all the nodes:
                - Check if current node is not Null:
                    - Check if current (node == p || node == q)  directly return that node, as LCA
                    - Explore left-Subtree
                    - Explore right-Subtree
                    - If both left & right subtree is != null: return node as our LCA
                    - If left is not null: return left.
                    - If right is not null: return right.


                        TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
                            if(root == nullptr) return nullptr;         // if current node is null return that as null
                            if(root == p || root == q) return root;     // if any p || q matches return current node as LCA

                            // Explore left & right subtree:
                            TreeNode* left = lca(root->left, p, q);
                            TreeNode* right = lca(root->right, p, q);

                            if(left != nullptr && right != nullptr) return root;    // If our both left & right calls return something & != null: this current node is our LCA.
                            if(left != nullptr) return left;    // If left has returned something: return that left
                            return right;                       // or return right if it's return something.
                        }
                                        

        // Complexity:
            - TC: O(n)  <- total nodes in binary tree.
            - SC: O(d)  <- depth/height of binary tree.
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
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
private:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == nullptr) return nullptr;
        if(root == p || root == q) return root;
            
        TreeNode* left = lca(root->left, p, q);
        TreeNode* right = lca(root->right, p, q);

        if(left != nullptr && right != nullptr) return root;
        if(left != nullptr) return left;
        return right;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        return lca(root, p, q);
    }
};