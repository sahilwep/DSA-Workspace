/*
//  A. Don't Try to Count

// According to the question, constrains are: 
    1<= n*m <= 25  , length of n*m should be less than 25
    len(x) = n, len(s) = m
    x -> xx -> xxxx -> xxxxxxxx -> xxxxxxxxxxxxxxxx

    * In worst case: 
    n = 1, m = 25
    x = 'a'
    s = 'aaaa...25 times'
    'a' -> 'aa' -> 'aaaa' -> 'aaaaaaaa' -> 16 -> 32
     0       1       2          3           4     5, here in worst case we cannot have more than 5 operations...
    * even after applying operations of adding x with x, 5 times if it's not become s, then can return -1..

    * Conclusion: 
        * Try doing operation 5 times..
        * Even after applying operations 5 times, s is not part of x, -> print -1
        * If after applying operations ith times -> print i

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
    int n, m;
    cin >> n >> m;
    string x, s;
    cin >> x >> s;
    bool found = false;
    for(int i=0;i<=5;i++){
        if(x.find(s) != string::npos){
            cout << i << endl;
            found = true;
            break;
        }
        x.append(x);
    }
    if(!found){
        cout << -1 << endl;
    }
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}