/*
//  A. Array with Odd Sum


// Observations: 
    * We need to find that if the array of elements having odd sum or not?
        * Odd Sum property:
            * odd + odd = even
            * odd + odd + odd = odd
        * We can say that if numbers of odd elements are even in number we can have sum as even-number
        * and if the number of odd elements are odd in number, we can have sum as odd-number


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
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin >> arr[i];
    int evenCnt = 0, oddCnt = 0, sum = 0;
    for(int i=0;i<n;i++){
        if(arr[i] % 2 != 0){
            oddCnt++;
        }else{
            evenCnt++;
        }
        sum += arr[i];
    }
    // if array is is odd, we can directly say "YES"
    if(sum % 2 != 0 ) cout << "YES" << endl;
    // else we have to check odd sum & even sum
    else{
        // if oddcnt and evencnt is not == 0, we always have sum values in odd.
        if(oddCnt != 0 && evenCnt != 0) cout << "YES" << endl;
        else cout << "NO" << endl;  // else "NO"
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