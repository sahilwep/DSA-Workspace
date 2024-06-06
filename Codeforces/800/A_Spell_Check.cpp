/*
//  A. Spell Check


// Observations: 
    * We have to check the spelling: 
            * Right spelling: 
                Timur

// Intrusion: 
    * We simply hash all the alphabet & check the size...
        * if size is > 5 return false...
        * if first letter is not the 'T' return false..
        * Then individually check the elements, if hashed value is grater than 

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
    cin >> s;
    map<char, int> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]]++;
    }

    auto i = mp.begin();
    if(i->first != 'T'){
        cout << "NO" << endl;
        return;
    }
    if(mp.size() != 5){
        cout << "NO" << endl;
        return;
    }
    string t = "";
    for(auto it = mp.begin();it!= mp.end();it++){
        // cout << it->first << " " << it->second << endl;
        if(it->second != 1){
            cout << "NO" << endl;
            return;
        }
        t += it->first;
    }
    if(t == "Timru") cout << "YES" << endl;
    else cout << "NO" << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}