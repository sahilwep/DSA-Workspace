/*
// Implementation of Inorder Traversal:

    * Inorder: (Left, root, right)

    // Example:         
                                        [10]
                                         |
                                 [20]-----------[30]
                                                 |
                                           [40]---------[50]
            // Inorder: 20, 10, 40, 30, 50
        
        // Recursive tree of inorder:
                    
                    inorder(10)
                        |--->inorder(20)
                        |       |--->inorder(NULL)
                        |       |--->print(20)
                        |       |--->inorder(NULL)
                        |
                        |--->print(10)
                        |--->inorder(30)
                                |--->inorder(40)
                                |       |--->inorder(NULL)
                                |       |--->print(40)
                                |       |--->inorder(NULL)
                                |
                                |--->print(30)
                                |--->inorder(50)
                                        |--->inorder(NULL)
                                        |--->print(50)
                                        |--->inorder(NULL)

// TC: O(n)
// AS: O(h+1) -> O(h)
    * h=hight of tree

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

// InOrder Traversal:
void inOrder(Node *root){
    if(root!= NULL){
        inOrder(root->left);
        cout << root->key << " ";
        inOrder(root->right);
    }
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    
    inOrder(root);
    
    return 0;
}