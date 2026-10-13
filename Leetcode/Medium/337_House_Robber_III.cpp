/*

//  337. House Robber III


//  Problem Statement: 
    - The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.
    - Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.
    - Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


// Example:

    Example 1:
        Input: root = [3,2,3,null,3,null,1]
        Output: 7
        Explanation: Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.

    Example 2:
        Input: root = [3,4,5,1,3,null,1]
        Output: 9
        Explanation: Maximum amount of money the thief can rob = 4 + 5 = 9.


// Observations:
    - Given root of binary tree
    - we need to find the amount we can collect.
    - Considering that, we can't theft the two same adjacent nodes
    - we need to return the max_amount we can collect..

    // Approach:
        - One thing we can observe is that we can collect the odd & even level nodes cost
        - and we can return the max_among them
        - as we don't have to loot adjacent houses..
        - BFS will help us in that..
            - Wait, bfs make sure that we will only collect the level-wise and exactly skip 1 nodes as every level.
            - but conditions may be possible that we would need to skip two consecutive node, because next to that give us maximum..
            - So, we can't rely on BFS
        - We can simply write the DFS:
            - Considering choices:
                -> GOes to recursive solution:
                    - For any node, we have options:
                        -> reject + 1, we can explore next node.
                        -> include + 2, we will have to skip next node

            -> We will start form the root & explore until our root is not != NULL

            // base condition:
                - if(root == NULL) return 0;    // nothing to explore

            // Decision Tree:
                - Two choices:
                
                    reject: move next
                        rej += solve(root->left)
                        rej += solve(root->right)

                    accept: move next->next
                        acc += root->val + solve(root->left->left)
                        acc += root->val + solve(root->left->right)
                        acc += root->val + solve(root->right->left)
                        acc += root->val + solve(root->right->right)

                considering the choices, accept/reject: return the collection
                        return max(rej, acc)

                // Complexity:
                    - TC: O(2^n)
                    - SC: O(2^n)

            -> Solution falls into TLE, as exploring the overlapping subproblem, and constrains is also 1e4


            -> We can memoize this:
                -> Variable values:
                    root

                -> range: we are not sure about how many we wil have to loop upon:
                    -> we can simply use map in this case..

                unordered_map<TreeNode*, int> dp

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


// Memoization Solution:
class Solution {
private:
    unordered_map<TreeNode*, int> t;
    int solve(TreeNode* root) {
        // Base conditions: nothing to explore..
        if(root == NULL) return 0; 

        // check in dp table:
        if(t.count(root)) {
            return t[root];
        }

        // Decision Tree: two choices-> reject OR accept
        int rej = solve(root->left) + solve(root->right);
        
        int acc = root->val;
        if(root->left != NULL) acc += solve(root->left->left) + solve(root->left->right);
        if(root->right != NULL) acc += solve(root->right->left) + solve(root->right->right);

        return t[root] = max(acc, rej);
    }
public:
    int rob(TreeNode* root) {
        
        return solve(root);
    }
};


// Recursive Solution:
class Solution_ {
private:
    int solve(TreeNode* root) {
        // Base condition:
        if(root == NULL) return 0;

        // Decision Tree: Two choice reject OR accept
        int rej = 0;
        if(root->left != NULL) rej += solve(root->left);
        if(root->right != NULL) rej += solve(root->right);

        int acc = root->val;
        if(root->left != NULL && root->left->left != NULL) acc += solve(root->left->left);
        if(root->left != NULL && root->left->right != NULL) acc += solve(root->left->right);
        
        if(root->right != NULL && root->right->left != NULL) acc += solve(root->right->left);
        if(root->right != NULL && root->right->right != NULL) acc += solve(root->right->right);


        return max(rej, acc);
    }
public:
    int rob(TreeNode* root) {
        
        return solve(root);
    }
};