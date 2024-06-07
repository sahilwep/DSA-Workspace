/*
//  B. Two Arrays And Swaps

// Observations: 
    * We have to swap k times two array in such a way, so that we can have maximum sum in first array..
    * First we will sort the array..
    * Second we can use two pointer & swap the maximum elements..


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
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
    int n, k;
    cin >> n >> k;
    int a[n], b[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    if(k == 0){
        int res = 0;
        for(auto i : a) res += i;
        cout << res << endl;
        return;
    }
    sort(a, a+n);
    sort(b, b+n);

    int ptr1 = 0; // for a
    int ptr2 = n-1; // for b
    int i = 0;
    while(ptr1 <= n-1 && k > 0){
        if(a[ptr1] > b[ptr2]){
            ptr1++;
        }
        else if(a[ptr1] < b[ptr2]){
            a[ptr1] = b[ptr2];
            ptr2--;
            ptr1++;
            k--;
        }
        else if(a[ptr1] == b[ptr2]){
            ptr1++;
            ptr2--;
        }
    }
    int res = 0;
    for(auto i : a) res += i;
    cout << res << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}