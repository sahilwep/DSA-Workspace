/*
// Largest Element of an array :

I/p : arr[] = [10, 5, 20, 8]
O/p : 2 // return index of largest element


// efficient solution: 
    * Let's assume our largest element is at index 0, then iterate through out the array, if we find any largest value grater than assumed value, just update with it.


*/

#include <bits/stdc++.h>
using namespace std;

// Bruteforce Solution: TC : O(n^2)
int largestElement(int arr[], int n){
    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<n;j++){
            if(arr[j] > arr[i]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            return i;
        }
    }
    return -1;
}

// Efficient solution: TC : O(n)
int largestElement_1(int arr[], int n){
    int largest = 0;
    for(int i=1;i<n;i++){
        if(arr[i] > arr[largest]) {
            largest = i;
        }
    }
    return largest;
}


int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << "index: " << largestElement_1(arr, n);

    return 0;
}