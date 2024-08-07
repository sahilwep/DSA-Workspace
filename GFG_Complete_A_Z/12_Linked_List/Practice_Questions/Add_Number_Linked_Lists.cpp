/*

// Add Number Linked list: 
    * We are given two linked list, we have to perform sum operations, nodes by nodes, & return the newly allcoated linked list that contains solutions..

// Observations: 
    * we have to add a number from two linked list: 
        LL 1: 4 5
        LL 2: 3 4 5

            4 5
          3 4 5 + 
        ---------
         3  9  0

    * if we carefully observe, we are doing sum from left to right...
    * every time we are storing single digit & the remaining front value will become addon to the next sum operations...
    * In this scenario, we can use stack data structure..
        * first we store all the value in stack..
        * second we sum the result, & store it..
    * Once we are done with all the operations, we just have to return the allocated linked list that contains values of result, into it...

// Intrusion: 
    // Approach 1: using stack:
        * idea is to store all the values into the stack first...
            * we will use two stack that store the values..
            * Stack 1 : stores element of first list
            * stack 2 : stores element of second list
        * Once we are done with this, we will pop() value one by one from both the stack & sum up the result...
            * we have to take care of the double digits, when we are storing value in solutions..
            * when we have double digits: 
                *  we store the last value as remaining sum for next sum operations...
            * when we have single digits:
                * we can directly store the sum & make remaining '0'
        * We have to take care of edge cases like: 
            * when first stack is empty & second stack contains some values, & vice versa...
            * When both the stack is empty & we have value in remaining variable...
        
        * At last when we get our sum, we just have to allocate the values one by one into the linked list & return the head pointer of allocated nodes..

        * TC: O(n)
        * AC: O(n)
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList(){
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node* addTwoLists(Node* num1, Node* num2){
        // Initiallization of two stack to perform all the actions:
        stack<int> s1;
        stack<int> s2;


        // insertion of both the linked list values into the stack:
        // insertion of first list into first stack:
        int size1 = 0;
        Node *c1 = num1;
        while(c1 != NULL){
            size1++;
            s1.push(c1->data);
            c1 = c1->next;
        }
        // insertion of second list into second stack:
        int size2 = 0;
        Node *c2 = num2;
        while(c2 != NULL){
            size2++;
            s2.push(c2->data);
            c2 = c2->next;
        }


        // Now we pop() out all of the element one by one & sum up all the results...
        int size = max(size1, size2);   // we need to iterate to max size element, so we are getting the max size from it.
        int remaining = 0;  // use to store the remaining number when we have our value grater than 10...
        string res = "";    // we will use string store the result
        // iteration till max size of list:
        for(int i=0;i<size;i++){
            // when both that stacks have values in it.
            if(s1.empty() == 0 && s2.empty() == 0){
                int v1 = s1.top();  // storing the top element from fist stack
                s1.pop();   // popping the top element from first stack
                int v2 = s2.top();  // storing the top element from first stack
                s2.pop();   // popping the top element from second stack

                // as we have to store the single digit, so use temp to store the sum & then we can filter out what we have to store & what we have to store in remaining variable.
                int temp = v1 + v2 + remaining;
                // when we have value grater than 9, means we have double digits..
                if(temp > 9){
                    remaining = temp / 10;  // storing remaining the first value of the sum
                    res += to_string(temp % 10);    // storing the last value in solution..
                }
                // when we have single digits..
                else{
                    remaining = 0;
                    res += to_string(temp);
                }
            }
            // when second stack is empty & first stack contains some values: 
            else if(s1.empty() == 1 && s2.empty() == 0){
                int v1 = s2.top() + remaining;
                s2.pop();
                // when sum are in double digits...
                if(v1 > 9){
                    remaining = v1 / 10;
                    res += to_string(v1 % 10);
                }
                // when sum are in single digits...
                else{
                    res += to_string(v1);
                    remaining = 0;
                }
            }
            // when first stack is empty & second stack contains some values:
            else if(s2.empty() == 1 && s1.empty() == 0){
                int v2 = s1.top() + remaining;
                s1.pop();
                // when sum are in double digits...
                if(v2 > 9){
                    remaining = v2 / 10;
                    res += to_string(v2 % 10);
                }
                // when sum are in single digits...
                else{
                    res += to_string(v2);
                    remaining = 0;
                }
            }
            // case when both the stack is empty, but we have some value leftover in remaining variable...
            if(s1.empty() == 1 && s2.empty() == 1 && remaining > 0 ){
                res += to_string(remaining);    // storing it into the solutions...
            }
        }

        // Now we have done all the operations we just have to create a linked list & store all the values in that..
        // allocation of nodes: we will allocate nodes at beginning of linked list, because TC: O(1)
        Node *head = NULL;  // allocation of nodes
        for(int i=0;i<res.size();i++){
            // allocation of nodes: 
            head = insertBeg(head, int(res[i] - '0'));  // function call for every character of string..
        }
        return head;    // at last we return head to the parent function call..
    }

    // Allocations of Nodes at beginning: TC: O(1)
    Node *insertBeg(Node *head, int x){
        Node *temp = new Node(x);
        if(head == NULL){
            return temp;
        }
        temp->next = head;
        return temp;
    }

};


int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
    }
    return 0;
}