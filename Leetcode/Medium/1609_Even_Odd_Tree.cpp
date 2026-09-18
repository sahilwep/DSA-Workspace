/*

//  1609. Even Odd Tree

//  Problem Statement: 
    - A binary tree is named Even-Odd if it meets the following conditions:
        - The root of the binary tree is at level index 0, its children are at level index 1, their children are at level index 2, etc.
        - For every even-indexed level, all nodes at the level have odd integer values in strictly increasing order (from left to right).
        - For every odd-indexed level, all nodes at the level have even integer values in strictly decreasing order (from left to right).
    - Given the root of a binary tree, return true if the binary tree is Even-Odd, otherwise return false.

 
// Example:
    Example 1:
        Input: root = [1,10,4,3,null,7,9,12,8,6,null,null,2]
        Output: true
        Explanation: The node values on each level are:
        Level 0: [1]
        Level 1: [10,4]
        Level 2: [3,7,9]
        Level 3: [12,8,6,2]
        Since levels 0 and 2 are all odd and increasing and levels 1 and 3 are all even and decreasing, the tree is Even-Odd.

    Example 2:
        Input: root = [5,4,2,3,3,7]
        Output: false
        Explanation: The node values on each level are:
        Level 0: [5]
        Level 1: [4,2]
        Level 2: [3,3,7]
        Node values in level 2 must be in strictly increasing order, so the tree is not Even-Odd.

    Example 3:
        Input: root = [5,9,1,3,5,7]
        Output: false
        Explanation: Node values in the level 1 should be even integers.

 

// Observations:
    - given binary tree, even odd if it's meet conditions:
        - root of binary tree is at level 0, and level index  = 1
        - for every index level: all node have odd integer strictly increasing. (from left to right)
        - for odd index level: all node have even integer strictly decreasing (left to right)
        - given root of binary tre, return true if it's even-odd, else return false.

        // Approach:
            - we will collect all the node from every level,
            - and check the given conditions that is met or not?
            - If any given conditions is flagged as false, return false, else return true.

            - starting with level = 0;
            - if level = odd: 
                - First check: check values are even or not?
                - second check: check wether it's lesser than the previous or not?
            - if level = even:
                - first check: check for the odd values.
                - second check: check wether it's grater than the previous one not?

        // Complexity:
            - TC: O(n)  -> n = total number of nodes.
            - SC: O(1)

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
    bool isEvenOddTree(TreeNode* root) {

        queue<TreeNode*> q;
        int level = 0;

        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            int prev = -1;

            // process every level in one instance:
            while(size--) {
                TreeNode* node = q.front();
                int nodeVal = node->val;
                q.pop();

                // if level is odd and node is odd || level is even and node is even => return false
                if(level % 2 == 0 && nodeVal % 2 == 0 || level % 2 != 0 && nodeVal % 2 != 0) return false;

                if(prev != -1) {
                    if(level % 2 == 0) {    // for even level: Increasing
                        if(prev >= nodeVal) return false;   // violating.
                    } else {    // for odd level: decreasing:
                        if(prev <= nodeVal) return false;   // violating.
                    }    
                }

                // Explore left & right:
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);

                prev = nodeVal; // store prevNode as current node for comparing the next node
            }

            level++;
        }
        

        return true;      
    }
};