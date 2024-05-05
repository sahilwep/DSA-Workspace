/*
// Children Sum Property:
    * sum of children node should be parent node.


I/p:
                            [20]
                             |
                    [8]------------[12]
                     |                
              [3]-------[5]
O/p: Yes


I/p:
                            [10]
                             |
                    [8]------------[2]
                                    |
                              [2]----
O/p: Yes

I/p:
                    [10]
O/p: Yes

I/p:
                Null 
O/p: Yes

I/p: 
                            [3]
                             |
                    [1]------------[2]
                                    |
                              [1]--------[2]
O/p: No

// Recursive Solution: 
    * Ides is to pick a node & check their left & right child & their sum is equal to the original value or not..
    * We have to consider base case carefully, like for leaf node, we have no other nodes, so 
        * we can say (root->left == NULL && root->right == NULL) return true..
    * And last we recursively check for left child & right child.
    * Recursive Calls
                            [10]
                             |
                    [8]------------[2]
                                    |
                              [2]----
               
                isSum(10)   -> return true
                    |--->isSum(8)   -> return true
                    |       |--->isSum(NULL)
                    |       |--->isSum(NULL)
                    |
                    |--->isSum(2)   -> return true
                            |--->isSum(2)   -> return true
                            |       |--->isSum(NULL)
                            |       |--->isSum(NULL)
                            |
                            |--->isSum(NULL)
    * TC : O(n)
    * AS : O(h), h = height of binary tree.


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

// Recursive Solution: 
bool isSum(Node *root){
    if(root == NULL) return true;   // if node is null return.
    if(root->left == NULL && root->right == NULL) return true;  // for leaf node
    int sum = 0;    // counting sum at every calls for match
    // adding values of left child & right child
    if(root->left != NULL){
        sum = sum + root->left->key;
    }
    if(root->right != NULL){
        sum = sum + root->right->key;
    }
    // we are checking sum of left & right child with node key & recursively calls for checking left & right childs..
    return (root->key == sum && isSum(root->left) && isSum(root->right));
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(8);
    root->right = new Node(2);
    root->right->left = new Node(2);

    (isSum(root) == 1) ? cout << "Yes" << endl : cout << "No" << endl;

    
    return 0;
}