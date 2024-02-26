/*
// Insertion Sort :  Takes an element and place it in it's correct place.

            select outer loop i=0 & j=i, if j>0 swap (arr[j], arr[j-1]]) j--
            select outer loop i=1 & j=i, if j>0 swap arr[1, 0]  j--
            select outer loop i=2 & j=i, if j>0 swap arr[2, 1]  j--
            select outer loop i=3 & j=i, if j>0 swap arr[3, 2]  j--
            select outer loop i=4 & j=i, if j>0 swap arr[4, 3]  j--
            --------------------------------------------------
            --------------------------------------------------
            select outer loop i=n-1 & j=i, if j>0 swap arr[(n-1), (n-2)] j--



    // TC : O(n) in best case, when elements are already sorted.
          : O(n^2) in worst case, when elements are not sorted.

*/

#include <bits/stdc++.h>
using namespace std;

// insertion sort : 
void insertionSort(int arr[], int n){
    for(int i=0;i<=n-1;i++){
        int j = i;
        while(j>0 && arr[j-1] > arr[j]){
            // swap
            swap(arr[j], arr[j-1]);
            j--;
        }
    }


}

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    insertionSort(arr, n);

    for(auto i : arr) cout << i << " ";

    return 0;
}
