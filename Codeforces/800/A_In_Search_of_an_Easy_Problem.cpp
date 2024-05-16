/*
//  A. In Search of an Easy Problem


// Observations: 
    * if 1 -> hard, else easy

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
    int k;
    bool flag = false;
    for(int i=0;i<n;i++){
        cin >> k;
        if(k == 1) flag = true;
    }
    if(flag == true){
        cout << "HARD" << endl;
    }else {
        cout << "EASY" << endl;
    }
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}