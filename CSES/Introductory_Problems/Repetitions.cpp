/*
//  Repetitions

// Observations: 
    * We will have to check longest sequence in an string..
    * Constrains: 
        * 1 <= n <= 10^6


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef long unsigned int lsi;  // declare during string traversal..
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
    int cnt = 1;
    int longest = 1;
    for(lsi i=1;i<s.size();i++){
        if(s[i] == s[i-1]){
            cnt++;
        }else{
            cnt = 1;
        }
        longest = max(cnt, longest);
    }
    cout << longest << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    
    while(t--){
        solve();
    }
    
    return 0;
}