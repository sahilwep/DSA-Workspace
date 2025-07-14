/*

//  1448. Count Good Nodes in Binary Tree


//  Problem Statement: 
    -> Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
    -> Return the number of good nodes in the binary tree.


    Example 1:
        Input: root = [3,1,4,3,null,1,5]
        Output: 4
        Explanation: Nodes in blue are good.
        Root Node (3) is always a good node.
        Node 4 -> (3,4) is the maximum value in the path starting from the root.
        Node 5 -> (3,4,5) is the maximum value in the path
        Node 3 -> (3,1,3) is the maximum value in the path.

    Example 2:
        Input: root = [3,3,null,4,2]
        Output: 3
        Explanation: Node 2 -> (3, 3, 2) is not good, because "3" is higher than it.

    Example 3:
        Input: root = [1]
        Output: 1
        Explanation: Root is considered as good.
            The number of nodes in the binary tree is in the range [1, 10^5].
            Each node's value is between [-10^4, 10^4].


// Observations:
    -> maintain current so-far 
    -> Explore left & right subtree
    -> check the valid conditions
    -> return result

    // Complexity: 
        -> TC: O(N)
        -> SC: O(N), recursive call stack


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
    int solve(TreeNode* root, int maxSoFar) {
        if(root == NULL) return 0;

        int good = (root->val >= maxSoFar) ? 1 : 0; // if current value is grater or equal to previous, add 1 : else addd 0

        maxSoFar = max(maxSoFar, root->val);    // store maximum so-far
        
        // Explore left & right subtree
        int left = solve(root->left, maxSoFar);
        int right = solve(root->right, maxSoFar);

        return good + left + right; // return total count.
    }
public:
    int goodNodes(TreeNode* root) {
        
        return solve(root, INT_MIN);
    }
};