/*

// Height of Binary Tree

// Observations:    
    * we are given a binary tree we need to find the height of binary tree


        [1]
         |
    [2]------[3]

        -> 2

        [1]
         |
    [2]------[3]
     |
     ---[4]
        
        -> 3


*/

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 

// Function to Build Tree
Node* buildTree(string str){
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')  return NULL;
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    istringstream iss(str);
    for(string str; iss >> str; )   ip.push_back(str);
    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
        // Get the current node's value from the string
        string currVal = ip[i];
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->left);
        }
        // For the right child
        i++;
        if(i >= ip.size())  break;
        currVal = ip[i];
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

class Solution{
    public:
    //Function to find the height of a binary tree.
    int height(struct Node* node){
        if(node == NULL) return 0;
        return 1 + max(height(node->left), height(node->right));
    }
};


int main(){
    int t;
	scanf("%d ",&t);
    while(t--){
        string treeString;
		getline(cin,treeString);
		Node* root = buildTree(treeString);
        Solution ob;
		cout<<ob.height(root)<<endl;
    }
    return 0;
}