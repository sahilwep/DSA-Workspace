/*
// Move all zeroes to the end of array.

    arr[]  =  1 0 2 3 2 0 0 4 5 1

    temp[] =  1 2 3 2 4 5 1

   final[] =  1 2 3 2 4 5 1 0 0 0

// Bruteforce Solution :
    * make a temp array, store non-zeroes element.
    * after reassign the non-zeroes into the original array
    * then at rest position assign zeroes..

// Optimal : 
    * Using 2 pointer method : 
        * find the first 0 number and assign the i.
        * then iterate the j & find the non-zero number & assign it,
        * whenever we found the non-zero number, swap with i, & increment it.
        * same for the each step.

// input : 
1 
10
1 0 2 2 0 1 4 0 1 0
// output : 
1 2 2 1 4 1 0 0 0 0 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void moveZeroesEnd_1(int arr[], int n);
    void moveZeroesEnd_2(int arr[], int n);

};

// bruteforce : 
void Solution::moveZeroesEnd_1(int arr[], int n){
    // store the non-zero elements.
    vector<int> temp;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            temp.push_back(arr[i]);
        }
    }
        // TC  : O(N)
    // restoring the non-zeroes  into the original array.
    for(int i=0;i<temp.size();i++){
        arr[i] = temp[i];
    }
        // TC : O(x)
    // after that storing the 0's after the remaining places..
    for(int i=temp.size();i<n;i++){
        arr[i] = 0;
    }
        // TC : O(n-x)

    /*
        TC : O(N) + O(x) + O(n-x)   => O(2n)
        SC : O(x) --> O(n)(worst case)
    */
}

// Optimal : 
void Solution::moveZeroesEnd_2(int arr[], int n){
    // step 1 : This will make sure the j will be at the first 0 number.
    int j=-1;
    for(int i=0;i<n;i++){
        if(arr[i]==0){
            j = i;
            break;
        }
    }
    // if j=-1, means all the elements are non-zero.
    // step 2 : finding the non-zero & swap, then increment the j pointer to the next.
    if(j != -1){
        for(int i=j+1;i<n;i++){
            if(arr[i] != 0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }

    // TC : O(x) first length where we found the first 0, Then we move remaining O(n-x)
    // TC : O(x) + O(n-x)     => O(n)
}


int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >>n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        Solution obj;
        obj.moveZeroesEnd_2(arr, n);
        for(int i=0;i<n;i++) cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
