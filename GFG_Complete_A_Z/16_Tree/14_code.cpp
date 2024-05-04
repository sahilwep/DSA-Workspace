/*
// Level Order Traversal Line by Line (Part 1)


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
    * Idea is to push null marker when we traverse the current level completely.
    * At the end of every level we push null marker, so that it's identifies that new level start after null value.
    * Example: 
                [10]
                 |
          [20]-------[30]
           |
    [40]----

    *

           Insert at last pos          Takeout from front & print 
        [10 | NULL|.............]                  10
        [NULL | 20 | 30 |.......]                  \n
        [ 20 | 30 | NULL |......]                  20
        [ 30 | NULL |40 |.......]                  30
        [ NULL |40 | NULL |.....]                  \n
        [ 40 | NULL |...........]                  40
        [ NULL |................]                  \n

// Time
    TC : O(n+h) = O(n), every node goes in queue & comes out exactly once. & we have to process extra NULL at end of every level, i.e O(h) NULL.
    AS : O(width)

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
    if(root == NULL) return;    // if root is empty, we return.
    queue<Node *> q;    // making a queue of node type
    q.push(root);       // insert root inside the queue
    q.push(NULL);       // after inserting null inside the queue
    // condition will false when we have only last level null value inside the queue..
    while(q.size() > 1){
        Node *curr = q.front();     // making a curr node & inserting queue front element.
        q.pop();    // removing queue front element.
        // checking if our curr pointer value has null or not
        if(curr == NULL){   
            cout << "\n";   // if our curr pointer value is null, then we print "\n" 
            q.push(NULL);   // and push null value inside the queue.
            continue;   // skip the current part of iteration..
        }
        cout << curr->key << " ";   // if curr is not null, then print the curr->node key
        if(curr->left != NULL){
            q.push(curr->left); // inserting left child node 
        }
        if(curr->right != NULL){
            q.push(curr->right);   // inserting right child node 
        }
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