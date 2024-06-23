/*
//  A. Laptops


// Observations: 
    * we have to find if cheaper price have better specification or not?
    * input have two values, price & specifications
    * we are comparing two product consecutively, & for that if cheaper price have better specification, then we print "Happy Alex" : else "Poor Alex"



// Intrusion: 
    * first we will take input in pairs.
    * We will sort the value by price..
    * Then we can compare the two laptops, by their price & specification...
    * If condition satisfies, we print the result "Happy Alex" : else we print print "Poor Alex"



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


void solve(){
    int n;
    cin >> n;
    pair<int, int> p[n];    // we only have to take two values, so we will take in pairs.
    for(int i=0;i<n;i++){
        cin >> p[i].first >> p[i].second;   // taking input
    }
    sort(p, p+n);   // sorting will sort by the price: "p[i].first"

    for(int i=0;i<n-1;i++){
        // condition when price is cheeper & specification is better...
        if(p[i].first < p[i+1].first && p[i].second > p[i+1].second){
            cout << "Happy Alex" << endl;
            return;
        }
    }
    // when higher price have more specifications..
    cout << "Poor Alex" << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}