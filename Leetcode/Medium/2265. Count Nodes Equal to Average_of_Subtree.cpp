/*

//  2265. Count Nodes Equal to Average of Subtree


//  Problem Statement: 
    - Given the root of a binary tree, return the number of nodes where the value of the node is equal to the average of the values in its subtree.
    - Note:
        - The average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.
        - A subtree of root is a tree consisting of root and all of its descendants.



//  Example:
    Example 1:
        Input: root = [4,8,5,0,1,null,6]
        Output: 5
        Explanation: 
        For the node with value 4: The average of its subtree is (4 + 8 + 5 + 0 + 1 + 6) / 6 = 24 / 6 = 4.
        For the node with value 5: The average of its subtree is (5 + 6) / 2 = 11 / 2 = 5.
        For the node with value 0: The average of its subtree is 0 / 1 = 0.
        For the node with value 1: The average of its subtree is 1 / 1 = 1.
        For the node with value 6: The average of its subtree is 6 / 1 = 6.

    Example 2:
        Input: root = [1]
        Output: 1
        Explanation: For the node with value 1: The average of its subtree is 1 / 1 = 1.



// Observations:
    - Given root of tree:
        - We will have to get the avarage of all the subtree, and any node that is equal to their avarage of their subtree: that belongs to our answer, return count of total that node.


    // Approach:
        - from root: we will compute every subtree sum:
            - store it somewhere.
        - if their sum of subtree and avarage by it: is equal that number that's our answer..
        - First we will have to count how many child are there for every subtree, and store it.
        - also we will have to get the sum of the value of every subtree, and store it.
        - then from both the informations, we calculate the node that follows the answer.
            
    // Complexity:
        - TC: O(n)
        - SC: O(n)


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
    // Function to get all the nodes in order:
    void getTotal(TreeNode* root, vector<int> &totalNodes) {
        if(root == NULL) return;
        
        getTotal(root->left, totalNodes);
        getTotal(root->right, totalNodes);
        totalNodes.push_back(root->val);
    }
    // Function to get the child count of every subtree:
    int childCnt(TreeNode *root, vector<int> &child) {
        if(root == NULL) return 0;

        int cnt = 1;
        cnt += childCnt(root->left, child);
        cnt += childCnt(root->right, child);
        child.push_back(cnt);

        return cnt;
    }
    // Function to find the child sum:
    int childSum(TreeNode *root, vector<int> &sum) {
        if(root == NULL) return 0;

        int cSum = root->val;
        cSum += childSum(root->left, sum);
        cSum += childSum(root->right, sum);

        sum.push_back(cSum);

        return cSum;
    }
public:
    int averageOfSubtree(TreeNode* root) {
        
        if(root->left == NULL && root->right == NULL) {
            if(root->val == root->val/1) return 1;  // single node found
            return 0;   // nothing found.
        }

        // Find all the nodes in order: POST ORDER DFS
        TreeNode *t1 = root;
        vector<int> totalNodes;
        getTotal(t1, totalNodes);


        // calculate the child count of every subtree:
        TreeNode *t2 = root;
        vector<int> child;
        int x = childCnt(t2, child);


        // Calculate the sun of every subtree:
        TreeNode *t3 = root;
        vector<int> sum;
        x = childSum(t3, sum);


        // Calculate answer:
        int ans = 0;
        int total = totalNodes.size();
        for(int i = 0; i < total; i++) {
            if(sum[i] / child[i] == totalNodes[i]) ans++;
        }


        return ans;
    }
};