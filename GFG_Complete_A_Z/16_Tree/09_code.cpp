/*
//  Print leaf node of binary tree.

   I/p :
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [40]---------[50]      ---------[70]
    O/p : 40, 50, 70


   I/p :
                                            [10]
                                              |
                                      [20]-----
                                        |             
                                [40]----- 
    O/p : 40


    I/p :
                                            [10]
                                              |
                                        [6]--------[8]
                                                    |
                                                    -------[7]
                                                            |
                                                      [11]-------[12]  
    O/p : 6, 11, 12

// Recursive Calls: 
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [40]---------[50]      ---------[70]
                                                                  |
                                                                  -----[80]
          O/p : 40, 50, 80

          leafNode(10)
              |--->leafNode(20)
              |       |--->leafNode(40) -> print(20), return
              |       |--->leafNode(50) -> print(50), return
              |
              |--->leafNode(30)
                    |--->leafNode(70)
                          |--->leafNode(80) -> print(80), return


// TC : O(n) -> In worse case we have to iterate all the nodes..
// AS : O(h+1) -> O(h), h = height of tree.

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

// Leaf of binary tree:
void leafNode(Node *root){
  if(root == NULL) return;  // edge case, if root itself is passed empty..
  if(root->left == NULL && root->right == NULL){
    cout << root->key << " ";
    return; // after printing leaf node, we return the call...
  }
  leafNode(root->left);
  leafNode(root->right);
}

void preOrder(Node *root){
  if(root != NULL){
    cout << (root->key) << " ";
    preOrder(root->left);
    preOrder(root->right);
  }
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);

    preOrder(root);
    cout << endl;
    
    leafNode(root);

    // Clean up memory: 
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
