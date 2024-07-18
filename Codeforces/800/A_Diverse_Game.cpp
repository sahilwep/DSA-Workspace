/*

//  A. Diverse Game

// Observations: 
    * We just need to make array in a way that it should not be same as it was previous
    * That means we can swap all the ith upwards..
    * We can swap all the jth left side...

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
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> arr[i][j];
        }
    }
    if(n == 1 && m == 1){
        cout << -1 << endl;
        return;
    }
    // let's shift the all the columns:
    for(int i=0;i<n;i++){
        int temp = arr[i][0];
        for(int j=0;j<m;j++){
            arr[i][j] = arr[i][j+1];
        }
        arr[i][m-1] = temp;
    }
    // let's shift all the rows:
    // // first store the first rows:
    int temp[m];
    for(int i=0;i<1;i++){
        for(int j=0;j<m;j++){
            temp[j] = arr[i][j];
        }
    }
    // swapping all the rows upwards:
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = arr[i+1][j];
        }
    }
    // // updating the last row of array with first row:
    for(int i=n-1;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = temp[j];
        }
    }


    // printing the array:
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << arr[i][j] << " ";
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