/*

//  1261. Find Elements in a Contaminated Binary Tree


//  Problem Statement: 
    -> Given a binary tree with the following rules:
        -> root.val == 0
        -> For any treeNode:
            -> If treeNode.val has a value x and treeNode.left != null, then treeNode.left.val == 2 * x + 1
            -> If treeNode.val has a value x and treeNode.right != null, then treeNode.right.val == 2 * x + 2

    -> Now the binary tree is contaminated, which means all treeNode.val have been changed to -1.
    -> Implement the FindElements class:
        -> FindElements(TreeNode* root) Initializes the object with a contaminated binary tree and recovers it.
        -> bool find(int target) Returns true if the target value exists in the recovered binary tree.

// Example: 

    Example 1:

        Input
            ["FindElements","find","find"]
            [[[-1,null,-1]],[1],[2]]
        Output: [null,false,true]
        Explanation
            FindElements findElements = new FindElements([-1,null,-1]); 
            findElements.find(1); // return False 
            findElements.find(2); // return True 

    Example 2:

        Input
            ["FindElements","find","find","find"]
            [[[-1,-1,-1,-1,-1]],[1],[3],[5]]
        Output: [null,true,true,false]
        Explanation
            FindElements findElements = new FindElements([-1,-1,-1,-1,-1]);
            findElements.find(1); // return True
            findElements.find(3); // return True
            findElements.find(5); // return False

    Example 3:

        Input
            ["FindElements","find","find","find","find"]
            [[[-1,null,-1,-1,null,-1]],[2],[3],[4],[5]]
        Output: [null,true,false,false,true]
        Explanation
            FindElements findElements = new FindElements([-1,null,-1,-1,null,-1]);
            findElements.find(2); // return True
            findElements.find(3); // return False
            findElements.find(4); // return False
            findElements.find(5); // return True


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class FindElements {
private:
    unordered_set<int> st;  //we will use set to find the target value in O(1)
    void dfs(TreeNode *root, int x) {   // DFS
        if(!root) return ;  // if root is null return

        root->val = x;  // assign the given value from the 'x'
        st.insert(x);   // push it into set, in order to find in O(1)

        dfs(root->left, 2 * x + 1);     // left call
        dfs(root->right, 2 * x + 2);    // right call
    }
public:
    FindElements(TreeNode* root) {  
        st.clear(); // first clear the set
        dfs(root, 0);   // call dfs to assign value..
    }
    
    bool find(int target) {
        return st.count(target);    // if it's found in set, return 1, else 0
    }
};
    