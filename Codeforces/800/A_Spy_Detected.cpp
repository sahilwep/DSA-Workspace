/*
//  A. Spy Detected!




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
    int n;
    cin >> n;
    int arr[n];
    arrInp;

    int same = 0;
    // finding the same element
    for(int i=1;i<n;i++){
        if(arr[i] == arr[i-1]){
            same = i;
            break;
        }
    }
    // finding the unique element
    for(int i=0;i<n;i++){
        if(arr[i] != arr[same]){
            same = i;
            break;
        }
    }
    cout << same+1 << "\n";
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}