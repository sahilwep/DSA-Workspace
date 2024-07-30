/*

// Get min at pop:

// Observations: 
    * First we have to insert all the given element into stack..
    * After then we have to print the minimum element in stack, while poping() out elements from stack..
        * Note when the minimum among all the element is poped out of the stack & still stack have element's left, we need to print the minimum among them, and so on...
        * this will keep repeating until all the element is not poped out..

// Intrusion: 
    * We will make a stack that will store the minimum element..
        * this will store minimum element by comparing the previous minimum & next minimum..

*/

#include <bits/stdc++.h>
using namespace std;

// Function & members signatures:
stack<int> _push(int arr[],int n);
void _getMinAtPop(stack<int>s);
stack<int> minStack;    // this stack will store the minimum element from the array in order...

//Function to push all the elements into the stack.
stack<int> _push(int arr[],int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        s.push(arr[i]); // at every iteration we will insert element into stack...
        // if minStack has no value we will start inserting values inside them...
        if(minStack.empty()){
            minStack.push(arr[i]);
        }else{
            minStack.push(min(minStack.top(), arr[i])); // storing minimum among the previous store value & value from stack...
        }
    }
    
    return s; // returning stack
}

//Function to print minimum value in stack each time while popping.
void _getMinAtPop(stack<int>s){
    // as we know that element we have same number of element in both the stack, that's why we are using first stack in iteration condition...
    while(!s.empty()){
        s.pop();    // poping out element from stack that is given in function paramenter..
        cout << minStack.top() << " ";  // printing the top element from stack...
        minStack.pop(); // at every iteration we will pop out the element from stack...
    }
}

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
        cin>>arr[i];
        stack<int>mys=_push(arr,n);
        _getMinAtPop(mys);

        cout<<endl;

    }
    return 0;
}
