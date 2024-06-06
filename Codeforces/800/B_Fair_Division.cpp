/*
//  B. Fair Division


// Observations: 
    * We can hash the frequency of 1 & 2 & by simply checking the constrains, we output the result..



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
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    int alice = 0, bob = 0;
    int hash[3] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]++;
    }

    // cout << hash[1] << " " << hash[2] << endl;
    if(hash[1] == 1 && hash[2] == 1) cout << "NO" << endl;
    // if 2 frequency is 0
    else if(hash[2] == 0 && hash[1] > 0){
        // if 1 is in even in number we say "YES" , else "NO"
        if(hash[1] % 2 != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    // if 1 frequency is 0
    else if(hash[1] == 0 && hash[2] > 0){
        if(hash[2]  % 2 != 0) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    else if(hash[1] == hash[2]){
        if(hash[1] % 2 == 0)  cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    else if(hash[1] != hash[2]){
        if(hash[1] % 2 != 0) cout << "NO" << endl;
        else if(hash[2] % 2 != 0 && hash[1] % 2 == 0) cout << "YES" << endl;
        else if(hash[2] % 2 == 0 && hash[1] % 2 == 0) cout << "YES" << endl;

    }
    else cout << "YES" << endl;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}