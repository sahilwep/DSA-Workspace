/*
// Searching in linked list (Iterative & Recursive ) : 

    I/p : [10]-->[5]-->[20]-->[15]
    x : 20
    O/p : 3 (position of the nodes)

    I/p : [10]-->[15]
    x : 20
    O/p : -1 (not found)

    I/p : [3]-->[20]-->[5]
    x : 3
    O/p : 1

// Bruteforce method: 
    * start traversing from first index to end index: 
        * In between, if we found the value, return the index with using the counter.
    * Else return the -1 value.
    * TC : O(n)


*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};


void display(Node *head) {
    if (head == NULL) return;
    cout << head->data << " ";
    display(head->next);
}

int searchPos(Node *head, int value){
    int cnt = 1;
    Node *curr = head;
    while(curr != NULL){
        if(curr->data == value) {
            return cnt;
        }
        cnt++;
        curr = curr->next;
    }
    return -1;
}


int main() {
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);

    display(head);

    int value;
    cin >> value;

    cout << endl <<  searchPos(head, value);

}
