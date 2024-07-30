/*

// Operations on Stack:

*/

#include <bits/stdc++.h>
using namespace std;

// Push function: 
void insert(stack<int> &s,int x){
    s.push(x);
}

// Pop function:
void remove(stack<int> &s){
    s.pop();
}

// Function to print top of stack:
void headOf_Stack(stack<int> &st){
    if(!st.empty()) cout<<st.top()<<endl;
    else cout<<"No Elements in the stack"<<endl;
}

//Function to search an element in the stack:
bool find(stack<int> st, int val){
    while(!st.empty()){
        if(st.top() == val) return 1;
        st.pop();
    }
    return 0;
}


int main() {
    int T;
    cin>>T;
    while(T--){
        stack<int> s;
        int q;
        cin>>q;
        while(q--){
            char ch;
            cin>>ch;

            if(ch=='i'){
                int x;
                cin>>x;

                insert(s,x);
            }
            else if(ch=='r'){
                remove(s);
            }else if(ch=='h'){
                headOf_Stack(s);
            }
            else if(ch=='f'){
                int x;
                cin>>x;
                if(find(s,x))
                cout << "Yes";
                else cout << "No";
                cout << endl;
            }

        }
    }
    return 0;
}