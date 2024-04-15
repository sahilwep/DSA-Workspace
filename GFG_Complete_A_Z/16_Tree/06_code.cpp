/*
// Implementation of Postorder Traversal:

    * Postorder: (Left, right, root)

    // Example:         
                                        [10]
                                         |
                                 [20]-----------[30]
                                                 |
                                           [40]---------[50]

            // Postorder: 20, 40, 50, 30, 10
        
        // Recursive tree of Postorder:
                    
                    Postorder(10)
                        |--->Postorder(20)
                        |       |--->Postorder(NULL)
                        |       |--->Postorder(NULL)
                        |       |--->print(20)
                        |
                        |--->Postorder(30)
                        |       |--->Postorder(40)
                        |       |       |--->Postorder(NULL)
                        |       |       |--->Postorder(NULL)
                        |       |       |--->print(40)
                        |       |
                        |       |--->Postorder(50)
                        |       |       |--->Postorder(NULL)
                        |       |       |--->Postorder(NULL)
                        |       |       |--->print(50)
                        |       |       
                        |       |--->print(30)
                        |
                        |--->print(10)

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

// Post Order traversal:
void postOrder(Node *root){
    if(root != NULL){
        postOrder(root->left);
        postOrder(root->right);
        cout << (root->key) << " ";
    }
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    
    postOrder(root);
    
    return 0;
}