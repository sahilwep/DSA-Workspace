/*
//  3216. Lexicographically Smallest String After a Swap


Example 1:

Input: s = "45320"

Output: "43520"

Explanation:

s[1] == '5' and s[2] == '3' both have the same parity, and swapping them results in the lexicographically smallest string.

Example 2:

Input: s = "001"

Output: "001"

Explanation:

There is no need to perform a swap because s is already the lexicographically smallest.


// Observations: 
    * After swapping the different parity, we just break out..



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

string getSmallestString(string s) {
    for(int i=1;i<s.size();i++){
        // checking the adjecent digits pairty & their order..
        if ((s[i] % 2 == s[i-1] % 2) && (s[i] < s[i-1])) {  // if paridiy is same & s[i] grater than preivous, then goes inside the condition
            // Swap if they are out of order
            swap(s[i], s[i - 1]);   // swap the values..
            break;  // Perform only one swap
        }
    }
    return s;
}

void solve(){
    string s;
    cin >> s;
    cout << getSmallestString(s) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}