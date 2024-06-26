/*
//  A. Vlad and the Best of Five

// Observations: 
    * find the frequency of most occurring characters..


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
    string s;
    cin >> s;
    int cntA = 0;
    int cntB = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'A') cntA++;
        else cntB++;
    }
    (cntA > cntB) ? cout << "A" : cout << "B";
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