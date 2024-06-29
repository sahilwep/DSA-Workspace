/*
//  B. Gifts Fixing


// Observations: 
    * If we observe the input, we can observe some pattern like,
    * the minimum number is b/w both the array is using to subtract all the element & from there they are adding the maxDifference b/w both the array..
    * Example:
           size =  3
           a =  3 5 6
           b =  3 2 3
                    minA = 3, min B = 2

            for i = 0, 
                    3 - 3 = 0
                    3 - 2 = 1   -> stored

            for i = 1, 
                    5 - 3 = 2   -> stored
                    2 - 2 = 0

            for i = 2, 
                    6 - 3 = 3   -> stored
                    3 - 2 = 1

                    TOTAL: 1 + 2 + 3 = 6
    * We are getting the max difference b/w both the array because, we are allowed to subtract 1 from both the array..
    * Which makes, in one move we can subtract 1 from both the array...


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
    vector<int> a(n);
    vector<int> b(n);
    int minA = INT_MAX, minB = INT_MAX;
    for(int i=0;i<n;i++){
        cin >> a[i];
        minA = min(a[i], minA);
    }
    for(int i=0;i<n;i++){
        cin >> b[i];
        minB = min(b[i], minB);
    }
    // Now computing the sum...
    ll totalSum = 0;
    for(int i=0;i<n;i++){
        int maxDiff = max(a[i] - minA, b[i] - minB);
        totalSum += maxDiff;
    }
    cout << totalSum << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}