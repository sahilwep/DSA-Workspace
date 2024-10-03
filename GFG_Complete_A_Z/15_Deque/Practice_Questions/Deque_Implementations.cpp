/*

//  Deque Implementations: 

//  Observations: 
    * A deque is doubly ended queue that allowed enqueue & dequeue from both the end.
    * Implement all the functions.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

// Function to push element x to the back of the deque.
void push_back_pb(deque<int> &dq, int x) {
    dq.push_back(x);
}

// Function to pop element from back of the deque.
void pop_back_ppb(deque<int> &dq) {
    if (!dq.empty())  dq.pop_back();
    else return;
}

// Function to return element from front of the deque.
int front_dq(deque<int> &dq) {
    if (!dq.empty())  return dq.front();
    else return -1;
}

// Function to push element x to the front of the deque.
void push_front_pf(deque<int> &dq, int x) {
    dq.push_front(x);
}


int main() {

    int testcase;
    cin >> testcase;

    // declaring deque
    deque<int> dq;

    while (testcase--) {

        int queries;
        cin >> queries;

        while (queries--) {
            string s;
            cin >> s;

            // if query is to push back
            if (s == "pb") {
                int x;
                cin >> x;
                push_back_pb(dq, x);
                cout << dq.back() << endl;
            }

            // if query is to push front
            if (s == "pf") {
                int x;
                cin >> x;
                push_front_pf(dq, x);
                cout << dq.front() << endl;
            }

            // if query is to pop back
            if (s == "pp_b") {
                pop_back_ppb(dq);
                cout << dq.size() << endl;
            }

            // if query is to return front
            if (s == "f") {
                int x = front_dq(dq);
                cout << x << endl;
            }
        }
        dq.clear();
    }

    return 0;
}