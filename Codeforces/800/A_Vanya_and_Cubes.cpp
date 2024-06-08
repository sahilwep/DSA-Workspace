/*
//  A. Vanya and Cubes




// Observations: 


// n = 25

             *   ->  level 1    prev =  0(prev) + 1(level) -> prev = 1,     n -= prev => 24
           * * *     -> level 2,    prev =  1(prev) + 2(level) -> prev = 3,    n -= prev => 21
        * * * * * *      -> level 3,    prev = 3(prev) + 3(level) -> prev = 6,      n = prev => 15
    * * * * * * * * * *       -> level 4,   prev = 6(prev) + 4(level) -> prev = 10,     n -= prev => 5
 * * * * * * * * * * * * * * *        -> level 5,   prev = 10(prev) + 5(level) = 15,        n -= prev => -10        -> break;


        *  At level 5 -> it break, so we can make only till 4th level, because n has exceeded after after 4th level



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
    if(n == 1){
        cout << 1 << endl;
        return;
    }
    int total = 0;
    int prev = 0;
    int level = 1;
    while(n > 0){
        prev = prev + level;
        n = n - prev;
        if(n < 0) break;
        level++;
    }
    cout << level-1 << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}