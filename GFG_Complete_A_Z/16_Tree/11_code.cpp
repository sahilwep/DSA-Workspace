/*
// Level Order Traversal: BFS
    * Printing level by level from left to right...

   I/p :
                                            [10]
                                              |
                                      [20]-----------[30]
                                        |              |
                                [8]---------[7]        -----[6]
                                             |
                                      [9]---------[15]

    O/p : 10, 20, 30, 8, 7, 6, 9, 15

    I/p :               
                                        [3]
                                         |
                                  [4]-----
                                   |
                                   ----[5]

    O/p : 3, 4, 5

    I/p : 
                                        [8]
                                         |
                                         ---------[6]
                                                   |
                                           [2]-----------[4]
                                                          |
                                                    [3]----
    O/p : 8, 6, 2, 4, 3

// Naive Solution: 
    * First we can find the height of binary tree.
    * Then we can traverse from 0 to height of binary tree & for every level we print the nodes..
    * TC : O(h*n)
    * Recursive solution is not good idea, as it has TC : O(h*n)

// Better solution: 
    * We can use queue-ds to print the level order traversal:
    * The idea is to enque the level into the queue, then we take out the items from the queue & print them on the screen and when we are taking out an item, we enque the children of it, which means we enque the next level.
    * So, first we enque the root, & take out the root & print it, then we enque it's children which means the second level goes into the queue, and when we taking out the second level node, we enque the third level node into the queue, When we taking out third level one by one, we enque the fourth level in queue.....
    * So, this way our queue prints item in level order, because queue is FIFO..
        * We are taking in root, root will comes out first, then we are taking it's children & children of roots will come out first, & so on... 
    * So, when we are taking out and printing it, We are also enque the item of next level into the queue..


    * Every node goes inside the queue exactly once, & comes out of the queue exactly once...
    * TC : O(n)
    

    * When we process a one level, we have next level inside the queue, so we can say the width of binary tree..
    * As the tree height increases & the binary tree is perfectly balanced, the width of tree also increases & the number of nodes in last level is, in worst case, it's nearly equal to O(n)..
    * So, as worst case we can say we have O(n) nodes inside the queue.
    * AS : O(n), 
    * But in general we can say AS : O(w), w = width of binary tree..

// Pictorial Explanation: 

                                [10]
                                  |
                         [20]-----------[30]
                          |
                 [40]------

    // Queue: 
                [10| NULL|...................] 10
                [NULL|20|30|.................] \n
                [20|30|NULL|.................] 20
                [30|NULL|40|.................] 30
                [NULL|40|....................] \n
                [40|NULL|....................] 40
                [NULL|.......................] \n

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

// Better solution: 
void levelOrderTraversal(Node *root){
    if(root == NULL) return;
    queue<Node*> q;
    q.push(root);
    while(q.empty() == false){
        Node *curr = q.front();
        q.pop();
        cout << curr->key << " ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}


// // Naive Solution: 
// height of binary tree: 
int height(Node *root){
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}
// Printing node at kth distance: 
void printKthNode(Node *root, int k){
    if(root == NULL) return;
    if(k == 0){
        cout << root->key << " ";
        return;
    }
    printKthNode(root->left, k-1);
    printKthNode(root->right, k-1);
}
// Level order traversal:
void levelOrderTraversal_(Node *root){
    // getting height of binary tree: 
    int heightOfTree = height(root);
    // printing from 0 to height using function kth distance..
    for(int i=0;i<heightOfTree;i++){
        printKthNode(root, i);
    }
}

int main(void){
    
    Node *root = new Node(8);
    root->right = new Node(6);
    root->right->left = new Node(2);
    root->right->right = new Node(4);
    root->right->right->left = new Node(3);
    
    levelOrderTraversal(root);
    
    return 0;
}