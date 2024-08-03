/*

// Reverse a linked list: 
    * We are given singly linked list, we have to reverse it..

// Intrusion: 

    // Approach 1: We can use AS(N) size data structure like array or stack...
        * We can use stack for reversing the singly linked list...
        * This approach work fine, but it's take more time than usually...
        * this method will take TC: O(N), & SC: O(N)



    // Approach 2: we can change the pointer of node after every iteration....
        * while iterating throughout the linked list, we will change the pointer of nodes..
        * this method will take TC: O(N), & SC: O(1)

       head
        |
        []->[]->[]->[]->[]->[]->[]->[]->[]->NULL

             head
               |
        NULL<-[]---->[]---->[]---->[]
                * after every node that we visit we will have to store their temp reference, & change it in original...

        * At last we will change the head as last node of original linked list...

        * The idea is to reverse the links of all the nodes using three pointers:
            prev: pointer to keep track of previous node
            curr: pointer to keep track of current node
            next: pointer to keep track of next node
        * Starting from the first node, initialize curr with the head of linked list and next with the next node of curr.
        * Update the next pointer of curr with prev.
        * Finally, move the three pointer by updating prev with curr & curr with next.

            Example:    [1]->[2]->[3]->[4]->[5]->[6]
                        head

                    * Allocate nodes: 
                            curr = head
                            prev = NULL;
                            next

                    * while(curr != NULL)
                        1st iteration: 
                                [1]->[2]->[3]->[4]->[5]->[6]     next is used to store curr->next reference.
                                curr

                                    next = curr->next   stored reference of curr->next into next
                                    curr->next = prev;  [1]->NULL

                                    prev = curr     // updating prev to curr, because 
                                    curr = next     // as we have stored reference of curr->next into next..
                        

                        2nd iteration:
                            [1]->NULL       [2]->[3]->[4]->[5]->[6]         next is used to store curr->next reference.
                            prev            curr

                                    next = curr->next   stored reference of curr->next into next
                                    curr->next = prev;  [1]->NULL

                                    prev = curr     // updating prev to curr, because 
                                    curr = next     // as we have stored reference of curr->next into next..
                        

                        3rd iteration:
                            [2]->[1]->NULL             [3]->[4]->[5]->[6]          next is used to store curr->next reference.
                            prev                      curr

                                    next = curr->next   stored reference of curr->next into next
                                    curr->next = prev;  [1]->NULL

                                    prev = curr     // updating prev to curr, because 
                                    curr = next     // as we have stored reference of curr->next into next..
                        

                        4th iteration:
                            [3]->[2]->[1]->NULL              [4]->[5]->[6]          next is used to store curr->next reference.
                            prev                             curr

                                    next = curr->next   stored reference of curr->next into next
                                    curr->next = prev;  [1]->NULL

                                    prev = curr     // updating prev to curr, because 
                                    curr = next     // as we have stored reference of curr->next into next..
                        

                        5th iteration:
                            [4]->[3]->[2]->[1]->NULL              [5]->[6]          next is used to store curr->next reference.
                            prev                                  curr

                                    next = curr->next   stored reference of curr->next into next
                                    curr->next = prev;  [1]->NULL

                                    prev = curr     // updating prev to curr, because 
                                    curr = next     // as we have stored reference of curr->next into next..
                        

                        6th iteration:
                            [5]->[4]->[3]->[2]->[1]->NULL          [6]          next is used to store curr->next reference.
                            prev                                  curr

                                    next = curr->next   stored reference of curr->next into next
                                    curr->next = prev;  [1]->NULL

                                    prev = curr     // updating prev to curr, because 
                                    curr = next     // as we have stored reference of curr->next into next..
                        
                        7h iteration:
                            * break, because after 6th we have our curr has no nodes...

                                [6]->[5]->[4]->[3]->[2]->[1]->NULL     []          next is used to store curr->next reference.
                                prev                                  curr


// TC: O(N)

*/


#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    // Approach 1: Using AS:O(N) size Data structure like stack or array...
    Node* reverseList_A1(Node* head) {
        if(head == NULL) return head;   // if we have no node in linked list..
        if(head->next == NULL ) return head;    // if we have only one node in linked list..

        // using stack to reverse the linked list...
        stack<int> s;
        Node *curr = head;
        while(curr->next != NULL){
            s.push(curr->data); // first we will insert all the element into the stack..
        }

        // Now we will iterate once again & updating the values of each nodes by stack values...
        // this is how we can reverse the nodes values of linked list..
        Node *c = head;
        while(curr->next != NULL){
            curr->data = s.top();
            s.top();
            curr = curr->next;
        }

        // return head;
        return head;
    }
    // Approach 2: Changing the node reference after every iterations...
    Node *reverseList_A2(Node *head){
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        // using three pointer reference to reverse...
        Node *curr = head;
        Node *prev = NULL;  // this reference is used to connect all the reference that we traverse...
        Node *next; 

        while(curr != NULL){
            next = curr->next;  // making reference of curr->next into next
            curr->next = prev;  // changing the current->next to prev, i.e curr->next as new prev

            prev = curr;    // updating previous
            curr = next;    // updating current
        }
        return prev;
    }

};

void printList(struct Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int T, n, l, firstdata;
    cin >> T;
    cin.ignore();
    while (T--) {
        struct Node *head = NULL, *tail = NULL;

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int index = 0;
        n = arr.size();
        if (n != 0) {

            head = new Node(arr[0]);
            tail = head;
        }

        for (int i = 1; i < n; i++) {
            l = arr[i];
            tail->next = new Node(l);
            tail = tail->next;
        }

        Solution ob;
        // head = ob.reverseList_A1(head);  // approach 1
        head = ob.reverseList_A2(head); // approach 2

        printList(head);
        cout << endl;
    }
    return 0;
}