/*

//  B. Different String

// Observations: 
    * We just have to check the string have same character throughout the string or not, if it's print NO
    * Else we just have to change the order of the character & print the string...


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
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
    bool flag = 0;
    for(int i=1;i<s.size();i++){
        if(s[i] != s[i-1]){
            flag = 1;
        }
    }
    if(!flag){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        // we need to find the distinct values...
        for(int i=1;i<s.size();i++){
            if(s[i]!= s[i-1]){
                swap(s[i], s[i-1]);
                cout << s << endl;
                return;
            }
        }
    }
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}