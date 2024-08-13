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
        * 

    * Efficient Approach: 
        * we can perform this merging operations in linked list itself..
        * 



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
    Node* sortedMerge(Node* head1, Node* head2) {
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
