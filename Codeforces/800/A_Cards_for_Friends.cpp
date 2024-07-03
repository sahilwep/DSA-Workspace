/*
//  A. Cards for Friends

// Observations: 
    * w = width, h = height, of paper..
    * sheet of paper of (w x h) size, which can be cut into pieces:
        * When w is even: (w/2)*h
        * when w is odd: w*(h/2)
    * If w & h are even, then we can choose any of these..
    * After cutting sheets of paper, we can increment it by 1.
    * we have to find that if we can cut the sheet at into n or more pieces...

// Intrusion: 
    * while every paper size is even we can cut the paper into half..
    * after every split, the papers become two...

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
    int w,h,n;
    cin >> w >> h >> n;
    int total = 1;
    // while papers size are even, we can cut & split into half...
    while(h % 2 == 0){
        total = total*2;
        h = h/2;
    }
    while(w % 2 == 0){
        total = total*2;
        w = w/2;
    }
    if(total >= n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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