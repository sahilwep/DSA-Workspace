/*

//  Implement Queue using array

//  Observations: 
    * Implement queue using Array.
    * Push(x) -> insert element into queue
    * pop() -> removing element from queue


// Example: 
    Input: Q = 5, Queries = 1 2 1 3 2 1 4 2
    Output: 2 3
        Explanation:
        In the first test case for query 
        1 2 the queue will be {2}
        1 3 the queue will be {2 3}
        2   poped element will be 2 the 
            queue will be {3}
        1 4 the queue will be {3 4}
        2   poped element will be 3 

    * Note: Here 1 -> push, 2 -> pop


// Queue:
    * Queue follow FIFO

*/

#include<bits/stdc++.h>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;
};

class MyQueue {
private:
    int arr[100005];
    int front;
    int rear;

public :
    MyQueue(){front=0;rear=0;}
    void push(int);
    int pop();
};

void MyQueue :: push(int x){
    if(rear == 100005) return;
    else{
        arr[rear] = x;  // insert at end;
        rear++;
    }
}

//Function to pop an element from queue and return that element.
int MyQueue :: pop(){
    if(front == rear){
        return -1;
    }
    else{
        int val = arr[front];
        front++;
        return val;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){
        MyQueue *sq = new MyQueue();

        int Q;
        cin>>Q;
        while(Q--){
            int QueryType=0;
            cin>>QueryType;
            if(QueryType==1){
                int a;
                cin>>a;
                sq->push(a);
            }else if(QueryType==2){
                cout<<sq->pop()<<" ";

            }
        }
        cout<<endl;
    }
}
