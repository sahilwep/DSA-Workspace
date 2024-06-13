/*
//  A. Chat room

// Observations: 
    * We have to remove all the elements from the string except "hello",
    * This should be in sequence...
    * If we carefully observe we have to hash all the value only once except 'h', we have to hash it twice..
    * All the value occurrence should be in sequence, mean it can be mixed with random character, but it should be in sequence:
        * Example: 
            ahhellllloou    -> h e l l o -> here, "hello" can be made
            hlelo   ->  h l e l o   -> here, "hello" can't be made..

// Intrusion: 
    * We can create our expected result string "hello",
    * we can iterate the element one by one & increment the matching string index..


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
    string res = "";
    string solu = "hello";
    for(int i = 0, k = 0;i<s.size();i++){
        if(s[i] == solu[k]){
            res += s[i];
            k++;
        }
    }
    // cout << res << endl;
    (res == "hello") ? cout << "YES" : cout << "NO";
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