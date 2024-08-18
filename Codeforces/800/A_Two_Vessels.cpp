/*

//  A. Two Vessels

// Observations:
    * We are given two vessel of water, first vessel contains a liters, & second vessel contains b liters, both vessel are large and can hold any amount.
    * we can have an empty cup that can hold up c grams of water.


    Example: 
        a = 3, b = 7, c = 2
        diff = 4
        every step we can take 2
            a = 3+2, b = 7-2
            a = 5, b = 5 ==> equal
            Only One step needed.

        a = 17, b = 4, c = 3
        diff = 13
        every step we can take 3
            a = 17 - 3, b = 4 + 3
            a = 14, b = 7   -> step 1
            a = 11, b = 10  -> step 2
            a = 10.5, b = 10.5 -> step 3
            Three steps needed.
        


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
    int a, b, c;
    cin >> a >> b >> c;
    int cnt = 0;
    int maxVal = max(a, b);
    int minVal = min(a, b);
    // int cnt = 0;
    int need = maxVal - minVal;
    while(minVal < maxVal){
        minVal = minVal + c;
        maxVal = maxVal - c;
        cnt++;
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