/*
//  A. Sum




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
    for(int i=0;i<n;i++){
        int first, second, third;
        cin >> first >>second >> third;
        if(first == second+third){
            cout << "YES" << endl;
        } else if(second == first+third){
            cout << "YES" << endl;
        } else if(third == first + second){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
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