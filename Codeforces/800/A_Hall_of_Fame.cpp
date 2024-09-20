/*

//  A. Hall of Fame

//  Observations: 
    * We have trophy from 1 to n, & each trophy has lamp in between them.
    * Lamp can be directed in left or right that ic can illuminate the trophy.
    * We are given a string s, & it has two character 'L' & 'R', more formally,
    * for each i, 
        * trophy 1, 2, 3,..i-1, s[i] = left
        * trophy i+1, i+2,...n, s[i] = right
    * We can choose any index i, & i+1, in order to make our lamp will illuminate to each trophy, 
    * If it's possible then return the number of swap
    * If it's not possible then return -1



// Example:
    s = LLRLLLR

    L L R L L L R

    L R L L L L R


*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;

    // edge case: 
    if(s.size() == 2){
        if(s[0] == s[1]){
            cout << -1 << endl;
            return;
        }
        else if(s[0] == 'L'  && s[1] == 'R'){
            cout << 1 << endl;
            return;
        }
        else if(s[0] == 'R'  && s[1] == 'L'){
            cout << 0 << endl;
            return;
        }
    }
    // For Whole Right
    bool isRight = 1;
    for(int i=0;i<n;i++) if(s[i] != 'R') isRight = 0;
    if(isRight){
        cout << 0 << endl;
        return;
    }
    // For Whole Left
    bool isLeft  = 1;
    for(int i=0;i<n;i++) if(s[i] != 'L') isLeft = 0;
    if(isLeft){
        cout << 0 << endl;
        return;
    }
    
    int swCnt = 0;
    for(int i=1;i<n;i++){
        if(s[i] == s[i-1] && s[i] != s[i+1]){
            swCnt++;
            swap(s[i], s[i-1]);
            swap(s[i], s[i+1]);
        }
    }
    
    cout << swCnt << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}