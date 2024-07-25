/*

//  A. Deletions of Two Adjacent Letters

// Observations: 
    * string length will be odd in size..
    * We need to remove two adjacent element of string..
    * At last we have to form string c
    * If it's possible to create such string we have to print "YES" : else we can print "NO"



// Key Observations:
    * If we have string with odd size, & we have to remove two adjacent element & form such string c, then we have these possible conditions..
    * If the string c is at the positions (n/2), we can form such string c.
    * If the string is at first or last position, then we can form such string c.

// Intrusion: 
    * When we encounter with that character we will just have to count the left of the number & right of that number..
    * IF it's even then we can form that string.
    * We also need to check repetitive character in string, if the string c is matching with it..
    * When we match with the character we will check the index & If it's odd, then we will return "YES",
    * Else we will return "NO".
    * Because, we know that if the element is at odd index we can remove two consecutive element in such a way so that it can leave the single matched string c.
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
    string s;
    char ch;
    cin >> s >> ch;
    
    int idx = -1;
    for(int i=0;i<s.size();i++){
        if(s[i] == ch){
            idx = i+1;
            if(idx % 2 != 0){
                cout << "YES" << endl;
                return;
            }
        }
    }
    if(idx == -1) cout << "NO" << endl;
    else if(idx % 2 != 0) cout << "YES" << endl;
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