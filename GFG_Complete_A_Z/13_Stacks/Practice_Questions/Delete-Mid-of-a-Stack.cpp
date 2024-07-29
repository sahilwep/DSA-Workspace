/*
//  Delete Mid of a Stack


// Observations: 
    * We have to remove the middle element of stack, without disturbing the order of others elements.

// Iterative Solution: 
    * we can use temp stack & store n/2 elements in it, & remove the middle element & again restore it into the original stack.
    * TC: O(n)
    * SC: O(n)

// Recursive Solution: 
    * We will store n/2 size of stack into recursive call, when it's at middle we pop that element & restore the values from recursive calls...
    * TC: O(n)
    * SC: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Iterative Solution: 
    void deleteMid_(stack<int>& s, int n) {
        stack<int> temp;    // Creating the temp stack.
        // we only need to iterate till half of the element
        for(int i=0;i<=n/2;i++){    
            int x = s.top();
            s.pop();
            temp.push(x);
        }
        temp.pop();
        while(!temp.empty()){
            s.push(temp.top());
            temp.pop();
        }
    }
    // Recursive Solutions: 
    void deleteMid(stack<int> &s, int sizeOfStack){
        int mid = (sizeOfStack)/2 + 1;  // we need to the path of middle element..
        deleteMiddle(s, mid);   // calling recursive function that will perform all the work..

    }
    // function that will recursively call itself & remove the middle element..
    void deleteMiddle(stack<int> &s, int mid){
        // when middle become 1, means then only we will remove the middle element.
        if(mid == 1){
            s.pop();
            return;
        }
        int temp = s.top(); // creating temp to store stack top element in every recursive call.
        s.pop();    // removing to top element from stack at every recursive call.
        deleteMiddle(s, mid-1); // recursively call stack with mid-1, means we are decreasing the range, as we already iterate through the current...
        s.push(temp);   // when the recursive call return to parent call, this value push inside the stack..
    }
};


int main() {
    int t;
    cin >> t;

    while (t--) {
        int sizeOfStack;
        cin >> sizeOfStack;

        stack<int> myStack;

        for (int i = 0; i < sizeOfStack; i++) {
            int x;
            cin >> x;
            myStack.push(x);
        }

        Solution ob;
        ob.deleteMid(myStack, myStack.size());
        while (!myStack.empty()) {
            cout << myStack.top() << " ";
            myStack.pop();
        }
        cout << endl;
    }
    return 0;
}