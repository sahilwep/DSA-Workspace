/*
//  A. Dubstep

// Observations: 
    * We have string mixed with "WUB", we need to remove it from the string s & print the remaining string..


// Intrusion:
    * First we will store the unique sequence into new string with space..
    * then we remove spaces from front and end..


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
    string res = "";
    // operations to store the unique codes only:
    int n = s.size()-1;
    // if string end with last three codes
    if(s[n] == 'B' && s[n-1] == 'U' && s[n-2] == 'W'){
        for(int i=0;i<s.size()-3;i++){
            if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
                i = i + 2;
                res += ' ';
            }else{
                res += s[i];
            }
        }
    }
    // string end without codes
    else{
        for(int i=0;i<s.size();i++){
            if(s[i] == 'W' && s[i+1] == 'U' && s[i+2] == 'B'){
                i = i + 2;
                res += ' ';
            }else{
                res += s[i];
            }
        }
    }

    // as this string res store some space in beginning & end, we need to remove it..
    int k = 0;  // finding first value, so that we can remove space
    for(int i=0;i<res.size();i++){
        if(res[i] >= 65){
            break;
        }
        k++;
    }
    int l = res.size()-1;   // finding last value, so that we can remove space
    for(int i=l;i>=0;i--){
        if(res[i] >= 65){
            break;
        }
        l--;
    }
    for(int i=k;i<=l;i++) cout << res[i];   // printing the string.
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