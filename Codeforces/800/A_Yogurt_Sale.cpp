/*
//  A. Yogurt Sale      https://codeforces.com/contest/1955/problem/A



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
#define arrOut for(int i=0;i<n;i++) cout << arr[i] ;
#define el cout << endl;
#define SQ(a) (a)*(a)



void solve(){
    int n, a, b;
    cin >> n >> a >> b;
    int cost_individual = n * a;
    int pairs = n / 2;
    int remainder = n % 2;
    int cost_promotion = (pairs * b) + (remainder * a);
    cout << min(cost_individual, cost_promotion) << endl;

}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}