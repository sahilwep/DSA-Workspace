/*
// Maximum in Binary tree: 

  I/p :
                                            [10]
                                              |
                                      [30]-----------[40]
                                        |              |
                                [80]-----       [60]--------[20]
                                 |
                                 -------[70]
    O/p : 80

    I/p : Null
    O/p : -infinity

    I/p :               
                                        [30]
                                         |
                                  [20]-----
                                   |
                           [40]-----
    O/p : 40

    I/p : 
                                        [50]
                                         |
                                  [40]---------[80]
    O/p : 5

// Observation: 
                                            [10]
                                              |
                                      [30]-----------[40]
                                        |              |
                                [80]-----       [60]--------[20]
                                 |
                                 -------[70]


            getMax(10)          : get max of child call & compare the max with current node & return max to parent call
                |---->getMax(30)        : get max of child call & compare the max with current node & return max to parent call
                |       |---->getMax(80)        : get max of child call & compare the max with current node & return max to parent call
                |               |---->getMax(NULL) 
                |               |---->getMax(70)   
                |                       |---->getMax(NULL)    
                |                       |---->getMax(NULL)    
                |
                |
                |---->getMax(40)        : get max of child call & compare the max with current node & return max to parent call
                        |--->getMax(60)
                        |       |--->getMax(NULL)
                        |       |--->getMax(NULL)
                        |
                        |--->getMax(20)
                                |--->getMax(NULL)
                                |--->getMax(NULL)


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

int getMax(Node *root){
    if(root == NULL){
        return INT_MIN;
    }
    else {
        return max(root->key, max(getMax(root->left), getMax(root->right)));
    } 
}


int main(void){

    Node *root = new Node(10);
    root->left = new Node(30);
    root->right = new Node(40);
    root->left->left = new Node(80);
    root->left->left->right = new Node(70);
    root->right->left = new Node(60);
    root->right->right = new Node(20);
    
    cout << getMax(root) << endl;

    return 0;
}