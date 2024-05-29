/*
//  A. Lucky?


// In ascii 48 is '0'


// approach : 
    * we can store first 3 digit sum & last 3 digit sum, by taking input as string & then converting into int
    * We can convert char of string into string as : 
                x = int(s[0] - '0')         or x = int(s[0]) - 48;

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
    string s;
    cin >> s;
    int first , second = 0;
    first = int(s[0] - '0');
    first += int(s[1] - '0');
    first += int(s[2] - '0');

    second = int(s[3] - '0');
    second += int(s[4] - '0');
    second += int(s[5] - '0');

    if(first == second) cout << "YES" << endl;
    else cout << "NO" << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}