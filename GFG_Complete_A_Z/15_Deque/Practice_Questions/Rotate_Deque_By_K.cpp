/*

//  Rotate Deque By K

//  Observations: 
    * We are given a deque, & an integer k, we need to rotate it by k.


// Example:

    Input:
    6
    1 2 3 4 5 6
    1 2

    Output: 
    5 6 1 2 3 4 

    Explanation: 
    The dequeue is 1 2 3 4 5 6. 
    The query type is 1 and k is 2. So, we 
    need to right rotate dequeue by 2 times. 
    In 1 right rotation we get 6 1 2 3 4 5. 
    In another we get 5 6 1 2 3 4.


    Input: 
    6
    1 2 3 4 5 6 
    2 2 

    Output: 
    3 4 5 6 1 2 

    Explanation: 
    The dequeue is 1 2 3 4 5 6. 
    The query type is 2 and k is 2. So, we 
    need to left rotate dequeue by 2 times. 
    In 1 left rotation we get 2 3 4 5 6 1. 
    In another we get 3 4 5 6 1 2.


// IntrusioN:
    * Right rotate: removing element from back inserting in back
    * Left rotate: 


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//Function to rotate deque by k places in anti-clockwise direction.
void left_Rotate_Deq_ByK(deque<int> &deq, int n, int k){
    // left rotate means, counter clockwise, front element goes into last.
    k = k % n;
    while(k > 0){
        int x = deq.front();
        deq.pop_front();
        deq.push_back(x);
        k--;
    }
}

//Function to rotate deque by k places in clockwise direction.
void right_Rotate_Deq_ByK(deque<int> &deq, int n, int k){
    // right rotate means clockwise, last element comes in first
    k = k % n;
    while(k > 0){
        int x = deq.back();
        deq.pop_back();
        deq.push_front(x);
        k--;
    }
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        
        deque<int> deq;
        for(int i = 1; i <= n; i++){
            int val;
            cin>>val;
            deq.push_back(val);
            
        }
        int rotateQuery, k;
        cin>>rotateQuery>>k;
        
        
        
        if(rotateQuery == 1) right_Rotate_Deq_ByK(deq, n, k);    
        else left_Rotate_Deq_ByK(deq, n, k);
        
        
        for(auto itr = deq.begin(); itr != deq.end(); itr++) cout << *itr << " ";
        cout << endl;
    }
    return 0;
}