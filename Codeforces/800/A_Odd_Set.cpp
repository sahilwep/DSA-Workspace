/*
//  A. Odd Set

// Observations: 
    * we will just have to split the odd & evens elements into paris of n group...
    * If the count of odd & even which makes pair, means odd count should be equal to n, & even count should be equal to n, then we can say "YES" : else "NO"


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
    cin >> n;
    int arr[2*n];
    int oddsCnt = 0;
    int evenCnt = 0;
    for(int i=0;i<2*n;i++){
        cin >> arr[i];
        if(arr[i] % 2 != 0) oddsCnt++;
        else evenCnt++;
    }
    if(oddsCnt == n && evenCnt == n){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
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