/*
//  A. Chewbaсca and Number


// Ascii values of numbers: 

    48 ----> 57
    48 -> 0
    49 -> 1
    50 -> 2
    51 -> 3
    52 -> 4
    53 -> 5
    54 -> 6
    55 -> 7
    56 -> 8
    57 -> 9

// here we are subtract ascii value from ascii value, example: 
        char  :'9' - '6' = 'some random value, because
        ascii : 57 - 54 = 3, & ascii value of 3 is : ETX (end of text).
        Solution: 
            '9' - '6' + '0' = '3'
             57 - 54 + 48 = 51->3

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
#define SQ(a) (a)*(a)



void solve(){
    string s;
    cin >> s;
    for(int i=0;i<s.size();i++){
        if(i == 0 && s[i] == '9'){
            continue;
        }
        if(s[i] > '4'){
            s[i] = '9' - s[i] + '0';
        }
    }
    cout << s << endl;
}

int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}