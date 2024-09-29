/*

//  Operations on Queue

//  Observations: 
    * We are given integer of Q quires, the task is to perform operations on queue according to the query.
    * Queue: Follows FIFO
        * Operations: 
            * Enque() remove element from front
            * dequeue() insert element in last

// Intrusion:
    * We just have to write the given functions..

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

class Solution{
public:
    //Function to push an element in queue.
    void enqueue(queue<int> &q,int x){
        q.push(x);
    }
     
    //Function to remove front element from queue.
    void dequeue(queue<int> &q){
        q.pop();
    }
    
    //Function to find the front element of queue.
    int front(queue<int> &q){
        return q.front();
    }
    
    //Function to find an element in the queue.
    string find(queue<int> q, int x){

        while(!q.empty()){
            if(q.front() == x) return "Yes";
            q.pop();
        }

        return "No";
    }
};


int main() {

	int t;
	cin>>t;
	while(t--){
	    queue<int> s;
	    int q;
	    cin>>q;
	    Solution ob;
	    while(q--){
	        char ch;
	        cin>>ch;
	        
	        if(ch=='i'){
	            int x;
	            cin>>x;
	            ob.enqueue(s,x);
	        }
	        else if(ch=='r'){
	            ob.dequeue(s);
	        }
	        else if(ch=='h'){
	            cout << ob.front(s) << endl;
	        }
	        else if(ch=='f'){
	            int x;
	            cin>>x;
	            cout << ob.find(s,x) << endl;
	        }
	        
	    }
	}

	return 0;
}