/*

//  2095. Delete the Middle Node of a Linked List

//  Observations: 
    * We are given a head of singly linked list, & we need to delete the middle element.
    * The middle node of linked list of size 'n' is the '[n/2]th' node form the start, using 0 based indexing, 
    * where[x] is denoted as largest integer less or equal to x


// Example:

    Input: head = [1,2,3,4]
    Output: [1,2,4]
    Explanation:
        The above figure represents the given linked list.
        For n = 4, node 2 with value 3 is the middle node, which is marked in red.


    Input: head = [2,1]
    Output: [2]
    Explanation:
        The above figure represents the given linked list.
        For n = 2, node 1 with value 1 is the middle node, which is marked in red.
        Node 0 with value 2 is the only node remaining after removing node 1.

 

// Intrusion: 
    * Iterative removal:
        * iterate till the n/2 & remove that element.

    * Example:

            [1] -> [3] -> [4] -> [7] -> [1] -> [2] - [6]
                                  |
                                middle

                [1] -> [3] -> [4] -> [1] -> [2] - [6]

    * First we need to know the size of the linked list: 
    * then after getting the size, we can remove the middle element.
    * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Node Structure:
struct ListNode{
    int val;
    ListNode *next;
    ListNode(){
        val = 0;
        next = nullptr;
    }
    ListNode(int x){
        val = x;
        next = nullptr;
    }
    ListNode(int x, ListNode * Node){
        val = x;
        next = Node;
    }
};



class Solution {
public:
    int sizeLL(ListNode *head){
        if(head == NULL) return 0;
        if(head->next == NULL) return 1;
        int cnt = 0;
        ListNode *temp = head;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
    // Function to delete the middle element.
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL) return NULL;   // when there is no element in linked list, return NULL.
        // when we have single element: delete that element & return null
        else if(head->next == NULL){
            delete head;
            return NULL;
        }
        // when we have 2 element in our LL: delete the last element
        else if(head->next->next == NULL){
            ListNode *temp  = head->next;   // storing the reference of deleting node.
            delete temp;    // deleting that node.
            head->next = NULL;  // making head->next reference as NULL
            return head;        // return head.
        }
        // rest of the cases:
        int n = sizeLL(head);
        n = n / 2;  // we need to iterate till half.
        ListNode *temp = head;

        // we need our pointer just before the middle, so that we can delete the middle element.
        while(n > 1){
            temp = temp->next;
            n--;
        }

        ListNode *delNode = temp->next; // value that we have to delete
        temp->next = temp->next->next;   // Connecting temp next node with temp next next node.

        delete delNode; // delete that middle element.

        return head;    // return head reference.
    }
};