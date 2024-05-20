/*
//  A. Anton and Polyhedrons




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
    string s;
    int res = 0;
    for(int i=0;i<n;i++){
        cin >> s;
        if(s[0] == 'I') res += 20;
        else if(s[0] == 'D') res += 12;
        else if(s[0] == 'O') res += 8;
        else if(s[0] == 'C') res += 6;
        else if(s[0] == 'T') res += 4;
    }
    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    cin.ignore(); // Ignore the newline character left in the buffer
    
    while(t--){
        solve();
    }
    
    return 0;
}