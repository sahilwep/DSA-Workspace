/*

// Preorder Traversal


// Observations: 
    * Given a binary tree find the preorder traversal.
    * Preorder: root -> left -> right

// Example: 

        [1]
         |
        [4]
         |
   [4]-------[2]

        -> 1 4 4 2


                   [6]
                    |
          [3]--------------[2]
           |                |
           ----[1]    [2]----

        -> 6 3 1 2 2

*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val){
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str){
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')  return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )   ip.push_back(str);

    // for(string i:ip)
    //     cout<<i<<" ";
    // cout<<endl;
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
        if(i >= ip.size())  break;
        currVal = ip[i];
        // If the right child is not null
        if(currVal != "N"){
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// PreOrder Traversal:
void preOrder(Node *root, vector<int> &res){
    if(root != NULL){
        res.push_back(root->data);
        preOrder(root->left, res);
        preOrder(root->right, res);
    }
}

vector <int> preorder(Node* root){
    vector<int> res;
    preOrder(root, res);
    return res;
}

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        string s;
        getline(cin,s);
        Node* root = buildTree(s);

        vector<int> res = preorder(root);
        for (int i : res)   cout << i << " ";
        cout<<endl;
    }

    return 0;
}
