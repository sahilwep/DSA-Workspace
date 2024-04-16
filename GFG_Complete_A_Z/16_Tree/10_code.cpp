/*
//  Sum of leaf node of binary tree.

   I/p :
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [40]---------[50]      ---------[70]
    O/p : 40 + 50 + 70 = 160


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
    O/p : 29

// Recursive Calls: 
                I/p :
                                                        [10]
                                                          |
                                                    [6]--------[8]
                                                                |
                                                                -------[7]
                                                                        |
                                                                  [11]-------[12]  
                O/p : 29
                             
          sumOfLeaf(10, 0)
              |--->sumOfLeaf(6, 0)-> sum = 0 + 6 : 6, return as there is no left or right node.. 
              |
              |--->sumOfLeaf(8, 6)
                    |
                    |--->sumOfLeaf(7, 6)
                          |
                          |--->sumOfLeaf(11, 6) -> sum = 6 + 11 : 17, return as there is no left or right node.. 
                          |
                          |--->sumOfLeaf(12, 17) -> sum = 17 + 12 : 29, return as there is no left or right node.. 

            // at the end, sum become 29, As we passed referenced in parameter, the actual address value changes to 29...


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
void sumOfLeaf(Node *root, int &sum){
  if(root == NULL) return;  // edge case, if root itself is passed empty..
  if(root->left == NULL && root->right == NULL){
    sum += root->key;
  }
    sumOfLeaf(root->left, sum);
    sumOfLeaf(root->right, sum);
}

int main(void){
    
    Node *root = new Node(10);
    root->left = new Node(6);
    root->right = new Node(8);
    root->right->right = new Node(7);
    root->right->right->left = new Node(11);
    root->right->right->right = new Node(12);


    int sum = 0;
    sumOfLeaf(root, sum);
    cout << sum << endl;

    // Clean up memory: 
    delete root->right->right->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root->left;
    delete root;
    
    return 0;
}
