/*
//  A. Mahmoud and Longest Uncommon Subsequence

// Observations: 
    * we are given two string a, & b, we need to find the longest uncommon subsequence, which the longest string subsequence that is subsequence of one of them are not subsequence of other...
    * Subsequence: a subsequence of string is sequence of character that appears in the same order in the string.
    * It's not needed to appearance to be consecutive.
    * Example: 
        ab, bc, abc, and a        -> subsequence of "abc"
        abbc, acb are not

    * In conclusion: 
        * we have to print longest uncommon subsequence of a and b
        * If there is no such subsequence, we can print -1

// Key observations: 
    * we have to find the length of uncommon subsequence..
    * we have to find longest string that is subsequence of one of them & not subsequence of the other.
    * If we have same string, we can print -1..
    * Else if we don't have same string, we can return the max size stirng...
    * else if the length is same & string is distinct, we can return the size of string..


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
    string a, b;
    cin >> a >> b;

    // when size of string is not same
    if(a.size() != b.size()){
        cout << max(a.size(), b.size()) << endl;
    }
    // when both the string is same
    else if(a == b){
        cout << -1 << endl;
    }
    // when we have same size string
    else{
        cout << a.size() << endl;
    }

}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}