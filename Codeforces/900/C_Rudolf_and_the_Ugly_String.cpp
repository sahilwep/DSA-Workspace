/*
//  C. Rudolf and the Ugly String

// Observations: 
    * we have to check for the substring 'pie' and 'map'...
    * we can check for the particular sub-string window size...

// we can use greedy

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
    int n;
    string s;
    cin >> n >> s;
    int cnt = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'm'){
            if(s[i] == 'm' && s[i+1] == 'a' && s[i+2] == 'p'){
                cnt++;
                i+=2;
            }
        }
        else if(s[i] == 'p'){
            if(s[i] == 'p' && s[i+1] == 'i' && s[i+2] == 'e'){
                cnt++;
                i+=2;
            }
        }
    }
    cout << cnt << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}