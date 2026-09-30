/*

//  429. N-ary Tree Level Order Traversal



//  Problem Statement: 
    - Given an n-ary tree, return the level order traversal of its nodes' values.
    - Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 
    
// Example:
    Example 1:
        Input: root = [1,null,3,2,4,null,5,6]
        Output: [[1],[3,2,4],[5,6]]

    Example 2:
        Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
        Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]


// Observations:
    - Given n ary tree, return the lvl order traversal of the nodes values.
    - we will have to return the list of BFS traversal answer.
    - we can use bfs to get all the nodes in level order..


// Complexity:
    - TC: O(V + E)
    - SC: O(V + E)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root == NULL) return {};

        // process BFS & store node in lvl order:
        vector<vector<int>> ans;
        queue<Node*> q;

        q.push(root);
        while(!q.empty()) {
            int size = q.size();
            vector<int> lvl;

            while(size--) {
                auto node = q.front();
                q.pop();

                lvl.push_back(node->val);

                for(auto &it: node->children) {
                    if(it != NULL) {
                        q.push(it);
                    }
                }
            }

            ans.push_back(lvl);
        }


        return ans;
    }
};