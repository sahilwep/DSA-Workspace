/*

//  1161. Maximum Level Sum of a Binary Tree


//  Problem Statement: 
    - Given the root of a binary tree, the level of its root is 1, the level of its children is 2, and so on.
    - Return the smallest level x such that the sum of all the values of nodes at level x is maximal.

 
// Example:

    Example 1:
        Input: root = [1,7,0,7,-8,null,null]
        Output: 2
        Explanation: 
        Level 1 sum = 1.
        Level 2 sum = 7 + 0 = 7.
        Level 3 sum = 7 + -8 = -1.
        So we return the level with the maximum sum which is level 2.

    Example 2:
        Input: root = [989,null,10250,98693,-89388,null,null,null,-32127]
        Output: 2


// Observations:
    - we are given root of the tree.
    - we need to find the level on which we can get the maximum sum.


    // BFS Approach:
        - To process level by level we can use BFS, which is level order traversal
        - At every level we compute the sum,
        - And if it's the maximum, we will store the level as max_sum-so-far.
        - and at the last we will return the level on which we get the maximum sum..
    

    // Complexity:
        - TC: O(n)
        - SC: O(w)
            - n = total nodes of tree.
            - w = width of the tree, in worse case, the largest wight of the tree level, on which we have maximum nodes..


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
    int maxLevelSum(TreeNode* root) {

        // BFS:
        queue<TreeNode*> q;
        q.push(root);

        int maxSumSoFar = INT_MIN;
        int maxLvlSoFar = 1;    //  set it as inital Root-level
        int level = 1;          // starting level

        while(!q.empty()) {
            bool isNextLvlFound = false;    // just to maintain a next-level-check
            int size = q.size();
            int currLvlSum = 0; // current level sum

            while(size--) {
                TreeNode* node = q.front(); // get the node
                q.pop();    // remove that from queue

                currLvlSum += node->val;    // store their sum value.


                // Explore child nodes found in next level & store in queue, so that we can process them in next level:
                if(node->left != nullptr) {
                    isNextLvlFound = true;
                    q.push(node->left);
                }

                if(node->right != nullptr) {
                    isNextLvlFound = true;
                    q.push(node->right);
                }
            }

            // compare the maxi sum:
            if(currLvlSum > maxSumSoFar) {
                maxSumSoFar = currLvlSum;
                maxLvlSoFar = level;
            }

            if(isNextLvlFound) {    // check for next-level increment:
                level++;
            }
        }

        return maxLvlSoFar; // return the level on which we get maximums sum.
    }
};

