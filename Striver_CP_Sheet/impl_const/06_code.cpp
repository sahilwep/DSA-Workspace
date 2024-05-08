/*
//  A. Sum of Round Numbers




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
    int n;
    cin >> n;
    int digit = log10(n) + 1;
    vector<int> v;
    int cnt = 0;
    for(int i=0;i<digit;i++){
        int ld = n % 10;
        if(i == 0 && ld != 0){
            ld = 0 + ld;
            v.push_back(ld);
            cnt++;
        }
        else if(ld != 0){
            int mul = pow(10,i);
            ld = mul * ld;
            v.push_back(ld);
            cnt++;
        }
        n = n/10;
    }
    if(cnt == 4){
        reverse(v.begin(), v.end()-1);
    }
    else{
        reverse(v.begin(), v.end());
    }
    cout << cnt << endl;
    for(auto i : v) cout << i << " ";
    el;
}
/*
    n = 5009: 
        i = 0
            ld = 9
                v = 9
        i = 1
            ld = 0
                v = 9
            
        i = 2
            ld = 0
                v = 9
            
        i = 3
            ld = 0
                v = 9
            



*/

int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}