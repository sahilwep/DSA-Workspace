/*
//  A. Black Square



// Observations: 
    * At every second jury touches (ai)th part of touch-screen
    * We are given (ai)th part of calories burn..

        a1=1 a2=2 a3=3 a4=4     -> waste ai calories on touching ith strip

            touches : 1 2 3 2 1 4
            index:    1 2 3 4 5 6 -> seconds goes from 1 to n..

        * Calories burns:       burn = 0
                1sec => touches = 1 -> a1 = 1         => burn += 1
                2sec => touches = 2 -> a2 = 2         => burn += 3
                3sec => touches = 3 -> a3 = 3         => burn += 6
                4sec => touches = 2 -> a2 = 2         => burn += 8
                5sec => touches = 1 -> a1 = 1         => burn += 9
                6sec => touches = 4 -> a4 = 4         => burn += 13



        a1=1 a2=5 a3=3 a4=2

            touches: 1 1 2 2 1
            index:   1 2 3 4 5     -> second goes from 1 to n...

        * Calories burns:       burn = 0
                1sec => touches = 1 -> a1 = 1         => burn += 1
                2sec => touches = 1 -> a1 = 1         => burn += 2
                3sec => touches = 2 -> a2 = 5         => burn += 7
                4sec => touches = 2 -> a2 = 5         => burn += 12
                5sec => touches = 1 -> a1 = 1         => burn += 13

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
    int arr[4];
    for(int i=0;i<4;i++) cin >> arr[i];
    string s;
    cin >> s;
    int burn = 0;

    for(int i=0;i<s.size();i++){
        // int(s[i] - 48)   // convert into int
        // char(s[i] - 0)   // convert into char
        // cout << int(s[i] - 48) << " ";       // gives ith index of array, but it's started from 0, so we subtract while fetching from array..
        burn += arr[int(s[i] - 48) - 1];
    }
    cout << burn << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}