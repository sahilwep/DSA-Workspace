/*
//  A. cAPS lOCK

// Observations
    * We are given a string, & we have to check wether Capslock was on by mistakenly or not?
    * We have given all the constrains, & we ahve to follow..
        * we have to perform string manipulations if:
            * all the string is in upper case..
            * or the first character is lower & rest all are upper..
        * In these case we have to convert string, in a way it's that first character is upper & rest are lower...

// Intrusion: 
    * We have to check if all the letters in string is in uppercase, convert all of them to lowercase..
    * if first letter is lowercase & rest were uppercase, then convert first upper & rest lower...
    * from index 1 to n-1 if any letter is found to be small case, return the original string..


// ASCII: 
    A = 65
    Z = 90
    a = 97
    z = 122

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
    string temp = s;
    bool flag = false;
    for(int i=1;i<s.size();i++) (s[i] <= 90) ? s[i] = s[i] - 'A' + 'a' : flag = true;
    if(flag){
        cout << temp;
    }
    else{
        if(s[0] <= 90){
            s[0] = s[0] - 'A' + 'a';
        }else{
            if(s[0] > 90)  s[0] = s[0] - 'a' + 'A';
        }
        cout << s;
    }
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