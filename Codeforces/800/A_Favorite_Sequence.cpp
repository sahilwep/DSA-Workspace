/*
//  A. Favorite Sequence

// Observations: 
    * We will have to use two pointers..
    * Straightforward question..


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
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    int ptr1 = 0, ptr2 = n-1;
    while(ptr1 < ptr2){
        cout << arr[ptr1++] << " "  << arr[ptr2--] << " ";
    }
    // edge case, when we have odd numbers of elements..
    if(n % 2 != 0){
        cout << arr[ptr1] << " ";
    }
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}