/*

//  Queue Reversal


//  Observations: 
    * We are given a queue of N element, the task is to reverse the queue.

// Example:

    Input:
    n = 6
    arr[n] = 4 3 1 10 2 6
    Output: 6 2 10 1 3 4
    Explanation: After reversing the given elements of the queue , the resultant queue will be 6 2 10 1 3 4.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;


class Solution{
public:
    queue<int> rev(queue<int> q){
        stack<int> s;
        while(!q.empty()){
            s.push(q.front());
            q.pop();
        }
        while(!s.empty()){
            q.push(s.top());
            s.pop();
        }
        return q;
    }
};


int main(){
    int test;
    cin>>test; 
    while(test--){
        queue<int> q; 
        int n, var; 
        cin>>n;
        while(n--){
            cin>>var; 
            q.push(var);
        }
        Solution ob;
        queue<int> a=ob.rev(q); 
        while(!a.empty()){
            cout<<a.front()<<" ";
            a.pop();
        }
        cout<<endl; 
    }
}