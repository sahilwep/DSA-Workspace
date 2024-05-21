/*
//  A. Amusing Joke




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
    string gName, hName, pile;
    cin >> gName >> hName >> pile;
    int hash[91] = {0};
    for(int i=0;i<gName.size();i++){
        hash[int(gName[i])]++;
    }
    for(int i=0;i<hName.size();i++){
        hash[int(hName[i])]++;
    }
    for(int i=0;i<pile.size();i++){
        hash[int(pile[i])]--;
    }
    for(int i=65;i<91;i++){
        if(hash[i] != 0){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}