/*
//  A. Word Capitalization


// if the first character of string is small case, then we have to make it to the capital case..




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
#define arrOut for(int i=0;i<n;i++) cout << arr[i] ;
#define el cout << endl;
#define SQ(a) (a)*(a)



void solve(){
    string s;
    cin >> s;
    if(s[0] > 90){
        s[0] = s[0] - 'a' + 'A';
    }
    cout << s << endl;
    
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}