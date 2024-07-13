/*
//  B. Collatz Conjecture


// Observations: 
    * we have to follow the following operations k times..
        * increase x by 1
        * while the number x is divisible by y, divide it by y...
        * In simple word we have to perform these operations: 
            
            while(k--){
                x += 1;
                while(x % y == 0){
                    x = x / y;
                }
            }
        * But this solutions will lead us to TLE


*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll x, y, z;
    cin >> x >> y >> z;
    x++;
    z--;
    while(x != y){
        if(x % y == 0){
            while(x % y == 0){
                x /= y;
            }
        }
        if(z == 0){
            cout << x << endl;
            return;
        }
        ll temp = y - x % y;
        if(temp <= z){
            x = x + temp;
            z = z - temp;
        }else{
            cout << x + z << endl;
            return;
        }
    }
    cout << 1 + z % (y-1) << endl;
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}