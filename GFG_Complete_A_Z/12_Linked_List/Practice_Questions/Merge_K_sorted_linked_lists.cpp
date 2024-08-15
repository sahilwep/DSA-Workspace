/*
//  Merge K sorted linked lists

// Observations: 
    * we are given an array that contains multiple linked list, which are sorted in ordre..
    * We have to get all the data from it & make it one.
    * At last we have to return the linked list..

// Example: 
    Input: arr = [1->2->3, 4->5, 5->6, 7->8]
    Output: 1->2->3->4->5->5->6->7->8
    Explanation:
        The test case has 4 sorted linked 
        list of size 3, 2, 2, 2
        1st    list     1 -> 2-> 3
        2nd   list      4->5
        3rd    list      5->6
        4th    list      7->8
        The merged list will be

// Key Observations: 
    * while iterating linked list, we have to tak each starting node of linked list & merge them..
    * We will maintain two pointer, one is start, & other is temp, which help us to link all the given linked list
    * we have to merge all the linked list in a way so that all the linked list is sorted in order.

// Intrusion:
    * first we linked all the linked list together...
    * Once the linking is done, we will sort the values, by transferring all the values from final linked list to an array..
    * then once value is sorted we will update the values again in final linked list..


*/


#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    cout << endl;
}


class Solution {
  public:
    // Function to merge K sorted linked list.
    Node* mergeKLists(vector<Node*>& arr) {
        // Common cases: 
        if(arr.size() == 0){
            return NULL;
        }
        else if(arr.size() == 1){
            return arr[0];
        }


        // making reference:
        Node *start = new Node(0);  // this reference will contains the original position where our first nodes is starting
        Node *temp = arr[0];    // this temp reference will link all the values together
        start->next = temp; // linking start & temp, so that we can have final linked reference

        // as we have given temp the first reference, we need to iterate till last position,
        // so that we can link the further node together
        while(temp->next != NULL){
            temp = temp->next;
        }
        
        // now temp has last address of first node, we can merge them by iterating...
        // Node: iteration start from 1, because we already store the first linked list reference..
        for(int i=1;i<arr.size();i++){

            // first we link previous found linked list with current starting node
            temp->next = arr[i];    // linking the last node that we found with current starting node


            // By iterations, we find the last position of linked list node.
            Node *curr = arr[i];
            while(curr->next != NULL){
                curr = curr->next;
            }

            // At last we store the current linked list last node into the temp.
            temp = curr;
        }


        // At last we make final which holds start->next, which is the starting pointer of our linked list
        Node *final = start->next;
        delete start;   // finally free the start.


        // finally sort the linked list:
        vector<int> v;  // extract values from final linked list & store it into the array..
        Node *c = final;
        while(c != NULL){
            v.push_back(c->data);
            c = c->next;
        }
        sort(v.begin(), v.end());   // sort the element of linked list

        Node *d = final;    // at last we update the values
        int k = 0;
        while(d != NULL){
            d->data = v[k++];
            d = d->next;
        }


        return final;   // returning the final.
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<Node*> arr;
        vector<int> nums;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            nums.push_back(number);
        }
        int ind = 0;
        int N = nums.size();

        while (ind < N) {
            int n = nums[ind++];
            int x = nums[ind++];
            Node* head = new Node(x);
            Node* curr = head;
            n--;

            for (int i = 0; i < n; i++) {
                x = nums[ind++];
                Node* temp = new Node(x);
                curr->next = temp;
                curr = temp;
            }
            arr.push_back(head);
        }

        Solution obj;
        Node* res = obj.mergeKLists(arr);
        printList(res);
    }
    return 0;
}