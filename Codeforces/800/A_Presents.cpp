/*
//  A. Presents


// Observations: 
    * for each i gives gift to pi i.e : i --> pi

Input: 
        4
        2 3 4 1
index:  1 2 3 4
i has given gift to pi
    i->pi
    1->2
    2->3
    3->4
    4->1

* We have to print the i, for each pi in order i.e: 
    pi -> i
    1  -> 4
    2  -> 1
    3  -> 2
    4  -> 3

* we can do this by storing these index by the arr[] elements..
* note as the indexing start from 1->n, & we are storing the value from 0->n, 
* we have to decrement the arr[]-1 & increment the i+1, while doing operations...

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
    int arr[n];
    arrInp;
    int out[n];
    for(int i=0;i<n;i++){
        //  note i++ & i-- wil increment & assign the value it, so we have use the i-1 & i+1, we just want incremented & decremented value to be stored & computed
        out[arr[i]-1] = i+1;
    }
    for(auto i : out) cout << i << " ";
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