/*

//  Level order traversal

//  Observations: 
    * We are given root of binary tree, & we need to find the level order traversal.
    * Level order traversal is breadth first traversal for binary tree.


// Example:
    Example 1:

        Input:
            1
          /   \ 
         3     2

        Output: 1 3 2

        Example 2:

        Input:
        
                10
              /   \
            20     30
          /   \
         40   60

        Output: 10 20 30 40 60


// Intrusion:
    // Approach 1: Using Height & kth node..
        * First we will find the height of binary tree.
        * then, we will use function like Print node At kth distance,
        * And iterate it from 0 to that height..
        * TC: O(n*h)

    // Approach 2: Efficient Solution:


*/


//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}


class Solution{
public:
    // Method 1: O(n * h)
    vector<int> levelOrder(Node* root){
        vector<int> res;
        int height = heightOfTree(root);    // find the height of tree:

        // iterating from 0 to height & printing all the node at every level using kth function:
        for(int i=0;i<height;i++){
            vector<int> temp = kthNode(root, i);
            res = concatenation(res, temp);
        }

        return res;
    }
    // height of tree:
    int heightOfTree(Node *root){
        if(root == NULL) return 0;
        return 1 + max(heightOfTree(root->left), heightOfTree(root->right));
    }
    // Function used to print kth node:
    vector<int> kthNode(Node *root, int k){
        vector<int> res;
        // Using another function to get the result in vector..
        printKth(root, k, res);

        return res;
    }
    void printKth(Node* root, int k, vector<int>& res){
        if(root == NULL) return;    // If root become null before k become zero then return..
        // when k become zero, means we are at the correct level, so push that element into vector.
        if(k == 0){
            res.push_back(root->data);
        }
        // Iterating left then iterating right, as order start from left to right at every level.
        printKth(root->left, k-1, res);
        printKth(root->right, k-1, res);
    }
    // Function that Concat two vectors
    vector<int> concatenation(vector<int> v1, vector<int> v2){
        vector<int> res;

        for(auto i: v1) res.push_back(i);
        for(auto i: v2) res.push_back(i);

        return res;
    }
};


void inOrder(struct Node* node){
  if (node == NULL) return;
  inOrder(node->left);
  printf("%d ", node->data);
  inOrder(node->right);
}

Node* buildTree(string str){   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; ) ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
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
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size()) break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
  
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

int main(){
  int t;
  scanf("%d ",&t);
  while (t--){
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
		Solution ob;
        vector <int> res = ob.levelOrder(root);
        for (int i : res) cout << i << " ";
        cout << endl;
  }
  return 0;
}