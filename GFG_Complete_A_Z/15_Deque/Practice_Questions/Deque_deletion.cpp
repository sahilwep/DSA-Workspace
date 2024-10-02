/*

//  Deque deletion

//  Observations: 
    * We are given deque of size N, we have to complete the given functions:
    * eraseAt(x): In this function element is being removed at certain position.
    * eraseInRange(start, end): erase the element from range, start(inclusive), end(exclusive)
    * eraseAll(): erase all the element of dequeue:



// IntrusioN:
    * eraseAt(x): we will use stack to store the first x element:
    * eraseInRange(start, end): same, here we will also use stack to store the first start element, & last end element into stack, & remove it..

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

//Function to erase the element from specified position X in deque.
void eraseAt(deque <int> &deq, int X){
    if(X > deq.size()) return;

    // We will use stack to store the first X element:
    stack<int> s;
    while(X > 0){
        s.push(deq.front());
        deq.pop_front();
        X--;
    }

    // We are at X position, so we will remove that element:
    deq.pop_front();
    
    // Now Inserting back all the element from stack s to deq:
    while(!s.empty()){
        deq.push_front(s.top());
        s.pop();
    }
}

//Function to erase the elements in range start (inclusive), end (exclusive).
void eraseInRange(deque<int> &deq, int start, int end){

    // storing first Start element into first stack:
    int n = deq.size();
    stack<int> s1;
    for(int i=0;i<start;i++){
        s1.push(deq.front());
        deq.pop_front();
    }

    // Storing last start element into second stack:
    stack<int> s2;
    for(int i=n;i>end;i--){
        s2.push(deq.back());
        deq.pop_back();
    }

    // Empty the current queue:
    while(!deq.empty()){
        deq.pop_back();
        if(!deq.empty()){
            deq.pop_front();
        }
    }

    // Now Inserting back all the values from stack to deque:
    while (!s1.empty()){
        deq.push_front(s1.top());
        s1.pop();
    }

    while (!s2.empty()){
        deq.push_back(s2.top());
        s2.pop();
    }

}

//Function to erase all the elements in the deque.
void eraseAll(deque<int> &deq){
    while(!deq.empty()){
        deq.pop_back();
        if(!deq.empty()) deq.pop_front();
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
        
        int eraseQuery;
        cin>>eraseQuery;
        
        if(eraseQuery == 1){
            int pos;
            cin>>pos;
            eraseAt(deq, pos);
        }
        else if(eraseQuery == 2){
            int start, end;
            cin>>start>>end;
            eraseInRange(deq, start, end);
        }
        else{
            eraseAll(deq);
            
        }
        
        
        if(deq.empty())
            cout << "Empty";
        else
            {for(auto itr = deq.begin(); itr != deq.end(); itr++)
                cout << *itr << " ";}
        cout << endl;
    }
    return 0;
}