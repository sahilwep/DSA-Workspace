/*

//  A  Maximum in Table

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
    cin >> n;
    int arr[15][15];
    for(int i=1;i<=1;i++){
        for(int j=1;j<=n;j++){
            arr[i][j] = 1;
        }
    }

    for(int i=2;i<=n;i++){
        arr[i][1] = 1;
        for(int j=2;j<=n;j++){
            arr[i][j] = arr[i-1][j] + arr[i][j-1];
        }
    }

    cout << arr[n][n] << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}