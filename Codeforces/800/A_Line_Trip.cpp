/*
//  A. Line Trip                https://codeforces.com/problemset/problem/1901/A


   (start)                        (return)
      0     1       2       5       x(7)
       ---->1l---->1l------>3l--------|
                             <---------
                            2+2 L   : At last point x, there is no gas station..
                            Formula: {2*(x-a)}

        a0     a1      a2
         0     1       2 
         ------>1l----->
              (a1-a0))  : Formula:  (ai+1 - ai)


    * Let's understand with another example:
        0       1         4         6       7       10(x) : 2*x-an
        ------->1l------->3l-------->2L----->1l------>3l + 3L(tor return to 7)
        max(1, 3, 2, 1, 6) : max of all the fuel, so that we can reach to starting point...
        max(a1-a0, a2-a1, a3-a2,...., 2*(x-an))



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
    int n, x;
    cin >> n >> x;
    int arr[n];
    arrInp;
    int last = 0;   // Starting point is 0
    int tankSize = INT_MIN;
    for(int i=0;i<n;i++){
        tankSize = max(tankSize, arr[i] - last);    // performing (arr[i] - arr[i-1]) & comparing with previous result & storing it...
        last = arr[i];  
    }
    // handling last point: 
    tankSize = max(tankSize, 2*(x - last));
    cout << tankSize << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}