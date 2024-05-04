/*
// Level Order Traversal Line by Line (Part 2)
    * We break down the logic into two loops.

   I/p :
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [40]---------[50]      -----[60]
                                                              |
                                                       [70]---------[80]
    O/p : 
            10
            20 30
            40 50 60 
            70 80



    I/p :               
                                        [10]
                                         |
                                         ----[8]
                                              |
                                              ----[6]
    O/p : 
            10
            8
            6



    I/p : 
                                        [5]
                                         |
                                 [3]---------[10]
                                              |
                                      [15]-----
    O/p : 
            5
            3 10
            15

// Explanation: 
    * In previous method, we were adding null after printing every level.
    * Here, we break down level order printing into two loops.
    * The outer loops runs the inner loop for every level
    * The inner loop print one level at a time.
    * And outer loop print new line, after the inner loop has printed the level.
    * Example:
                           [10]
                            |
                    [20]---------[30]
                     |            |
              [40]-----[50]       ------[60]
    
            Queue:              print
        [10|            ]         10 \n
        [20|30|         ]         20 30 \n
        [40|50|60|      ]         40 50 60 \n


// Complexity: 
    * TC : O(n), because we are traverse n nodes, & it's going to enter into queue once & comes out once, Entering & coming out is constant operations.
    * AS : O(width), O(n)


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

void printLevelOrderLine(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        int count = q.size();   // note: this count should be separate because q.size(), will change after every insertion.. 
        for(int i=0;i<count;i++){
            Node *curr = q.front();
            q.pop();
            cout << curr->key << " ";
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
        cout << "\n";
    }
}


int main(void){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    
    printLevelOrderLine(root);
    
    return 0;
}