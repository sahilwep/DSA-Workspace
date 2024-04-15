/*
// Height of binary tree: 
    * Maximum number of node from root to leaf path.

    I/p : 
                                            [10]
                                              |
                                      [8]-----------[30]
                                                       |
                                                [40]---------[50]
                                                              |
                                                        [70]---
    O/p : 4


    I/p :               
                                            [10]
    O/p : 1


    I/p : NULL
    O/p : 0


    I/p :       
                                            [30]
                                              |
                                      [40]----------[60]
                                        |
                                [70]-----
                                  |
                         [80]------         
    O/p : 4


    I/p :       
                                            [10]
                                              |
                                              -----[20]
                                                     |
                                                     -----[20]

    O/p : 3

// Solution: 

    * We will recursively got to right subtree & then left subtree, & we wil compute height..

                        [10]
                          |
                  [8]-----------[30]
                                   |
                            [40]---------[50]

    * We can use max function to get the height of recursive tree..
    // Recursive tree:
                height(10) : gets max(1, 2) + 1 -> 3, & return to the parent call.
                    |--->height(8) : gets 0, & add 1 to it & then return to parent call.
                    |       |--->height(NULL) : return 0
                    |       |--->height(NULL) : return 0
                    |
                    |--->height(30) : gets max(1, 1) + 1 -> have 2, & return 2 to the parent call
                            |--->height(40) : gets 0, & add 1 to it & then return to parent call.
                            |       |--->height(NULL)
                            |       |--->height(NULL)
                            |
                            |--->height(50) : gets 0, & add 1 to it & then return to parent call.
                                   |--->height(NULL)
                                   |--->height(NULL)

        * It will return 3, as height..

    * TC : O(n), for n nodes
        * for every node it's take O(1) constant work, as we are doing comparision & addition..
    * AS : O(h+1) : because (h+1) calls in stack : O(h)
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

// Height of binary Tree: 
int height(Node *root){
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

// preOrder:
void preOrder(Node *root){
    if(root!=NULL){
        cout << (root->key) << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    
    preOrder(root);
    cout << endl;
    cout << height(root) << endl; // height of binary tree

    return 0;
}