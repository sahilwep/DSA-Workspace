/*
//  A. Magical Sticks


// Observations: 
    * We have set of n sticks, we can connect two stick of length a, b & new stick will be form of size (a+b), 
    * Previous stored a,b size stick will disappear from set of n stick & new 1 stick will be appear..
    * We have to create maximum number of stick that have same length, although if all the size will not the same, then in this case it's okk..
    * We have to find the number of equal length of stick in the set..

// Intrusion:
    * For n i.e even split n/2
    * For n i.e odd split (n/2 + 1)
    * return result

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
    (n % 2 == 0) ? cout << (n/2) : cout << ((n/2) + 1) ;
    el;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}