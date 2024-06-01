/*
//  A. Medium Number


// find midian of 3 unsorted value...


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
    int f,s,t;
    cin >> f >> s >> t;
    int minVal = min(f, min(s, t));     // finding min value among all
    int maxVal = max(f, max(s, t));     // finding max value among all
    // comparing for mid value..
    if(minVal != f && maxVal != f){
        cout << f << endl;
    }else if(minVal != s && maxVal != s){
        cout << s << endl;
    }else if(minVal != t && maxVal != t){
        cout << t << endl;
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