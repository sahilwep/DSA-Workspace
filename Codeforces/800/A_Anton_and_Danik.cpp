/*
//  A. Anton and Danik




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
    string s;
    int n;
    cin >> n;
    cin >> s;
    int cntA = 0;
    int cntD = 0;
    for(int i=0;i<n;i++){
        if(s[i] == 'A') cntA++;
        else if(s[i] == 'D') cntD++;
    }
    
    if(cntA > cntD) cout << "Anton" << endl;
    else if(cntA < cntD) cout << "Danik" << endl;
    else cout << "Friendship" << endl;
    
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}