/*
//  B. Sereja and Suffixes

// Observations: 
    * For each li, we need to find how many distinct number are staying on the positions, li, li+1,....n
    * Formally we need to find the distinct number among ali, ali+1,...an
    * array elements are so large, we need to find each li.
    * We are given li, i.e the position, from li-->n, we need to find the unique elements in that range.

// Intrusion: 
    * Bruteforce solution, will use nested loop approach, that will take O(n^2) complexity.
        * By picking element one by one & checking if it's unique or not...


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

// Bruteforce Solution:
int findUnique(int arr[],int n,int li){
    int cnt = 0;
    for(int i=li-1;i<n;i++){
        bool flag = 0;
        for(int j=i+1;j<n;j++){
            if(arr[i] == arr[j]){
                flag = true;
                break;
            }
        }
        if(!flag){
            cnt++;
        }
    }
    return cnt;
}


void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n];
    arrInp;
    int l;
    while(m--){
        cin >> l;
        cout << findUnique(arr, n, l) << endl;
    }

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}