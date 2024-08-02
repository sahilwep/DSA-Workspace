/*

// Identical Linked list: 

// Observations: 
    * We are given two linked list, we have to compare it if they are identical or not?

// Intrusion: 
    * We can iterate over both the linked list if any of these value are not same, we can say they are not same..
    * Also we have to check the size of both the linked list...
    * Edge case:    
        * when we have different size of linked list & both are same at some extent..
        * Example:  
              LL1 = [1] [2] [3] [4] [5]
              LL2 = [1] [2] [3] [4] [5] [6] [7] [8]
        * Here in this case we have to explicitly handel the node location whether both are ended or not?


// Time complexity: O(n)

*/

#include <bits/stdc++.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Function to check if both the linked list are identical or not?
bool areIdentical(struct Node *head1, struct Node *head2){
    Node *curr = head1;
    while(head1 != NULL &&  head2 != NULL){
        // compare if we have distinct value, we immediately return false..
        if(head1->data != head2->data) return 0;
        // changing the reference after every iterations..
        // increment both the linked list nodes...
        head1 = head1->next;
        head2 = head2->next;
    }
    // edge case: we are checking both the node, whether they have finished or not, if they were same...
    if(head1 == NULL && head2 == NULL){
        return 1;   // return true
    }else{
        return 0;   // else return false...
    }

}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n1, n2, tmp, d1, d2;
        struct Node *head1 = NULL, *tail1 = NULL;
        struct Node *head2 = NULL, *tail2 = NULL;
        cin >> n1;
        cin >> d1;
        head1 = new Node(d1);
        tail1 = head1;
        while (n1-- > 1) {
            cin >> tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin >> n2;
        cin >> d2;
        head2 = new Node(d2);
        tail2 = head2;
        while (n2-- > 1) {
            cin >> tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }

        areIdentical(head1, head2) ? cout << "true" << endl : cout << "false" << endl;
    }
    return 0;
}
