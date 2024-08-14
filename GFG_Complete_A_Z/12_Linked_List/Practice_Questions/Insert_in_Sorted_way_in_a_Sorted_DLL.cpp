/*
//  Insert in Sorted way in a Sorted DLL

// Observations: 
    * We are given sorted doubly linked list, and we are given an element "x", we need to insert it in linked list in sorted fashion..


// Intrusion:
    * we can get position which is just grater than than the given element "x",
    * Once we found that element, we insert node just before that node, & break out the iterations..

    * Edge Cases: 
            * When x is grater among all, all allocation is at end of linked list.
            * When x is allocated in middle range..
            * There are others edge cases also, that we have to look for, i have mentions all of them into the code descriptions..

*/



#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *prev, *next;
};

struct Node* getNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

void printList(struct Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

class Solution {
  public:
    Node* sortedInsert(Node* head, int x) {
        Node *temp = getNode(x);   // node x allocations

        // common cases: 
        if(head == NULL) return temp;
        if(head->next == NULL){
            // allocations is at last:
            if(head->data < x){
                head->next = temp;  // linking head with temp.
                temp->prev = head;  // linking newly allocated node with previous head.
                temp->next = NULL;   // making temp next is equal to null
                return head;    // returning head as original reference is not changed;
            }
            // when allocations is at front
            else{
                temp->prev = NULL;  // making temp prev to NULL
                temp->next = head;  // linking temp next to head
                head->prev = temp;  // linking head prev with newly allocated temp
                head->next = NULL;  // making head next NULL, as we don't have any value to link..
                return temp;    // last returning the temp.
            }
        }

        // Allocation is at beginning: 
        if(head->data > x){
            temp->prev = NULL;  // making temp prev as null
            temp->next = head;  // linking temp next with head pointer
            head->prev = temp;  // linking head prev with temp
            return temp;    // returning temp as new head
        }

        
        // finding the correct position to insert that node x:
        Node *curr = head;
        while(curr->next != NULL){
            if(curr->data > x){
                break;   // get the position.
            }
            curr = curr->next;
        }
        // edge case: when pointer point to last element, we have to compare the last value in order to correct linking of nodes...
        /*
        // edge case: when 
            Input:
                1271 2186 5161 8390
                5170
                if we don't compare value, the linking of 5170 will be after the 8390, as our current pointer point to the last nodes...
                So, it's important to compare the values..

        */ 
        if(curr->next == NULL && curr->data < x){
            temp->next = NULL;  // as temp is last node
            curr->next = temp;  // linking current node with temp
            temp->prev = curr;  // linking temp previous with current reference.
            return head;
        }
        else{
            // else when we have to insert value in between the linked list:
            // as current data is grater than the given data, means we have to allocate node just before the current
            Node *start = curr->prev;   // creating the reference that will store the current prev.
            // linking curr prev with allocated node
            start->next = temp; // linking start->next with temp
            temp->prev = start; // linking temp->prev with start
            
            // linking curr with allocated node
            temp->next = curr;
            curr->prev = temp;

        }
        return head;    // at last we return head, as we haven done no changes
    }
};



int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;
        if (ss >> x) {
            head = getNode(x);
            tail = head;
        }
        while (ss >> x) {
            tail->next = getNode(x);
            tail->next->prev = tail;
            tail = tail->next;
        }
        int valueToInsert;
        cin >> valueToInsert;
        cin.ignore(); // Ignore the newline character after the value

        Solution obj;
        head = obj.sortedInsert(head, valueToInsert);
        printList(head);
    }

    return 0;
}