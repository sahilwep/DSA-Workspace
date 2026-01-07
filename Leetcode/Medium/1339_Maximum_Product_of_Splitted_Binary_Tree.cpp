/*

//  1339. Maximum Product of Splitted Binary Tree


//  Problem Statement: 
    - Given the root of a binary tree, split the binary tree into two subtrees by removing one edge such that the product of the sums of the subtrees is maximized.
    - Return the maximum product of the sums of the two subtrees. Since the answer may be too large, return it modulo 109 + 7.
    - Note that you need to maximize the answer before taking the mod and not after taking it.


//  Example:

    Example 1:
        Input: root = [1,2,3,4,5,6]
        Output: 110
        Explanation: Remove the red edge and get 2 binary trees with sum 11 and 10. Their product is 110 (11*10)

    Example 2:
        Input: root = [1,null,2,3,4,null,null,5,6]
        Output: 90
        Explanation: Remove the red edge and get 2 binary trees with sum 15 and 6.Their product is 90 (15*6)

// Observations:
    - We are given root of the tree, & we need to find the maximum product by dividing tree in two part & getting their product from their subpart sums..
    - we need to cut tree in every possible place: 
        - and we have to find the maximum sum from both the subtrees.
    - We can easily calculate the sum of whole tree.
        - once we have to total sum, 
        - we can cut a particular part & calculate their sum, let s1 sum
        - the other part of sum s2, we can calculate from totalSum - s1 = s2.
    - So First we need to calculate the total sum of tree.
    - Once we have the total sum, we can start dividing the tree on every possible edges & try to find the maxProduct by:
        - Sum we can calculate at first.
        - S1 = we can calculate during the creating the subtree of a segment, we have explored so far.
        - S2 = we can calculate by totalSum - s1
        - At last we can do: maxProduct = max(maxProduct, s1 * s2)
    
    // Approach:    
        - The key idea is to split the binary tree into two subtrees by removing exactly one edge, such that the product of the sums of the two resulting subtrees is maximized.
    
        Step 1: Compute the Total Sum of the Tree
            First, we calculate the total sum of all nodes in the tree.
            This can be done using a simple DFS traversal, where:
            For each node, we compute
            node->val + sum(left subtree) + sum(right subtree)
            Let this total sum be stored in a variable called SUM.
            This step is important because, once we know the sum of the entire tree, we can easily compute the sum of the remaining part of the tree after cutting any subtree.

        Step 2: Explore All Possible Subtrees and Compute the Maximum Product
            After computing SUM, we perform another DFS using a function find(root):
            This function calculates the sum of each subtree.
            Let the sum of the current subtree be s1.
            If we cut the edge above this subtree, the remaining tree will have sum
            s2 = SUM - s1.
            For every subtree, we compute the product:
            product = s1 * s2
            We continuously update a global variable maxP to store the maximum product encountered so far.

        Why This Works (Intuition):
            Each possible way of splitting the tree corresponds to cutting one edge.
            Cutting an edge essentially separates the tree into:
            One subtree with sum s1
            The remaining part with sum SUM - s1
            By traversing all nodes and treating each node as the root of a potential subtree, we are effectively considering all possible splits.

        Example for Better Understanding:
                Consider this tree:

                     1
                    / \
                   2   3

                Total sum = 1 + 2 + 3 = 6

                Possible splits:
                    Cut edge above node 2:
                        s1 = 2, s2 = 6 - 2 = 4
                        Product = 2 × 4 = 8

                    Cut edge above node 3:
                        s1 = 3, s2 = 6 - 3 = 3
                        Product = 3 × 3 = 9  (maximum)

                    So the final answer is 9.

    // Complexity:
        - TC: O(n), We traverse each node at most twice (once for total sum, once for product calculation).
        - SC: O(n), Due to recursive DFS calls, the call stack can grow up to the height of the tree (worst case: skewed tree).

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


// Modularized Code: Single fuction will find sum & maxP, it's just first call for SUM, & then for maxP.

class Solution {
private:
    int mod = 1e9 + 7;
    long SUM = 0;
    long maxP = 0;
    long solve(TreeNode* root) {
        if(root == nullptr) return 0;

        // Explore left & right:
        int left = solve(root->left);
        int right = solve(root->right);

        // Calculate S1, S2 & get maxProduct:
        long s1 = root->val + left + right;
        long s2 = SUM - s1;
        maxP = max(maxP, s1 * s2);

        return (root->val + left + right);
    }
public:
    int maxProduct(TreeNode* root) {
        
        SUM = solve(root);   // first call for getting total sum:
        long x = solve(root);    // next call for getting maxProduct, because now we have total sum.

        return (int)(maxP % mod);
    }
};



// Multiple Function code:
class Solution {
private:
    int mod = 1e9 + 7;
    long SUM = 0;
    long maxP = 0;
    long totalSum(TreeNode *root) { // calculate total tree sum:
        if(root == nullptr) return 0;

        int leftSubTreeSum = totalSum(root->left);
        int rightSubTreeSum = totalSum(root->right);

        return root->val + leftSubTreeSum + rightSubTreeSum;
    }
    int find(TreeNode* root) {  // find sbustree sum by exploring in subtree & find product by subtracting subTreesum from SUM:
        if(root == nullptr) return 0;

        int leftSubTreeSum = find(root->left);
        int rightSubTreeSum = find(root->right);
        long subTreeSum = root->val + leftSubTreeSum + rightSubTreeSum;  // s1

        long remainingSubTreeSum = SUM - subTreeSum;    // s2
        maxP = max(maxP, subTreeSum * remainingSubTreeSum);  // calculate maxProduct: s1 * s2

        return subTreeSum;
    }
public:
    int maxProduct(TreeNode* root) {
        if(root == nullptr) return 0;   // no valid max product we can get.

        SUM = totalSum(root);

        int x = find(root);
        
        return (int)(maxP % mod);
    }
};