/*

//  C. Gorilla and Permutation

// Permutations: 
    * Permutations means the selections of objects, where order of selections matters.
    * nPr : n!/(n-r)!

// Observations: 
    * gorilla & monk found three number n, m, & k, (m < k)
    * They decided to build permutation of length n 
    * We have to build an array of elements that following the permutations conditions...
        * a permutations of length n, &  (arr[i] <= n)
    * if we carefully observe the input & output pattern:
        * we first have to print the element that start from n to m...
        * Then we have to print the element form 1 to m...



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
    int n, m, k;
    cin >> n >> m >> k;
    for(int i=n;i>m;i--) cout << i << " ";
    for(int i=1;i<=m;i++) cout << i << " ";
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