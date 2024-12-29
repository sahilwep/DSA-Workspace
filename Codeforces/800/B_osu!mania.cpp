/*

//  B. osu!mania

*/

#include<bits/stdc++.h>
#include<algorithm>
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
#define mod 1000000007


void solve(){
    int n;
    cin >> n;
    char ch;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            cin >> ch;
            if(ch == '#') arr[n-i-1] = j+1;
        }
    }

    for(auto i: arr) cout << i << " ";
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
        cout << endl;
    }
    
    return 0;
}