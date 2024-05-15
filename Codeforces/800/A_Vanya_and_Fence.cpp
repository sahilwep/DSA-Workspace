/*
//  A. Vanya and Fence

̃


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
#define SQ(a) (a)*(a)



void solve(){
    int n, h;
    cin >> n >> h;
    int arr[n];
    arrInp;
    int res = 0;
    for(int i=0;i<n;i++){
        if(arr[i] <= h){
            res +=1;
        }
        else {
            while(arr[i] > h){
                arr[i] = arr[i] / 2;
                res += 2;
            }
        }
    }
    cout << res << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}