/*

//  B. CopyCopyCopyCopyCopy

//  Observations: 
    * We are given an array, we have to create longest increasing subsequence of that array, & We have to return the size of it.

// Intrusion: 
    * If we carefully observe, we can form the longest increasing subsequence by taking only unique element from the given array..
    * as we are allowed to form array according to our needs with given elements.
    * So, we can say whatever unique values we have that will make the combinations which is increasing subsequence..
    * We can use set data structure that will done the job.

*/

#include<bits/stdc++.h>
#include<algorithm>
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
#define mod 1000000007


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    set<int> s;
    for(auto i: v){
        s.insert(i);
    }

    cout << s.size() << endl;
    
}

int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}