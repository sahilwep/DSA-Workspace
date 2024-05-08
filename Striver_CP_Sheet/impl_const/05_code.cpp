/*
//  A. The New Year: Meeting Friends




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
    int a, b, c;
    cin >> a >> b >> c;
    int minVal = INT_MAX, maxVal = INT_MIN;
    // finding max val
    if(a > b && a > c){
        maxVal = a;
    } else if (b > a && b > c){
        maxVal = b;
    } else {
        maxVal = c;
    }
    // finding min val
    if(a < b && a < c){
        minVal = a;
    } else if(b < a && b < c){
        minVal = b;
    } else {
        minVal = c;
    }
    cout << maxVal - minVal << endl;

    
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}