/*

//  865. Smallest Subtree with all the Deepest Nodes


//  Problem Statement: 
    - Given the root of a binary tree, the depth of each node is the shortest distance to the root.
    - Return the smallest subtree such that it contains all the deepest nodes in the original tree.
    - A node is called the deepest if it has the largest depth possible among any node in the entire tree.
    - The subtree of a node is a tree consisting of that node, plus the set of all descendants of that node.

 
// Example:
    Example 1:
        Input: root = [3,5,1,6,2,0,8,null,null,7,4]
        Output: [2,7,4]
        Explanation: We return the node with value 2, colored in yellow in the diagram.
        The nodes coloured in blue are the deepest nodes of the tree.
        Notice that nodes 5, 3 and 2 contain the deepest nodes in the tree but node 2 is the smallest subtree among them, so we return it.

    Example 2:
        Input: root = [1]
        Output: [1]
        Explanation: The root is the deepest node in the tree.

    Example 3:
        Input: root = [0,1,3,null,2]
        Output: [2]
        Explanation: The deepest node in the tree is 2, the valid subtrees are the subtrees of nodes 2, 1 and 0 but the subtree of node 2 is the smallest.

        

// Observations:
    - We are given root node of binary tree,
    - The depth of each node is the shortest distance from node OR in simple word say levels of each node from root.
    - we need to return the smallest subtree that is deepest.
    - Node is called deepest if it has largest depth possible among any node in entire tree.
    - Let's visualized this with some example:

                - Example 1:
                              3
                            /   \
                           5     1
                          / \    / \
                         6   2  0  8
                            / \
                           7   4

                    ans = [2, 7, 4]
                        representing root as 2

                              2 
                             / \
                            7   4


                - Example 2:

                              3
                            /   \
                           5     1
                          / \    / \
                         6   2  0  8
                            /
                           7

                            ans = [7]
                                representing root as 7

                - Example 3:

                              3
                            /   \
                           5     1
                          / \    / \
                         6   2  0   8
                            / \    /
                           7   4  9

                            ans = [3, 5, 1, 6, 2, 0, 8, null, null, 7, 4, null null, 9]
                            whole tree representing root as 3

                - Example 4:

                              3
                            /   \
                           5     1
                          /  \   / \
                         6    2 0   10
                        / \  / \
                       8  9 7   4  

                            ans = [5, 6, 2, 8, 9, 7, 4]
                            whole tree representing root as 5

    
    - This problem breaks into LCA Pattern: Lowest common Ancestors:
        - IN LCA:
            - Leetcode: 236 Problems.
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
                             
        - Coming back to question:
            - here we have to return the LCA lowest common Ancestors of deeps level.
            - Something like:


                              3             -> level 0
                            /   \           
                           5     1          -> level 1
                          / \    / \
                         6   2  0   10      -> level 2
                            / \
                           7   4            -> level 3


                At level '3' which is the deepest level, these are the valid candidate like p, q in lca

            - First we need to find level of each nodes:
                - We can use something like BFS/DFS to find that
                - We needed that level to compare the deepest level so we will store it somewhere that gives us lookup in O(1) time.
                    - Map will help us in that, we can use map to store every node found in level 'l'
                    - Also we need maxDepth, so we will maintain something maxD & while doing dfs, we can store the maxDepth by getting max-explore-so-far by simply mainatting the global maxD
                    - Something like this.
                        unordered_map<int, int> mp;
                        int maxD = 0;   // initially root as max-depth
                        void depth(TreeNode* root, int d) { // This dfs will let's know level of every node
                            if(root == NULL) return;
                            
                            mp[root->val] = d;
                            maxD = max(maxD, d);    // update maxD every time to get maximum depth..

                            depth(root->left, d + 1);
                            depth(root->right, d + 1);
                        }
            
                - Once we have this: 
                    - We can simply use LAC Format code that use (P, Q) as our maxD comparision..
                    - Something like:
                        TreeNode* lca(TreeNode* root) {
                            if(root == NULL) return NULL;   // empty tree
                            
                            // Check with max-Depth: if found return that as our potential LCA
                            if(mp[root->val] == maxD) { // if nodes is on max-depth:
                                return root;    // return node itself.
                            }

                            TreeNode* left = lca(root->left);       // explore left
                            TreeNode* right = lca(root->right);     // explore right

                            if(left != NULL && right != NULL) {     // From both side, if we get not-null values, means the current node is the root of LCA subtree..
                                return root;    // return node as lca value.
                            }

                            if(left != NULL) return left;   // If something found in left -> return that.
                            return right;   // else if something found in right -> return that.
                        }

        // Complexity:
            - TC: O(n)      -> We are exploring every node at once.
            - SC: O(maxD)   -> maximum Depth/Height of binary tree.


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
    unordered_map<int, int> mp;
    int maxD = 0;
    void depth(TreeNode* root, int d) { // calculate the level of every node
        if(root == NULL) return;
        
        mp[root->val] = d;
        maxD = max(maxD, d);

        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }
    TreeNode* lca(TreeNode* root) {
        if(root == NULL) return NULL;   // empty tree
        
        if(mp[root->val] == maxD) { // if nodes is on max-depth:
            return root;    // return node itself.
        }

        TreeNode* left = lca(root->left);
        TreeNode* right = lca(root->right);

        if(left != NULL && right != NULL) {
            return root;    // return node as lca value.
        }

        if(left != NULL) return left;
        return right;
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        depth(root, 0);    // calculate the depth of every node

        return lca(root);   // return the lca node
    }
};