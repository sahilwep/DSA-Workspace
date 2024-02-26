/*
// Operations in array Part 2 : 

// Delete operations : 
    * TC : O(n)

// Example : 
    I/p : arr[] = {3, 8, 12, 5, 6}
    x = 12
    0/p : arr[] = {3, 8, 5, 6, _}
    
    I/p : arr[] = {3, 8, 12, 5, 6}
    x = 6
    0/p : arr[] = {3, 8, 12, 5, _}


*/

#include<bits/stdc++.h>
using namespace std;

int deleteEle(int arr[], int n, int x){
    int i;
    // finding the index position of deleting element
    for(i=0;i<n;i++){
        if(arr[i] == x){
            break;
        }
    }
    if(i==n) return n;  // if deleting element is last element.
    // now shift all the element to left.
    for(int j=i;j<n;j++){
        arr[j] = arr[j+1];
    }
    return (n-1);   // as we delete one element, we return (size-1)
}

int main(void){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int x;
    cin >> x;

    n = deleteEle(arr, n, x);

    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}