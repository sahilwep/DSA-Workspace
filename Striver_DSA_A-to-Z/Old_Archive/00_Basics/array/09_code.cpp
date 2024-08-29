/*
// matrix Addition : 

// LOGIC : 
        0  4         3  2               0+3  4+2            3  6
                 +              =>                  =>      
        1  3         5  1               1+5  3+1            6  4


*/

#include <bits/stdc++.h>
using namespace std;


int main(void){
    int t;
    cin >>t;
    while(t--){
        int n,m;
        cin >> n >> m;
        int arr1[n][m], arr2[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> arr1[i][j];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) cin >> arr2[i][j];
        }


        int arr3[n][m];

        // operation : 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr3[i][j] = arr1[i][j] + arr2[i][j];
            }
        }

        // printing : 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << arr3[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}