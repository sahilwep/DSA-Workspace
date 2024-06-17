/*
//  B. Xenia and Ringroad




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
#define arrInp for(int i=0;i<m;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);

void solve(){
    int n, m;
    cin >> n >> m;
    int arr[m];
    arrInp;
    int cnt = 1;
    for(int i=1, j=0;i<=n;i++){
        cnt++;  // counter
        if(j == m-1 && arr[j] == i) break; // condition when all the element of array is found..
        // condition to iterate in array
        if(i == arr[j]){
            j++;
        }
        // if(cnt == 10) break;
        // condition for circular iteration
        if(i == n){
            i = 0;
        }
    }
    cout << cnt << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}