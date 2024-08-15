/*
// Array insert at end

// Observations: 
    * We are given an array of size n, which contains n-1, element, we have to insert element at last..
    * As we are given size of array, we can insert element at arr[n-1] position.

*/

#include <bits/stdc++.h>
using namespace std;

void insertAtEnd(int arr[],int sizeOfArray,int element){
    arr[sizeOfArray - 1] = element;
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int sizeOfArray;
        cin>>sizeOfArray;
        int arr[sizeOfArray];
        
        for(int i=0;i<sizeOfArray-1;i++) cin>>arr[i];
        
        int element;
        cin>>element;
        
        insertAtEnd(arr,sizeOfArray,element);
        
        for(int i=0;i<sizeOfArray;i++)
        cout<<arr[i]<<" ";
        
        cout<<endl;
    }

    return 0;
}