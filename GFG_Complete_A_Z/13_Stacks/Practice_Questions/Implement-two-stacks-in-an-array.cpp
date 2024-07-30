/*

//  Implement two stacks in an array

// Observations: 
    * we need to implement 2 stacks in one array efficiently, we need to implement 4 method
        * Two stack: initialize the data structure and variable to be used to implement 2 stack in one array.
        * push1: pushes element into first stack.
        * push2: pushes element into second stack.
        * pos1: remove element from first stack & return it, if the stack is empty it should return -1
        * pos2: remove element from second stack & return it, if the stack is empty it should return -1


// Intrusion: 
    * As constrains is 100 for the size of an array:
    * We can implement first stack in from beginning of array
    * and second stack from end of array..
    * first position of stack1: 0
    * first position of stack2: 100

*/

#include<bits/stdc++.h>
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


class twoStacks {
  public:
    int *arr;
    int top1;
    int top2;
 
    twoStacks(){
        arr = new int[100]; // allocation of memory at runtime
        top1 = -1;  // assigning the pointer for first stack
        top2 = 100; // assigning the pointer for second stack
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        arr[++top1] = x;
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        arr[--top2] = x;
    }

    // Function to remove an element from top of the stack1.
    int pop1() {
        if(top1 == -1) return -1;
        else{
            return arr[top1--];
        }
    }

    // Function to remove an element from top of the stack2.
    int pop2() {
        if(top2 == 100) return -1;
        else{
            return arr[top2++];
        }
    }
};



int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }
        cout << endl;
    }
}