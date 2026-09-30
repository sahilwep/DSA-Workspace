/*

//  530. Minimum Absolute Difference in BST


//  Problem Statement: 
    - Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.



// Observations:
    - From all the nodes, we will have to pick the minimum absolute value..
    - store all the nodes values.
    - sort them
    - after sorting find the min Abs diff by getting the difference b/w two consecutive values.

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
    int getMinimumDifference(TreeNode* root) {

        if(root == NULL) return -1; // nothing is there.

        // Using BFS store all the nodes:
        vector<int> nums;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            auto root = q.front();
            q.pop();

            nums.push_back(root->val);

            if(root->left != NULL) q.push(root->left);
            if(root->right != NULL) q.push(root->right);
        }
        
        // Sort the nums to get everything in order:
        sort(begin(nums), end(nums));

        // find the min-Diff:
        int ans = INT_MAX;
        for(int i = 0; i < nums.size() - 1; i++) {
            ans = min(nums[i + 1] - nums[i], ans);
        }

        return ans;
    }
};