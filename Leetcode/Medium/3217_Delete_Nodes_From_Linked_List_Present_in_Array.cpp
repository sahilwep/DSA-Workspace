/*
//  3217. Delete Nodes From Linked List Present in Array


Example 1:
Input: nums = [1,2,3], head = [1,2,3,4,5]
Output: [4,5]
Explanation:    Remove the nodes with values 1, 2, and 3.

Example 2:
Input: nums = [1], head = [1,2,1,2,1,2]
Output: [2,2,2]
Explanation:    Remove the nodes with value 1.


Example 3:
Input: nums = [5], head = [1,2,3,4]
Output: [1,2,3,4]
Explanation:    No node has value 5.

// Observations: 
    * We are using unordered set..
        * First we will store all the elements of nums into the set..
    * we will create dummy node having extra node before the head, because we have to start checking from head, this is edge case..
    * now we will start iterating the linked list till null
    * we will use count function that will check node element is present in the array or not...
    * If it's present, we will delete that node..
    * else we will iterate to the next..
    * unordered_set count function will take O(1) avg time complexity...

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Node
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x, next(next) {}
};

// Functions:
ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> valuesToRemove(nums.begin(), nums.end());
    
    // Create a dummy node to simplify edge cases
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* current = dummy;
    
    // Iterate through the linked list
    while (current->next != nullptr) {
        if (valuesToRemove.count(current->next->val)) {
            // Remove the node
            ListNode* nodeToDelete = current->next;
            current->next = current->next->next;
            delete nodeToDelete; // free the memory of the removed node
        } else {
            // Move to the next node
            current = current->next;
        }
    }
    
    // Get the new head of the linked list
    ListNode* newHead = dummy->next;    // because the first node contains (0), as we use for edge case..
    delete dummy; // free the memory of the dummy node
    return newHead;
}

// Function to print the linked list
void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    // Create the linked list [1,2,3,4,5]
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Create the vector nums = [1,2,3]
    vector<int> nums = {1, 2, 3};

    // Remove elements from the linked list
    ListNode* newHead = modifiedList(nums, head);

    // Print the modified linked list
    printList(newHead);

    // Clean up the remaining nodes
    while (newHead != nullptr) {
        ListNode* temp = newHead;
        newHead = newHead->next;
        delete temp;
    }

    return 0;
}
