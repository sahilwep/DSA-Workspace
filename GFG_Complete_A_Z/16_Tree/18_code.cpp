/*
// Check for Balanced tree:
    * The difference b/w the hight of left subtree & right subtree should be not more than 1 & this should be true for every node.

    I/p :           
                               [18]
                                |
                         [4]-------------[20]
                                           |
                                     [13]------[70]
    O/p: Yes
    Explanation: 
                    for 18: left height = 1, right height = 2, & diff = 1
                    for 4: left height = 0, right height = 0, & diff = 0
                    for 20: left height = 1, right height = 1, & diff = 0
                    for 13: left height = 0, right height = 0, & diff = 0
                    for 17: left height = 0, right height = 0, & diff = 0


    I/p:        
                                [3]
                                 |
                        [4]-------
                         |
                [5]-------
    O/p: No
    Explanation:    
                    for 10: left height = 2, right height = 0, & diff = 2, So false

    I/p 
                                       [3]
                                        |
                                [4]-------------[8]
                                 |               |
                            [5]-----[9]          ----[7]
                                                       |
                                                [6]----
    O/p: No


    I/p 
                                       [30]
                                        |
                                [40]-------------[80]
                                 |                 |
                            [50]-----[70]   [5]-----
                                       |
                                 [20]-------[10]
    O/p: Yes



// Naive Solution: 
    * Idea is simple, we begin with root
    * We call the height of left subtree & compute the height of right subtree
    * We check if the difference is less than or equal to 1,
    * If that is true, we call isBalanced recursively for left subtree to check the left subtree is balanced,
    * and we call for the right subtree to heck the right subtree is balanced.
    * If all these three condition are true, then we return true.

    * TC : O(n^2)
    * height of subtree for n node will take O(n-1) = O(n) time, & We are doing this for n times, So O(n^2)




// Efficient Solution: 
    * Idea for this O(n) is, what if the left child call & right child call tell they are balanced or not & also tell their height.
        * Every subtree will tells whether they are balanced or not & they will also return the height..
        * We can implement this solution by using pair, where the first value is boolean value which tells the balanced or not, & second value is height..
        * One Interesting & tricky implementation is to return only one value,
            * we say, this function is return -1, if tree or subtree is unbalanced
            * otherwise it will return height, because height can never be -1, it's always 0 & positive.
            * So, by one value we can do both the purposes...
        
        * The function will return -1, if it's unbalanced, otherwise it will return height..
        * At any movement of the recursive calls, if we got -1, we immediately return the function calls.
        * So, before checking the whole node, we check for the left subtree node & right subtree node..

    * TC : O(n)


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

// Naive Solution: 
int height(Node *root){
    if(root == NULL) return 0;
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root){
    if(root == NULL) return true;
    int lh = height(root->left);
    int rh = height(root->right);
    return(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right));
}


// Efficient Solution: 
int isBalanced_(Node *root){
    if(root == NULL) return 0;
    // check for left subtree, also get the left subtree height
    int lh = isBalanced_(root->left);
    if(lh == -1) return -1;

    // check for right subtree, also get the right subtree height
    int rh = isBalanced_(root->right);
    if(rh == -1) return -1;
    
    if(abs(lh-rh) > 1) return -1;   // getting the difference of height
    else return max(lh, rh) + 1;    // return height
}


int main(void){
    Node *root = new Node(30);
    root->left = new Node(40);
    root->right = new Node(80);
    root->left->left = new Node(50);
    root->left->right = new Node(70);
    root->left->right->left = new Node(20);
    root->left->right->right = new Node(10);
    root->right->left = new Node(5);

    (true == isBalanced(root)) ? cout << "Yes" << endl : cout << "No" << endl;
    (-1 == isBalanced_(root)) ? cout << "No" << endl : cout << "Yes" << endl;
    
    return 0;
}