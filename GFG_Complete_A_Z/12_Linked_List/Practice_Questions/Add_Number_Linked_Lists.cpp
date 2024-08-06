/*

// Add Number Linked list: 


// Observations: 
    * we have to add a number from two linked list: 
        LL 1: 4 5
        LL 2: 3 4 5

            4 5
          3 4 5 + 
        ---------
         3  9  0

    * We have to return the result in linked list...

// Intrusion: 
    // Approach 1: using stack or array data structure:
        * We can use stack to perform all of this operations...
        * We will perform all of of the operations & then we will return the result of it in linked list...
        * First use stack to store all the value of linked list..
        * Second we can pop() out values one by one & sum up the result.
        * Lastly we will return all the result in linked list...


            4 5
          3 4 5 + 
        ---------


        (0 + 0) * 10 0





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
        stack<int> s1;
        stack<int> s2;
        // insertion of both the linked list values into the stack:
        int size1 = 0;
        Node *c1 = num1;
        while(c1 != NULL){
            size1++;
            s1.push(c1->data);
            c1 = c1->next;
        }

        int size2 = 0;
        Node *c2 = num2;
        while(c2 != NULL){
            size2++;
            s2.push(c2->data);
            c2 = c2->next;
        }

        // Now we pop() out all of the element one by one & sum up all the results...
        int size = max(size1, size2);   // we need to iterate to max size element, so we are getting the max size.
        int remaining = 0;
        int solu = 0;
        string res = "";
        for(int i=0;i<size;i++){
            // When we have values in both the stack...
            if(s1.empty() == 0 && s2.empty() == 0){
                int v1 = s1.top();
                s1.pop();
                int v2 = s2.top();
                s2.pop();

                int temp = v1 + v2 + remaining;
                if(temp > 9){
                    remaining = temp % 10;
                    temp = temp / 10;
                    solu += temp;
                    res += to_string(temp);
                }else{
                    remaining = 0;
                    solu += temp;
                    res += to_string(temp);
                }
            }
            // when second stack is empty & first stack contains some values: 
            else if(s1.empty() == 1 && s2.empty() == 0){
                int v1 = s2.top() + remaining;
                s2.pop();
                // when the sum of remaining & current values become grater than 9, means single digit
                if(v1 > 9){
                    remaining = v1 % 10;
                    v1 = v1 / 10;
                    solu += v1;
                    res += to_string(v1);
                }else{
                    solu += v1;
                    res += to_string(v1);
                    remaining = 0;
                }
            }
            // when first stack is empty & second stack contains some values: 
            else if(s2.empty() == 1 && s1.empty() == 0){
                int v2 = s1.top() + remaining;
                s1.pop();
                // when the sum of remaining & current values become grater than 9, means single digit
                if(v2 > 9){
                    remaining = v2 % 10;
                    v2 = v2 / 10;
                    solu += v2;
                    res += to_string(v2);
                }else{
                    solu += v2;
                    res += to_string(v2);
                    remaining = 0;
                }
            }
        }
        reverse(res.begin(), res.end());
        cout << "solu: " << solu << " & " << res <<  endl;

        return NULL;
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