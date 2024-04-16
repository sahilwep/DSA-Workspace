/*
//  Print node at distance k

I/p : 

   I/p :  k = 2
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [40]---------[50]      ---------[70]
    O/p : 40, 50, 70


   I/p :  k = 1
                                            [10]
                                              |
                                      [20]-----
                                        |             
                                [40]----- 
    O/p : 20


    I/p : k = 3
                                            [10]
                                              |
                                        [6]--------[8]
                                                    |
                                                    -------[7]
                                                            |
                                                      [11]-------[12]  
    O/p : 11, 12

// Recursive Calls: 
          k = 2
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [40]---------[50]      ---------[70]
                                                                  |
                                                                  -----[80]
          O/p : 40, 50, 70

          nodeAtK(10, 2)
              |--->nodeAtK(20, 1)
              |       |--->nodeAtK(40, 0) -> print(20),as k == 0
              |       |       |--->nodeAtK(NULL, -1) -> return
              |       |          
              |       |--->nodeAtK(50, 0) -> print(50),as k == 0
              |               |--->nodeAtK(NULL, -1) -> return
              |
              |--->nodeAtK(30, 1)
                    |--->nodeAtK(70, 0) -> print(70), as k == 0
                          |--->nodeAtK(80, -1)
                                  |--->nodeAtK(NULL, -2) -> return

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

// printing node at k distance: 
void nodeAtK(Node *root, int k){
  if(root == NULL) return;
  if(k == 0){
    cout << root->key << " ";
  }
  nodeAtK(root->left, k-1);
  nodeAtK(root->right, k-1);
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
    
    int k = 3;  // as per the example
    nodeAtK(root, k);

    return 0;
}
