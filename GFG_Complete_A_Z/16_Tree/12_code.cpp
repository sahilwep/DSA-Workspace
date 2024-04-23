/*
//  Size of binary tree: 

  I/p :
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [8]---------[7]        -----[6]
                                             |
                                      [9]---------[15]
    O/p : 8

    I/p : Null
    O/p : 0

    I/p :               
                                        [3]
                                         |
                                  [4]-----
                                   |
                                   ----[5]
    O/p : 4

    I/p : 
                                        [8]
                                         |
                                         ---------[6]
                                                   |
                                           [2]-----------[4]
                                                          | 
                                                    [3]----
    O/p : 5



// observation: 
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [8]---------[7]        -----[6]
                                             |
                                      [9]---------[15]


          getSize(10)   return 1 + 5 + 2 = 8
              |--->getSize(20)    return: 1 + 1 + 3 = 5
              |       |--->getSize(8)   return: 1 + 0 + 0 = 1
              |       |       |--->getSize(NULL)    return: 0
              |       |       |--->getSize(NULL)    return: 0
              |       |
              |       |--->getSize(7)    return: 1 + 1 + 1 = 3
              |               |--->getSize(9)    return: 1 + 0 + 0 = 1
              |               |       |--->getSize(NULL)    return: 0
              |               |       |--->getSize(NULL)    return: 0
              |               |
              |               |--->getSize(15)    return: 1 + 0 + 0 = 1
              |                       |--->getSize(NULL)    return: 0
              |                       |--->getSize(NULL)    return: 0
              |
              |--->getSize(30)      return: 1 + 0 + 1 = 2
                      |--->getSize(NULL)    return: 0
                      |
                      |--->getSize(6)     return: 1 + 0 + 0 = 1
                              |--->getSize(NULL)    return: 0
                              |--->getSize(NULL)    return: 0

// Iterative solution: 
    * We can use level order traversal : BFS, & by using counter we can count the size of binary tree..
    * TC : O(n)
    * SC : O(max width of binary tree)

// Recursive Solution: 
    * TC : O(n)
    * AS : O(h)

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
int getSize(Node *root){
    if(root == NULL) return 0;
    return 1 + getSize(root->left) + getSize(root->right);
}

// Iterative solution: 
int getSizeByBFS(Node *root){
    int count = 0;
    queue<Node *> q;
    q.push(root);
    while(q.empty() == false){
        Node *curr = q.front();
        q.pop();
        count++;
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
          q.push(curr->right);
        }
    }
    return count;
}

int main(void){
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(8); 
    root->left->right = new Node(7); 
    root->left->right->left = new Node(9); 
    root->left->right->right = new Node(15); 
    root->right->right = new Node(6);

    cout << getSize(root) << endl;
    cout << getSizeByBFS(root) << endl;
    
    return 0;
}