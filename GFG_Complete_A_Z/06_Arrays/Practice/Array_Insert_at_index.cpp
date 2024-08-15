/*

// Array insert at index

// Observations: 
    * we are given a index of array, we have to insert element on that specific index.

// TC: O(n)
// AS: O(1)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    void insertAtIndex(int arr[], int n, int idx, int x){
        if(idx >= n || idx < 0) return;    // case when index is out of bound
        else if(idx == n-1){
            arr[idx] = x;
        }
        for(int i=n-1;i>idx;i--){
            arr[i] = arr[i-1];
        }
        arr[idx] = x;
    }
};

int main() {
    int t;
    cin>>t;
    while(t--){
        
        int sizeOfArray; 
        cin>>sizeOfArray;
        
        int arr[sizeOfArray];
    
        for(int i = 0; i < sizeOfArray-1; i++)  cin>>arr[i];
        
        int index;
        cin>>index;

        int element;
        cin>>element;
        
        Solution obj;
        obj.insertAtIndex(arr, sizeOfArray, index, element);
        
        for(int i = 0; i < sizeOfArray; i++)    cout<<arr[i]<<" ";
        
        cout<<endl;
    }
    
    return 0;
}