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


    * Efficient Approach: 
        * We can use dp, technique:
        * we can use set ds, & iterate from last to first..
        * as set stores only unique elements..
        * we can start inserting last value size, then iterate to first & storing the size,
        * as set stores only unique value, if we have encounter any duplicate values, the size of uniques value to their right will be stored..


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


// Efficient Solution: 
void solve(){
    int n, m;
    cin >> n >> m;
    int arr[n+1];
    for(int i=1;i<=n;i++) cin >> arr[i];

    // preprocessing:
    int query[n+1];     // creating a query to store the size of unique elements..
    set<int> s; // using set data-structure
    // start iterating from last & goes to first..
    for(int i=n;i>0;i--){
        s.insert(arr[i]);   // while iterating insert value to set, as set only stores unique values.
        query[i] = s.size();    // storing the size of set the index of query[i]
    }

    // query:
    int l;
    while(m--){
        cin >> l;
        cout << query[l] << endl;
    }


}

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

void solve_(){
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