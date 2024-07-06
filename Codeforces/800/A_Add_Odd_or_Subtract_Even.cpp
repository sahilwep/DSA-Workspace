/*
//  A. Add Odd or Subtract Even


// Observations: 
    * In one move we can change a in following ways:
        * choose any positive odd integer x(x > 0) and replace a with a+x
        * choose any positive even integer y(y > 0) and replace a with a-y
    * You can perform as many such operations as we want...
    * we can choose same number x & y in different move...
    * We need to find the minimum number of operations required to obtain b from a

// Key observations: 
    * We can increment numbers with odd value..
    * And we can decrement it with even value..


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

void solve(){
    int a, b;
    cin >> a >> b;
    if(a == b){
        cout << 0 << endl;
        return;
    }
    // when we have to increment the value, we can increment it with odd numbers..
    if(b > a){  // when b is greater, means for a we can add only odd digits..
        int req = b - a;
        if(req % 2 != 0){ // when we get the required number as odd, only one number is needed..
            cout << 1 << endl;
        }else{  // else we need two numbers to make this possible
            cout << 2 << endl;
        }
        return;
    }

    // when we have to decrement the value, We can decrement it with even numbers..
    if(b < a){  // when b is lesser, means for a we can decrement only even numbers... 
        int req = a - b;
        if(req % 2 == 0){   // when we get the required number as even, only one numbers needed..
            cout << 1 << endl;
        }else{  // else we need two numbers to make this possible..
            cout << 2 << endl;
        }
        return;
    }
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}