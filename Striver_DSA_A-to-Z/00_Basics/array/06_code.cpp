/*
// Deletion in array

    arr[] = 1 2 3 4 5
    delete 3
    arr[] = 1 2 4 5

*/

#include <bits/stdc++.h>
using namespace std;

void deleteElement(int arr[], int n, int target){
    int ind = -1;
    
    for(int i=0;i<n;i++){
        if(arr[i] == target){
            ind = i;
            break;
        }
    }

    if(ind != -1){
        for(int i=ind;i<n;i++){
            arr[i] = arr[i+1];
        }
        for(int i=0;i<n-1;i++) cout << arr[i] << " " ;
    }
    else{
        for(int i=0;i<=n-1;i++) cout << arr[i] << " " ;
    }
}

int main(void){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        int target;
        cin >> target;
        deleteElement(arr, n, target);
    }

    return 0;
}
