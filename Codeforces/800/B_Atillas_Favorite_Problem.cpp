/*
//  B. Atilla's Favorite Problem


// Observations: 
    * We just need to return the last alphabet..
    * We can store the max Ascii alphabet, & then we can subtract that ascii value with 96, which will give it's positions...

// Intrusion: 
    * Initially we will make a variable with ascii value 97, because this is the least value & as per constrains, we atleast have one size of string..
    * as a = 97, & z = 122

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
    int maxAscii = 97;
    for(s_t i=0;i<s.size();i++){
        if(int(s[i]) > maxAscii){
            maxAscii = int(s[i]);
        }
    }
    // last we will subtract maxASCII with 96, will gives position of largest character in string..
    cout << maxAscii - 96 << endl;

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}