/*

//  A. Rudolf and the Ticket

// Observations: 
    * we will have to check whether the two coins from both the array list will have value less or equal to k or not, if it's, then how many possible combinations are there...
    * We can sort the array & the we can pick each element from the both the array and match the conditions...

// Intrusion: 
    * first we will sort both the array...
    * Second we will iterate till the value is less than 'k'..
    * and from there we will match values from both the array with k...


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
    int a[n], b[m];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+m);

    int cnt = 0;
    for(int i=0;(i < n) && (a[i] < k);i++){
        for(int j=0;(j < m) && (b[j] < k);j++){
            if(a[i] + b[j] <= k) cnt++;
        }
    }

    cout << cnt << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}