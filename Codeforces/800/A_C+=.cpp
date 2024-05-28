/*
//  A. C+=


// observations
    * we have a += b, or b += a, operations
    * we have to make any one of them grater than n.

a = 5, b = 4, n = 100

if(a < b) a += b, else (b += a)

1st : b += a, a = 5, b = 9
2nd : a += b, a = 13, b = 9
3rd : b += a, a = 13, b = 22
4th : a += b, a = 35, b = 22
5th : b += a, a = 35, b = 57
6th : a += b, a = 92, b = 57
7th : b += a, a = 92, b = 149 --> at this times we have b > n, so break


15 12409 160767


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
    long long a, b, n;
    cin >> a >> b >> n;
    int i = 0;
    while(i < n){
        if(a < b){
            a += b;
            i++;
        }else{
            b += a;
            i++;
        }
        if( a > n || b > n) break;
    }
    cout << i << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}