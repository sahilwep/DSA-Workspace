/*
//  B. A and B and Compilation Errors

// Observations: 
    * we have given n separated positive integers..
    * Then we have given n-1 separated positive integers..
    * Then at last we have given n-2 separated positive integer..
    * we need to find two integer that are disappear from first & second array..
    * we have third array to compare with first & second..

// Intrusion: 
    * First we will sort all the arrays..
    * Then with using pointers we will check which values are not present..
    * First with first & second array
        * after every check we will have to check for last element as we are checking only the shorter array size times.
    * Then with second & third array
        * after every check we will have to check for last element as we are checking only the shorter array size times.
    * At last we will return the result that we have stored...

    * TC: O(nlogn)

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
    int fir[n];
    int sec[n-1];
    int final[n-2];
    for(int i=0;i<n;i++) cin >> fir[i];
    for(int i=0;i<n-1;i++) cin >> sec[i];
    for(int i=0;i<n-2;i++) cin >> final[i];
    sort(fir, fir+n);
    sort(sec, sec+n-1);
    sort(final, final+n-2);

    // Operations: 
    vector<int> v;
    for(int i=0;i<n-1;i++){
        if(fir[i] != sec[i]){
            v.push_back(fir[i]);
            break;
        }
    }

    if(v.size() == 0){
        v.push_back(fir[n-1]);
    }

    for(int i=0;i<n-2;i++){
        if(sec[i] != final[i]){
            v.push_back(sec[i]);
            break;
        }
    }
    if(v.size() == 1){
        v.push_back(sec[n-2]);
    }
    
    cout << v[0] << endl << v[1] << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}