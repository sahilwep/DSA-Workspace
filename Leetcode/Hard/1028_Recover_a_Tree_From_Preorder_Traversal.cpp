/*

//  1028. Recover a Tree From Preorder Traversal


//  Problem Statement: 
    -> We run a preorder depth-first search (DFS) on the root of a binary tree.
    -> At each node in this traversal, we output D dashes (where D is the depth of this node), then we output the value of this node.  If the depth of a node is D, the depth of its immediate child is D + 1.  The depth of the root node is 0.
    -> If a node has only one child, that child is guaranteed to be the left child.
    -> Given the output traversal of this traversal, recover the tree and return its root.

 
// Example:
    Example 1:
        Input: traversal = "1-2--3--4-5--6--7"
        Output: [1,2,5,3,4,6,7]

    Example 2:
        Input: traversal = "1-2--3---4-5--6---7"
        Output: [1,2,5,3,null,6,null,4,null,7]

    Example 3:
        Input: traversal = "1-401--349---90--88"
        Output: [1,401,null,349,88,90]


// Complexity:
    -> TC: O(n)
    -> SC: O(n)

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
private: 
    int n;
    TreeNode *solve(string &s, int &i, int depth) {
        if(i >= n) {
            return NULL;
        }

        int j = i;
        while(j < n && s[j] == '-') {
            j++;
        }
        
        int dash = j - i;
        if(dash != depth) {
            return NULL;
        }

        i += dash;

        int num = 0;
        while(i < n && isdigit(s[i])) {
            num = (num * 10) + (s[i] - '0');
            i++;
        }
        TreeNode *root = new TreeNode(num);
        root->left = solve(s, i, depth + 1);
        root->right = solve(s, i, depth + 1);

        return root;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        n = traversal.size();

        int i = 0;
        int depth = 0;

        return solve(traversal, i, depth);
    }
};