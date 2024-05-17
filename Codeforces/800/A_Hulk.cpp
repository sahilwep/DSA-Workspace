/*
//  A. Hulk


// observations: 
    * If we carefully observe the pattern
    * first we have to print "i hate "
    * End we have to print "it"
    * Mid sequence change accordingly the iterations...
    * first mid sequence : "that i love"
    * second mid sequence : "that i hate"

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
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)

void solve(){
    int n;
    cin >> n;
    string start = "I hate ";
    string mid1 = "that I love ";
    string mid2 = "that I hate ";
    string end = "it";
    string res = start;
    for(int i=1;i<=n;i++){
        if(i != n){
            if(i % 2 != 0){
                res += mid1;
            } else {
                res += mid2;
            }
        }
    }
    res += end;
    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}