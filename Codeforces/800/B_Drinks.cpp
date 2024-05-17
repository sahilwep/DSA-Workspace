/*
//  B. Drinks

// observations: 
    * here we are doing the sum / n
    * for precision we have used the setprecision(n) function -> that give the n value precision..
    * fixed -> gives the number of the n times value, if there is no such value for absolute number then it places 0 there..


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
    int n;
    cin >> n;
    double res = 0;
    for(int i=0;i<n;i++){
        float k;
        cin >> k;
        res = res + k;
    }
    res = res / n;
    cout << fixed << setprecision(12) << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}