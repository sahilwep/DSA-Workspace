/*

// Merge two sorted linked lists

// Observations: 
    * we are given two sorted linked list, we need to merge them into one..
    * while merging two linked list, we need to careful about several edge cases..
        * first case: when size of both the linked list is not same..
        * we have to compare the linked list, & maintaining which node we are using as reference.


// Intrusion: 
    * Easy Approach:
        * We can use auxilary array to merge & at last we can transfer all the merged values into linked list.
        * TC: O(n+m)
        * AS: O(n+m)

    * Better Solution:
        * We can merge the linked list, by using auxilary linked list.
        * While merging we allocate every node in new linked list chain.
        * TC: O(n+m)
        * AS: O(n+m)

    * Efficient Approach:
        * we can perform this merging operations in linked list itself.
        * We can use two pointer approach: 
            * first pointer point the first linked list node
                * we can increase first pointer once we found lower value node.
            * Second pointer point the second linked list
                * we can increase second pointer once we found lower value node.
        * We will maintain a third reference pointer, that will hold the final linked list..
        * TC: O(n+m)
        * AS: O(1)



*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << '\n';
}


// Function to merge two sorted linked list.
class Solution {
  public:
    // using basic Approach: 
    Node* sortedMerge_(Node* head1, Node* head2) {
        // finding size: 
        Node *c1 = head1;
        int s1 = 0;
        while(c1 != NULL){
            s1++;
            c1 = c1->next;
        }
        int s2 = 0;
        Node *c2 = head2;
        while(c2 != NULL){
            s2++;
            c2 = c2->next;
        }

        // create auxilary size array & Merge values: 
        vector<int> arr(s1+s2);
        Node *cur1 = head1, *cur2 = head2;
        int i = 0;
        while(cur1 != NULL && cur2 != NULL){
            if(cur1->data <= cur2->data){
                arr[i++] = cur1->data;
                cur1 = cur1->next;
            }else{
                arr[i++] = cur2->data;
                cur2 = cur2->next;
            }
        }
        // handling the leftover:
        while(cur1 != NULL){
            arr[i++] = cur1->data;
            cur1 = cur1->next;
        }

        while(cur2 != NULL){
            arr[i++] = cur2->data;
            cur2 = cur2->next;
        }

        // Now we allocate all the value from the array to linked list:
        int k = 0;
        Node *curr1 = head1;
        while(curr1 != NULL){
            curr1->data = arr[k++];
            curr1 = curr1->next;
        }

        Node *curr2 = head2;
        while(curr2 != NULL){
            curr2->data = arr[k++];
            curr2 = curr2->next;
        }

        // Last we linked both the linked list.
        Node *first = head1;
        while(first->next != NULL){
            first = first->next;
        }
        first->next = head2;    // first last linked with second linked list..
        

        return head1;   // return first head pointer..
    }   // end of the first function:

    // Better Solution: 
    Node* sortedMergeBetter(Node* head1, Node* head2){
        Node *c1 = head1;   // pointer 1
        Node *c2 = head2;   // pointer 2

        // final node that contains the linked list chain
        Node *chain = NULL;
        while(c1 != NULL && c2 != NULL){
            if(c1->data <= c2->data){
                chain = insertEnd(chain, c1->data);
                c1 = c1->next;  // moving first pointer
            }else{
                chain = insertEnd(chain, c2->data);
                c2 = c2->next;  // moving second pointer
            }
        }

        // inserting left over:
        while(c1 != NULL){
            chain = insertEnd(chain, c1->data);
            c1 = c1->next;
        }
        while(c2 != NULL){
            chain = insertEnd(chain, c2->data);
            c2 = c2->next;
        }

        return chain;   // returning new chain that we have created..
    }

    // insert node at linked list:
    Node *insertEnd(Node *head, int x){
        Node *temp = new Node(x);
        if(head == NULL){
            return temp;
        }
        else if(head->next == NULL){
            head->next = temp;
            return head;
        }
        Node *curr = head;
        while(curr->next != NULL){
            curr = curr->next;
        }
        curr->next = temp;
        return head;
    }

    // Efficient Solution: 
    Node *sortedMerge(Node *head1, Node *head2){

        // node that help to merge two linked list: 
        Node *dummy = new Node(0);      // reference that contains the starting point of linked chain
        Node *tail = dummy; // this reference keep on changing..

        // using two pointer head1 & head2 that will compare & iterate
        while(head1 != NULL && head2 != NULL){
            if(head1->data <= head2->data){
                tail->next = head1;     // making tail next equal to head1
                head1 = head1->next;    // moving head1 pointer forward
            }else{
                tail->next = head2;     // making tail next equal to head2
                head2 = head2->next;    // moving head2 pointer forward
            }
            // at last we need to move tail also, because we need this tail reference to attach further compared nodes..
            tail = tail->next;  // after every iteration we need to move tail to tail next, so that we can add next node with it..
        }

        // inserting left over nodes from any of the linked list: as we only one node left from any of these nodes..
        if(head1 != NULL){
            tail->next = head1;
        }else{
            tail->next = head2;
        }

        // Store the result in final node & free dummy node
        Node *final = dummy->next;  // storing the dummy->next reference that is starting point
        delete dummy;   // free memory

        return final;   // returning final node..
    }

};

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        int n1, n2, tmp;
        Node *head1 = nullptr, *tail1 = nullptr;
        Node *head2 = nullptr, *tail2 = nullptr;
        string input1, input2;

        getline(cin, input1); // Read the entire line for the LL1 elements
        stringstream ss1(input1);
        while (ss1 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head1 == nullptr) {
                head1 = new_node;
                tail1 = new_node;
            } else {
                tail1->next = new_node;
                tail1 = new_node;
            }
        }

        getline(cin, input2); // Read the entire line for the LL2 elements
        stringstream ss2(input2);
        while (ss2 >> tmp) {
            Node *new_node = new Node(tmp);
            if (head2 == nullptr) {
                head2 = new_node;
                tail2 = new_node;
            } else {
                tail2->next = new_node;
                tail2 = new_node;
            }
        }

        Solution obj;
        Node *head = obj.sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
