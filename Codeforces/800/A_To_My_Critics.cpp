/*
//  A. To My Critics


// Observations: 
    a b c       -> Sum of two should make grater or equal 10.

    possible pair :     (a, b), (a, c), (b, c)

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
    // Naive solution:
    int a, b, c;
    cin >> a >> b >> c;

    if(a + b >= 10 || a + c >= 10 || b + c >= 10){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }


    // Generalized solution for n numbers: Checking each possible pairs: 
    // int n = 3;
    // int arr[n];
    // for(int i=0;i<3;i++) cin >> arr[i];
    // bool flag = false;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         // cout << arr[i] << " " << arr[j] << endl;  // for printing pair
    //         if(arr[i] + arr[j] >= 10){
    //             flag = true;
    //             break;
    //         }
    //     }
    //     // cout << endl;
    //     if(flag) break;
    // }
    // if(flag == true) cout << "YES" << endl;
    // else cout << "NO" << endl;


}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}