/*
//  A. Helpful Maths

// ASCII Range: 
    0 -> 48
    9 -> 57

// Intrusion: 
    * Create hash array, & store the frequency of ascii numeric value
    * Create another string that can store hashed values..
    * at end, we print the string from 0->n-2

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
    int hash[52] = {0};
    for(int i=0;i<s.size();i++){
        if(s[i] != '+'){
            hash[int(s[i])]++;
        }
    }
    string res;
    for(int i=49;i<52;i++){
        int k = hash[i];
        for(int j=0;j<k;j++){
            res += char(i);
            res += "+";
        }
    }
    for(int i=0;i<res.size()-1;i++){
        cout << res[i];
    }
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