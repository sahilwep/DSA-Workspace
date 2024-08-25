/*

//  A. Only Pluses

// Observations: 
    * We are given three integer, we have to find the product of it..
    * At most we can increase 5 times..
    * We can increase any of them, who's value is less.

// Intrusion: 
    * We can iterate from 1-5, & increase the value that is lesser..
    * At end we get the product of it..

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
    int a, b, c;
    cin >> a >> b >> c;
    for(int i=0;i<5;i++){
        if(a <= b && a <= c){
            a++;
        }
        else if(b <= a && b <= c){
            b++;
        }
        else{
            c++;
        }
    }
    cout << a * b * c << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}