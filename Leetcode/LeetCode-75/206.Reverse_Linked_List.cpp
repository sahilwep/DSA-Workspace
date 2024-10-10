/*

//  206. Reverse Linked List


//  Observations: 
    * We are given singly linked list, we need to reverse it.


// Example:

    Input: head = [1,2,3,4,5]
    Output: [5,4,3,2,1]


    Input: head = [1,2]
    Output: [2,1]


    Input: head = []
    Output: []

// Intrusion: 
    // Using stack: 
        * fill all the elements form LL to stack.
        * then move element from the LL.
        * This will make sure to store the element into reverse order.
        * TC: O(n)

    // By Changing the direction of linked list:

        * Initialize pointers:
            * We can use three pointer: prev, 

        We can implement the reversal of the linked list using an iterative approach:
            prev is initialized to null since the new tail will point to null.
            current is initialized to the head of list.

        * Iterate through the List: As long as current is not null:
            Store the next node(next = curr->next);
            reverse the next pointer to the current node to point to prev.
            Move prev and current one step forward.

        * Return the New head: Once all nodes have been processed, prev will point to the new head of the reversed list.


        * Example:  
                I/p:  [1] -> [3] -> [4] -> [7]
                  
                O/p:  [1] <- [3] <- [4] <- [7]

                Here's a step-by-step diagram in plain text for reversing a linked list with the logic you mentioned:


                        * Initial Linked List:

                                    
                                    [1] -> [3] -> [4] -> [7] -> null


                        * Step 1: Initial pointers


                                    prev: null          current: [1] -> [3] -> [4] -> [7] -> null

                            At this point, prev is null and current points to the first node [1].
                            

                        * Step 2: First iteration

                            Next step: Store next = current->next (3)
                            Reverse the link: current->next = prev (null)
                            Move the pointers:
                                prev = current (1)
                                current = next (3)


                                    prev: [1] <- null   current: [3] -> [4] -> [7] -> null

                            Pointers:
                                prev now points to [1]
                                current points to [3]
                                next was used to store [3]


                        * Step 3: Second iteration

                            Next step: Store next = current->next (4)
                            Reverse the link: current->next = prev (1)
                            Move the pointers:
                                prev = current (3)
                                current = next (4)


                                    prev: [3] <- [1] <- null   current: [4] -> [7] -> null


                            Pointers:
                                prev now points to [3] <- [1]
                                current points to [4]
                                next was used to store [4]

                        * Step 4: Third iteration

                            Next step: Store next = current->next (7)
                            Reverse the link: current->next = prev (3)
                            Move the pointers:
                                prev = current (4)
                                current = next (7)


                                    prev: [4] <- [3] <- [1] <- null   current: [7] -> null


                            Pointers:
                                prev now points to [4] <- [3] <- [1]
                                current points to [7]
                                next was used to store [7]

                        * Step 5: Fourth iteration

                            Next step: Store next = current->next (null)
                            Reverse the link: current->next = prev (4)
                            Move the pointers:
                                prev = current (7)
                                current = next (null)


                                    prev: [7] <- [4] <- [3] <- [1] <- null   current: null


                            Pointers:
                                prev now points to [7] <- [4] <- [3] <- [1]
                                current is null (end of list)
                                next is null (end of list)


                        * Final Reversed Linked List:

                                    [7] <- [4] <- [3] <- [1] <- null

                            At each step:
                                prev takes the place of the current node after reversal.
                                current moves to the next node using next to continue the iteration.
                                        



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
    // Reverse List Using stack:
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        else if(head->next == NULL){
            return head;
        }
        else if(head->next->next == NULL){
            int x = head->val;
            head->val = head->next->val;
            head->next->val = x;
            return head;
        }
        // Using stack to reverse the linked list:
        stack<int> s;

        ListNode *temp = head;
        while(temp != NULL){
            s.push(temp->val);
            temp = temp->next;
        }


        // moving value from stack to LL:
        ListNode *temp1 = head;
        while(!s.empty()){
            temp1->val = s.top();
            temp1 = temp1->next;
            s.pop();
        }

        return head;

    }
    // Reverse List Using O(1) space
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;

        ListNode *prev = NULL;
        ListNode *curr = head;
        ListNode *next;

        while(curr != NULL){
            // Temporary, we put the current->next reference in next variable.
            next = curr->next;

            // reversing the link:
            curr->next = prev;  // current-> next element will be previous.

            // move prev & current pointer froward:
            prev = curr;    // now, updating prev, prev pointer become current value, after 
            curr = next;    // after all the operations, making current again (curr->next) that we have stored in next.

        }

        // at last we have prev that will refer the last value of given list.
        return prev;
    }
};
