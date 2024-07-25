/*

//  A. Three Pairwise Maximums

// Observations: 
    * we are given x, y & z
        x = max(a, b)
        y = max(a, c)
        z = max(b, c)
    * We have to determine if it's possible to obtain a, b, c or not?
    * If we sort them & compare the last two value if they are not equal, we can return "NO" : else "YES"

    * for the condition to be true, two element need to be equal & Third number should be lesser than both of them..


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
    int arr[3];
    for(int i=0;i<3;i++) cin >> arr[i];
    sort(arr, arr+3);

    if(arr[1] != arr[2]){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
        cout << arr[0] << " " << arr[0] << " " << arr[2] << endl;
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