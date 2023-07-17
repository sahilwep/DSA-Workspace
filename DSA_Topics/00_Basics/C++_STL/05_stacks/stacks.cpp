/*
// stacks :
    * Stack is a type of container adaptor with LIFO(Last in first out), type of working, where a new element is added at one end (top) and an element is removed from that end only.
    * Stack uses an encapsulated object of either vector or deque(by default) or list(sequential container class) as it's underlying container, providing a specific set of member function to access its elements.
    * LIFO : Last in first out
        * eg : 
              push 1        | 5  |<-------- last value in, will remove firs.
              push 4        | 2  |
              push 2        | 4  |
              push 5        | 1  |
            stack :         |____|
    * In stack indexing address is not allowed : 
    * There are only 3 action that are allowed.
        * push()
        * pop()
        * top()
        
    * Stack is a liner data structure in which elements can be inserted and deleted only from one side of the list, called top. 
    * A stack follow LIFO pipeline

*/

#include <bits/stdc++.h>
using namespace std;

void explainStack(){

    stack<int> st;
    st.push(2); //  {2}
    st.push(5); //  {2, 5}
    st.push(3); //  {3, 2, 5}
    st.push(3); //  {3, 3, 2, 5}
    st.push(4); //  {4, 3, 3, 2, 5}
    st.push(8); //  {8, 4, 3, 3, 2, 5}

    cout << st.top();   // print the top value i.e 8, "** st[2] is invalid, because indexing is not allowed." 

    st.pop();   // st looks like {4, 3, 3, 2, 5}

    cout << endl <<  st.top();   // 4

    cout << endl << st.size();  // 5

    cout << endl << st.empty();     // return 0 || 1, true or false.

    stack<int> st1, st2;
    st1.swap(st2);

}

int main(void){

    explainStack();

    return 0;
}

// TC : O(1), everything happens at constant time.

