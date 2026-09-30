/*

//  513. Find Bottom Left Tree Value


//  Problem Statement: 
    - You are given the root of a binary tree.
    - Return the leftmost value in the last row of the tree.

// Example:
    Example 1:
        Input: root = [2,1,3]
        Output: 1
        Explanation: The last row is [1,3], so the leftmost value is 1.

    Example 2:
        Input: root = [1,2,3,4,null,5,6,null,null,7]
        Output: 7
        Explanation: The last row contains only the node 7.


// Observations:
    - from the last level, we will have to fetch the first node value.
    - process BFS and for every new level fetch the first value which is found.
    - at the end of exploration, return the value..    


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
    int findBottomLeftValue(TreeNode* root) {
        if(root == NULL) return -1; // invalid case..

        queue<TreeNode*> q;
        int ans = -1;
        q.push(root);

        while(!q.empty()) {
            bool flag = false;
            int size = q.size();

            while(size--) {
                TreeNode* root = q.front();
                q.pop();

                if(!flag) {
                    flag = true;
                    ans = root->val;
                }
                
                if(root->left != NULL) q.push(root->left);
                if(root->right != NULL) q.push(root->right);
            }
        }
        
        return ans;
    }
};