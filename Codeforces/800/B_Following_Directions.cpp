/*
//  B. Following Directions

// Observations: 
    * We will start at the coordinates: (0, 0), candy is at (1, 1)
    * We are given a string containing the path of traversal...
    * We need to determine whether we are able to pass the candy or not?

// Key Observations: 
    * initial coordinates: (0, 0), say (x, y)
    * For U -> y++
    * For D -> y--
    * For R -> x++
    * For L -> x--

*/

#include<bits/stdc++.h>
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



void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> p;
    p.first = 0, p.second = 0;
    bool flag = 0;
    for(int i=0;i<s.size();i++){
        if(s[i] == 'U') p.second++;
        else if(s[i] == 'D') p.second--;
        else if(s[i] == 'R') p.first++;
        else if(s[i] == 'L') p.first--;
        if(p.first == 1 && p.second == 1){
            flag = 1;
            break;
        }
    }
    (flag) ? cout << "YES" : cout << "NO";
    el;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}