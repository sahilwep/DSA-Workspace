/*

//  Dequeue Traversal

//  Observations: 
    *  We are given a queue, we need to traverse the queue, & print the element of queue.


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//Function to traverse the Deque and print the elements of it.
void printDeque(deque<int> Deq){
    for(auto i: Deq) cout << i << " ";
}    

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        deque<int> Deq;
        for(int i = 0; i < n; i++){
            int val;
            cin>>val;
            Deq.push_back(val);
        }
        printDeque(Deq);
        
    }
}