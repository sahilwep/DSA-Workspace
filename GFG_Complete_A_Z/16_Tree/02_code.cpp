/*
// Binary Tree: 
    * Every node has at most two children..
    * So, the degree of a node is at-most 2, means node degree can be 0, 1, or 2.

        // Same as below: 
                                   [30]
                                    |
                        [40]-----------------[50]
                         |                     |
                [70]------              [60]------[80]


        // Implementation representation: 
                                              [ |30| ] 
                                                  |
                        [ |40|Null] ------------------------------[ |50| ] 
                            |                                         |
          [Null|70|Null]-----                   [Null|60|Null] --------------[Null|80|Null]


        // Node:
                             [left reference |30| right reference]
                                              key


// Note : Difference b/w binary tree & binary Search tree:
    * Binary Tree: Elements are in any random order.
    * Binary Search Tree: Elements are in sorted order.

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Node{
    int key;
    Node *left, *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

int main(void){
    // implementation of above binary tree...
    Node *root = new Node(30);
    root->left = new Node(40);
    root->left->left = new Node(70);
    root->right = new Node(50);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    
    
    return 0;
}