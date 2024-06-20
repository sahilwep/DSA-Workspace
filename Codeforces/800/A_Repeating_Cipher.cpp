/*
//  A. Repeating Cipher

// Observations: 
    * The cipher text works on algorithm:
        * It makes 
            s1 -> one same string 
            s2 -> two same string
            s3 -> three same string
            sm -> m times.

        * Example: 
            abc-> abc-> a-> abb-> abbccc
            bab-> b -> baa-> baabbb
    * We have given cipher text, we have to decrypt this...

// Intrusion: 
    * We have to only skip s[i]th iteration by 1->2->3->4->...n
    * we can use pointer approach:
        Example: 
             s = ooopppssss, n = 10
                * iterations start form 0->n, & we will use another variable to store the s[i]th value.
                * We will also maintain (k = 1), another pointer that used to skip iteration numbers..
                    i = 0, s[0] = o, res = "o", k = 1,(i = i + k = 1), i++ at end of every iteration, which makes i = 2
                    i = 2, s[2] = o, res = "oo", k = 2,(i = i + k = 4 ), i++ at end of every iteration, which makes i = 5
                    i = 5, s[5] = p, res = "oop", k = 3,(i = i + k = 8 ), i++ at end of every iteration, which makes i = 9
                    i = 9, s[9] = s, res = "oops", k = 4,(i = i + k = 13), i++ at end of every iteration, which makes i = 14..
                    break;
                res = "oops"

// TC: logn

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
    string s;
    cin >> n;
    cin >> s;
    int k = 1;
    string res = "";
    for(int i=0;i<s.size();i++){
        res += s[i];
        i = i + k;
        k++;
    }
    cout << res << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}