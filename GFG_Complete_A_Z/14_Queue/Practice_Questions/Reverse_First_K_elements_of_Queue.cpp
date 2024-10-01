/*

//  Reverse First K elements of Queue

//  Observations: 
    * we are given queue, & integer k, we have to reverse the first k numbers of queue.

// Example:

    Input:
    5 3
    1 2 3 4 5
    Output: 
    3 2 1 4 5
    Explanation: 
    After reversing the given
    input from the 3rd position the resultant
    output will be 3 2 1 4 5.



// Queue Insertion & Deletions: 
    front[ 1 2 3 4 5 ] back

    Insertion at back: push() ->  back()
    Deletions from front: pop() ->  front()


// Intrusion: 
    * Example: k = 3
        Input: 1 2 3 4 5
        Output: 3 2 1 4 5
    
    * we are reversing first 3 element of queue:
    * First we will store the first k elements into the stack: As stack use LIFO when we store element from stack to queue, again this will store in reversal order.
    * Then we will create a temp queue, & store the elements into temp queue from stack: as we are inserting elements from stack to queue, this will store the values in reversal order.
    * Then we will insert leftover elements from the first queue to temp queue : then at end we will store teh leftover element into the temp from the first queue.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution{
public:
    queue<int> modifyQueue(queue<int> q, int k) {
            // Inserting first k values into stack:
            stack<int> s;
            while(k > 0){
                s.push(q.front());
                q.pop();
                k--;
            }
            // making new queue to insert the first stack values:
            queue<int> temp;

            while(!s.empty()){
                temp.push(s.top());
                s.pop();
            }
            // After that inserting element from first queue to temp queue:
            while(!q.empty()){
                temp.push(q.front());
                q.pop();
            }

            return temp;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        Solution ob;
        queue<int> ans = ob.modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}