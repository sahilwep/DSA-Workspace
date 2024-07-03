/*
//  B. Ten Words of Wisdom

// Observations:
    * we have n responses, each response submit word & quality..
    * Out of all the responses, we have to find the request which has word value less or equal 10 & having highest quality...
    * we have to return that number of participant..

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
    int a[n], b[n];
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }

    // operations: 
    int currMax = 0;
    int maxPos = -1;    // final index that contains the maximum..
    for(int i=0;i<n;i++){
        if(a[i] <= 10){
            if(b[i] > currMax){
                currMax = b[i];
                maxPos = i;
            }
        }
    }
    cout << maxPos+1 << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}