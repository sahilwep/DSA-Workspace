/*

//  B. Upscaling

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

    string s, t;
    for(int p = 0; p < n; p++){
        if(p % 2 == 1){
            s += "..";
        }else{
            s += "##";
        }
        if(p % 2 == 1){
            t += "##";
        }else{
            t += "..";
        }
    }

    for(int i=0;i<2*n;i++){
        if(i % 4 < 2){
            cout << s;
        }else{
            cout << t;
        }
        el;
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