/*
//  A. Puzzles


// Observations: 
    * There are n student, and given each of them a jigsaw puzzle
    * There are m puzzle in the shop, but they might differ in difficulty and size.
        * specially, the first jigsaw puzzle consist of f1 pieces, and the second one consist of f2 pieces, and so on.
    * We have to make difference b/w no's of pieces in the present must be smallest as possible.
    * Let A, be the number of pieces in the largest puzzle that teacher buys and B, be the number of piece in the smallest such puzzle
    * We have to choose such n puzzle, so that A-B is minimum possible.

// Intrusion: 
    * If we sort the array & use sliding window, then we can get the minimum...
    * Example: 

array: 10 12 10 7 5 22
sorted: 5 7 10 10 12 22

Case 1: 
   5 7 10 10
    10 - 10 = 0
    10 - 7 = 3
    7 - 5 = 2
            total: 5    (smallest)

case 2: 
    7 10 10 12  -> 5
        12-10 = 2
        10-10 = 0
        10-7 = 3
            total: 5    (smallest)


case 3: 
    10 10 12 22
        22 - 12 = 10
        12 - 10 = 2
        10 - 10 = 0
            total = 12

// Approach: 
    * we can use sliding window, for each window we will check the difference..
    * after the each sliding iteration, we will get the minimum value...

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
#define arrInp for(int i=0;i<m;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);

// function used to find the minimum difference b/w the sliding window elements..
int kWindow(vector<int> arr, int start, int end){
    int res = 0;
    for(int i=start+1;i<=end;i++){
        res += arr[i] - arr[i-1];
    }
    return res;

}

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    arrInp;
    sort(arr.begin(), arr.end());   // sort the array..

    // now moving this window throughout the array..
    int sol = INT_MAX;
    // we will start from 0 & go till ((arr.size()-1)-(n-1))
    for(int i=0;i<arr.size()-(n-1);i++){    
        int temp = kWindow(arr, i, i+(n-1));    // at every iteration of i, we will check the window difference..
        sol = min(sol, temp);   // last we will store the window difference, with previous compared minimum values..
    }
    cout << sol << endl;    // last we will print the result..
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}