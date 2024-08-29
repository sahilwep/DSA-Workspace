/*
Merging of two array : 

*/

#include <bits/stdc++.h>
using namespace std;

void mergeTwoArray(int arr1[], int arr2[], int n, int m){
    int k = m+n;
    int arr3[k];
    int ind;
    for(int i=0;i<n;i++){
        arr3[i] = arr1[i];
        ind = i;
    }
    
    ind++;

    for(int i=0;i<m;i++){
        arr3[ind] = arr2[i];
        ind++;
    }

    for(auto i : arr3) cout << i << " ";

}

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int arr_1[n];
        int arr_2[n];
        for(int i=0;i<n;i++) cin >> arr_1[i];
        for(int i=0;i<n;i++) cin >> arr_2[i];
        mergeTwoArray(arr_1, arr_2, n, m);
    }

    return 0;
}