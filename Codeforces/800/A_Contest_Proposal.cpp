/*
//  A. Contest Proposal

// Operations we are performing: 
    * If a[i] > b[i] -> perform operation.
        * insert the smallest element at a[n-1] position
        * Sort the array... 

        First step: 
            1000 1400 2000 2000 2200 2700
            800 1200 1500 1800 2200 3000
            result: 
            a[] = 800 1000 1400 2000 2000 2200
            b[] = 800 1200 1500 1800 2200 3000
        Second step: 
            800 1000 1400 2000 2000 2200
            800 1200 1500 1800 2200 3000
            result: 
            a[] = 800 1000 1400 1800 2000 2000
            b[] = 800 1200 1500 1800 2200 3000

        * All we have to do is count the number of operations.

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
#define arrOut(k) for(int i=0;i<n;i++) cout << a[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)

void insertBegSort(vector<int> &v, int k){
    int n = v.size();
    v[n-1] = k;
    sort(v.begin(), v.end());
}
 
void solve(){
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
 
    int cnt = 0;
    for(int i=0;i<n;i++){
        while(a[i] > b[i]){
            insertBegSort(a, b[i]);
            cnt++;
        }
    }
    cout << cnt << endl;
}

int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}