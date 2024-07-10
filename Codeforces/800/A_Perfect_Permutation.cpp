/*
//  A. Perfect Permutation


// Observations: 
    * we need to print the prefect permutation..
    * According to the question: 
        * A perfect permutations p for any i(1 <= i <= n)(n = is the permutations size) for following holds:
        * Ppi = i & pi != i
    * In simple word we need to print those value of Ppi = i, whose satisfies the conditions above...
    * we can check the number is divisible by 2 or not, if we get the remainder as 1, we can print "-1"
    * else: 
        * first we will print "2 & 1", then 
        * In loop from i = 3 to n: 
        * we can print the i+1 & i, & increment the value as i+=2...
    * If we carefully observe the testcase, we can crack the pattern in which the values are printing...


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
    if(n % 2 == 1){
        cout << -1 << endl;
    }
    else{
        cout << "2 1";
        for(int i=3;i<n;i+=2){
            cout << " " << i+1 << " " << i ;
        }
        el;
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