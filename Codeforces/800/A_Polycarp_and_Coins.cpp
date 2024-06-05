/*
//  A. Polycarp and Coins


// Observations: 
    * If we carefully observe, we have 2 & 1 burles, & we have to divide n amount...
    * means we have to divide it in that way we have this condition true: 
        * c1 + 2*c2 = n
        * & also we must minimize | c1 - c1 |

    * Example: 
        n = 1000
        output: 334 333

        * If we observe carefully: 
            1000/3 = 333    -> c2
            n - 2*c2 = c1
            1000 - 2*333 = 334 -> c1
            * and we satisfied conditions...



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
    int i = round(n/3.0);       // remember, while using round function user double division, else it will not work properly..., means use n/3.0 not n/3
    int j = n - 2*i;

    cout << " " << j << " " << i<< endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}