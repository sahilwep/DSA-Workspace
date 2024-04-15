/*
// Implementation of Preorder Traversal:

    * Preorder: (root, left,  right)

    // Example:
                                        [10]
                                         |
                                 [20]-----------[30]
                                                 |
                                           [40]---------[50]
            // Preorder: 10, 20, 30, 40, 50
        
        // Recursive tree of Preorder:
                    
                    Preorder(10)
                        |--->print(10)
                        |--->Preorder(20)
                        |       |--->print(20)
                        |       |--->Preorder(NULL)
                        |       |--->Preorder(NULL)
                        |
                        |--->Preorder(30)
                                |--->print(30)
                                |--->Preorder(40)
                                |       |--->print(40)
                                |       |--->Preorder(NULL)
                                |       |--->Preorder(NULL)
                                |
                                |--->Preorder(50)
                                        |--->print(50)
                                        |--->Preorder(NULL)
                                        |--->Preorder(NULL)

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

// Preorder Traversal:
void Preorder(Node *root){
    if(root!= NULL){
        cout << root->key << " ";
        Preorder(root->left);
        Preorder(root->right);
    }
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    
    Preorder(root);
    
    return 0;
}