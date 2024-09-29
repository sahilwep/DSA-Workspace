/*

//  Implement Queue using Linked List

//  Observations: 
    * We are given structure of Queue, & we have to implement push(), & pop() functions of queue..
    * Queue => FIFO

// Pictorial Observations:

        <- Deletions    [   |   |   |   |   |   |   |   ]      <- Insertion
                        front                       rear
                
                nodes chain directions []--->[]--->[]--->

// Intrusion:
    // pop():
        * we have to return value of front node.
        * If there is no node return -1
        * If there is node, front & rear refer to that single node only, so we have to delete & change both to null.
        * else for other cases, when we have multiple items, we just have to change front reference to front->next.
    // push():
        * we have to insert item in rear:
        * If there is no items, we have to make front & rear as that allocated item.
        * else, allocate node, change rear reference to rear->next.

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct QueueNode{
    int data;
    QueueNode *next;
    QueueNode(int a){
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    void push(int);
    int pop();
    MyQueue() {front = rear = NULL;}
};


/*
// Overview Of nodes:

        <- Deletions    [   |   |   |   |   |   |   |   ]      <- Insertion
                        front                       rear
                
                nodes chain directions []--->[]--->[]--->
*/

// Function to push an element into the queue.
void MyQueue:: push(int x){
    // Allocate temp node & insert values inside it.
    QueueNode *temp = new QueueNode(x);
    // If we don't have any value, we have to make temp as our first value.
    if(rear == NULL){
        // we will make our first value temp as front & rear
        rear = front = temp;
        return;
    }
    // Else when we have some values
    rear->next = temp;  // rear next will be our new element temp
    rear = temp;    // changing the rear reference as new temp.
}


// Function to pop front element from the queue.
int MyQueue :: pop(){
    // When there is no element in queue: return -1
    if(front == NULL || rear == NULL) return -1;
    
    // When there is single element only:
    if(front == rear){
        int temp = front->data;
        
        // Deleting single element: as front & rear is pointing to same reference, so we don't need to delete both of them, we can delete any of them, it will delete that allocated node.
        QueueNode *del1 = front;
        delete del1;
        
        // Changing Front & rear reference as null
        front = rear = NULL;
        
        return temp;
    }
    
    // Storing front value in temp variable that we have to return.
    int temp = front->data;
    // Making delete reference as front
    QueueNode *NodeWeHaveToDelete = front;
    front = front->next;    // changing the front reference as front next node
    delete NodeWeHaveToDelete;  // deleting that reference.
    
    return temp;
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
        if(QueryType==1)
        {
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

