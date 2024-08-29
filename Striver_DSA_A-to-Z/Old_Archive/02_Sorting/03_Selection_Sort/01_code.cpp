/*
// Selection Sort : Select minimum & swap

                swap at index 0 & mini[0-n-1]
                swap at index 1 & mini[1-n-1]
                swap at index 2 & mini[2-n-1]
                swap at index 3 & mini[3-n-1]
                .............................
                .............................
                swap at index (n-2) & mini[(n-2)-(n-1)]

*/

#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        // find minimum
        int mini = i;
        for(int j=i;j<=n-1;j++){
            if(arr[j] < arr[mini]){
                mini = j;
            }
        }
        // swap : 
        int temp = arr[i];
        arr[i] = arr[mini];
        arr[mini] = temp;
    }

}


int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    selectionSort(arr, n);

    for(auto i : arr) cout << i << " ";

    return 0;
}