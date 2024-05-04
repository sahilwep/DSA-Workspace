/*
// Print Left view of Binary Tree: 
    * We have to print leftmost node of every level...

    I/p :           
                            [10]
                             |
                    [20]------------[30]
                     |                |
              [40]-------[50]          ------[60]


    O/p : 10 20 40


    I/p :           
                            [10]
                             |
                    [50]------------[60]
                                      |
                               [70]--------[20]
                                |
                                ------[8]
    O/p : 10 50 70 8

    I/p : 
                                [30]
                                 |
                                 ----------[50]
                                            |
                                    [60]-----
                                     |
                                     ----[10]
    O/p : 30 50 60 10



// Recursive Solution: 
    * If we do preorder traversal in binary tree, we will alway visit the leftmost node of the level before any other node.
    * We will use preorder traversal..
    * TC : O(n)
    * AS : O(h), h= height of binary tree.


// Iterative Solution: 
    * It's based on level order traversal line by line method 2
    * We only print the current node, if i = 0, means our first node.
    * TC : O(n)
    * AS : O(width)

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int maxLevel = 0;   // making it global variable

struct Node{
    int key;
    Node *left, *right;
    Node(int k){
        key = k;
        left = right = NULL;
    }
};

// Iterative Solution: 
void printLeftMost_(Node *root){
    if(root == NULL) return;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        int count = q.size();
        for(int i=0;i<count;i++){
            Node *curr = q.front();
            q.pop();
            if(i == 0){
                cout << curr->key << " ";
            }
            if(curr->left != NULL) q.push(curr->left);
            if(curr->right != NULL) q.push(curr->right);
        }
    }
}

// Recursive Solution: 
void printLeftMost(Node *root, int level){
    if(root == NULL) return;
    if(maxLevel < level){
        cout << root->key << " ";
        maxLevel = level;
    }
    printLeftMost(root->left, level+1);
    printLeftMost(root->right, level+1);
}


int main(void){
    Node *root = new Node(10);
    root->left = new Node(50);
    root->right = new Node(60);
    root->right->left = new Node(70);
    root->right->right = new Node(20);
    root->right->left->right = new Node(8);
    
    printLeftMost(root, 1);
    cout << endl;
    printLeftMost_(root);
    
    
    return 0;
}