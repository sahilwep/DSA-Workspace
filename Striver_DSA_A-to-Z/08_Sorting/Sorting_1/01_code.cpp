/*
// Selection Sort : 
    * Select min, & swap

        array :     13  46  24  52  20  9
        index :     0   1   2   3   4   5

    step 1 : get the min(9), & place it to the first by swapping (13, 9) 
                    9|   46  24  52  20  13 

    step 2 : get the next min(13), & swap after min. (46, 13)
                    9   13|  24  52  20  46  

    -->  till the step 2 our two elements are sorted..

    step 3 : get the next min(20), & swap. (24, 20)
                    9   13  20|  52  24  46  

    step 4 : get the next min(24), & swap (52, 24)
                    9   13  20  24|  52  46  

    step 5 : get the next min(46), & swap (52, 46)
                    9   13  20  24  46|  52
    --> after step 5, no need to sort, because one element is left, so one element is always sorted..


// Observation : 
    * first time swap at index 0, &  min index [0 - n-1]
    * first time swap at index 1, &  min index [1 - n-1]
    * first time swap at index 2, &  min index [2 - n-1]
    * first time swap at index 3, &  min index [3 - n-1]
    *                          i                i - n-1
    *                          i                i - n-1
    *                          i                i - n-1
    *                          
    *                    index (n-2)            i - n-1     
    * outer loop from : 0-(n-2), inner loop from  i - n-1
    
// pseudo-code :

    for(i = 0;i<=n-2;i++){
        mini  = i;  // 
        for( j = i;j<=n-1;j++){
            if(arr[j]< arr[mini]){
                mini = j
            }
        }
        swap(arr[mini], arr[i]) // swap with the first guy.
    }


*/
#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int n){
    for(int i=0;i<=n-2;i++){
        int mini = i;   // lets consider our minimum value is at array[i], then find the mini with nested loop.
        // finding the minimum in nested loop. 
        for(int j=i;j<=n-1;j++){
            if(arr[j] < arr[mini]){
                mini = j;   // we found the minimum value.
            }
        }
        // lets swap with the first index with the minimum value.
        swap(arr[mini], arr[i]);    // swap the minimum with arr[i]
    }
}


int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        selectionSort(arr, n);
        for(auto i : arr) cout << i << " ";
        cout << endl;
    }

    return 0;
}