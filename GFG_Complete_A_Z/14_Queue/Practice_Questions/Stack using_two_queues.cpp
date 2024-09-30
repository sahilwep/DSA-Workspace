/*

//  Stack using two queues

//  Observations: 
    * Implement stack using two given queue q1 & q2

           Insertions-> [ | | | | | ] -> Deletions              -> Insertion [ | | | | | ] -> Deletions
                                            q1                                                  q2
                            

// Intrusion: 
    * We are having two queue:
        * we will insert element in one queue, whenever we have push Operations...
        * When we have pop operations, we will insert all the element from first queue to second queue till the second last element.
        * Then again we will reinsert all the element into the first queue.
    * Example: 
         q1 =  [4, 2, 3],  q1 = []   

         stk.push(10) -> q1[10, 4, 2, 3]
         stk.push(7)  -> q1[7, 10, 4, 2, 3]

         stk.pop() -> we will remove last element by, inserting all the element from first queue to second queue except the last element that we recently inserted in first queue.
                      Now, we will move all the element from second queue to first queue, & return the last element from the first queue.


// NOTE: Insertions from back & deletions from front in queue.

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


class QueueStack{
private:
    queue<int> q1;  // insertion of element into first queue.
    queue<int> q2;  // we will take this to remove the last element of queue.
public:
    //Function to push an element into stack using two queues.
    void push(int x){
        q1.push(x);
    }
    //Function to pop an element from stack using two queues. 
    int pop(){
        // When first queue is empty we will return 
        if(q1.empty()){
            return -1;
        }
        // Now transfer all the element from first queue to the second queue till second last element.
        while(q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }

        // storing the last element.    
        int res = q1.front();   
        q1.pop();   // removing last element.

        // Now transferring all the element from second to first queue.
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }

        return res; // returning the last element.
    }
};


int main(){
    int T;
    cin>>T;
    while(T--){
        QueueStack *qs = new QueueStack();

        int Q;
        cin>>Q;
        while(Q--){
            int QueryType=0;
            cin>>QueryType;
            if(QueryType==1){
                int a;
                cin>>a;
                qs->push(a);
            }
            else if(QueryType==2){
                cout<<qs->pop()<<" ";
            }
        }
        cout<<endl;
    }
}