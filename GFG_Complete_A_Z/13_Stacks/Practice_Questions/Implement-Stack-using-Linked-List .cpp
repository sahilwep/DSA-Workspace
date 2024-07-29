/*

// Implement stack using linked list:


*/

#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;
    StackNode(int a) {
        data = a;
        next = NULL;
    }
};

class MyStack {
  private:
    StackNode *top;
  public:
    // push operation:
    void push(int x) {
        StackNode *node = new StackNode(x); // node allocation
        // if top is null return node as new top
        if(top == NULL){
            top = node; // assigning node to top
        }
        else{
            // attaching node with top, by node->next = top
            node->next = top;
            top = node; // at last making node as new top
        }
    }
    // pop operation:
    int pop() {
        if(top == NULL) return -1;
        int tempData = top->data;   // storing values inside temp
        StackNode *temp = top;  // storing top reference..
        top = top->next;    // changing top reference to top->next
        delete temp;    // deleting the top reference that we have stored
        return tempData;    // at last we return the tempData value.
    }

    // constructor that will allocate memory & value NULL
    MyStack() { top = NULL; }
};


int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        delete sq;
    }
}