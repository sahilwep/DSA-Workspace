/*

//  1382. Balance a Binary Search Tree


//  Problem Statement: 
    - Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.
    - A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 
// Example:
    Example 1:
        Input: root = [1,null,2,null,3,null,4,null,null]
        Output: [2,1,3,null,null,null,4]
        Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.

            [1]                             [2]                                     [3]
              \                           /    \                                   /   \
               [2]          =>          [1]     [3]                 OR           [1]    [4]
                 \                                 \                               \
                 [3]                                [4]                             [2]
                   \
                    [4]


    Example 2:
        Input: root = [2,1,3]
        Output: [2,1,3]

                    [2]
                    / \
                 [1]   [3]

// Observations:
    - Given Binary Search Tree:
        - Binary search Tree, means for a given node:

                    [Node]
                    /   \
                [left]   [right]

            left side smaller than node
            right side greater than node

    - We need to make sure that it's height balanced.
    
    // Approach:
        - To height balance a Given Binary Search Tree:
            - we need to make sure the depth difference should not be more than '1'
        
        Observations 1: For any Given Binary tree:
            - if we do In-Order:
                - we will have shorted list of nodes...
                - Example:
                    In-Order: Left - root - right

                                [4]
                               /   \
                            [2]     [6]
                           /  \     /  \
                         [1]  [3] [5]   [7]

                         1 2 3 4 5 6 7 8

        Observations 2: let say we have given shorted nodes 1, 2, 3, 4, 5, 6, 7
            - if we have to arrange into a binary tree in a fashion so that it should be height balanced.
                - It's better we should take root node as middle & start distributing left & right from there.

                        1, 2, 3, 4, 5, 6, 7
                        |        |        |
                    start       mid      end

                    mid = start + (end - start) / 2;

                    left = start to mid - 1
                    right = mid + 1 to end

            - Now we can make binary search tree using this logic.
            - We just have to recursively arrange the range of given list.
            - When we finished, our tree looks something like this.

                                [4]
                               /   \
                            [2]     [6]
                           /  \     /  \
                         [1]  [3] [5]   [7]

            - Our Final Binary search tree is always have height balanced.

        - First we will have to get the shorted list of given Binary tree
        - Secondly, we will have to re-arrange the binary Search tree in a way so that it will be height balanced.


        // Complexity:
            - TC: O(n)
            - SC: O(n)
                - n = total nodes


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
    vector<int> vec;    // store the list of nodes from binary search tree in shorted order.
    void inOrder(TreeNode *root) {  // In-Order to collect the nodes in shorted fashion.
        if(root == NULL) return;

        inOrder(root->left);
        vec.push_back(root->val);
        inOrder(root->right);
    }
    TreeNode* construct(int l, int r) { // Function to Construct Binary Search tree height balanced.
        // if left pointer is grater than right pointer range is finished.
        if(l > r) return NULL;  

        int mid = l + (r - l) / 2;  // get the middle point

        TreeNode* root = new TreeNode(vec[mid]);    // assign the value to the current node
        root->left = construct(l, mid - 1);         // left sub-branch construction range: l to mid - 1
        root->right = construct(mid + 1, r);        // right sub-branch construction range: mid + 1 to r

        return root;        // last return the root node.
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        
        // In-order will gives us binary tree in shorted fashion:
        inOrder(root);

        // Now, construct binary tree:
        int l = 0;
        int r = vec.size() - 1;
        return construct(l, r);
    }
};