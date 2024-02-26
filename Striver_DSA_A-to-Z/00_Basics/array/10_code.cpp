/*
// Matrix Multiplication : 


*/

#include <bits/stdc++.h>
using namespace std;

int main(void){
    int t;
    cin >> t;
    while (t--){
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
        // Operations :
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                arr3[i][j] = 0;
                for(int k=0;k<n;k++){
                    arr3[i][j] += arr1[i][k] * arr1[k][j]; 
                }
                cout << arr3[i][j] << " ";
            }
            cout << endl;
        }

        // // printing : 
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout << arr3[i][j] << " ";
        //     }
        //     cout << endl;
        // }

    }
    return 0;
}