/*
// A. Football              https://codeforces.com/problemset/problem/96/A

// We can count adjacent position elements, if its same, we will increase counter & if counter is 7, we print "YES" & return : else print "No"

// TC : O(n)


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
#define arrOut for(int i=0;i<n;i++) cout << arr[i] ;
#define el cout << endl;
#define SQ(a) (a)*(a)

void solve(){
    string s;
    cin >> s;
    int cnt = 1;    // counter should be 1, because we are going to compare the element before the iterator..
    for(int i=1;i<s.size();i++){
        // two adjacent elements..
        if(s[i-1] == s[i]){
            cnt++;  // increases the counter
        } else {
            cnt = 1;    // if not same, reset the counter to 1.
        }
        // at any movement counter is 7, we will return the YES.
        if(cnt == 7){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    int t;  // test case: change this according to the questions...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}