/*
// find the largest element in array : 

// bruteforce solution :
    * largest element is found in last of an array : 
    * first we need to sort an array : 
    * after that we need to access the last element of an array 
        * TC : sorting takes : O(n*log(n)) 
        * accessing takes : unit operation.
    * TC : O(n*log(n))

// better solution : 
    * In first pass we will find the largest element of an array : 
        * assuming the first element be the largest element, 
        * iterating the loop from (1-n).
        * checking the condition if any (arr[i]) element is grater than the largest element, update the largest element. 
    * TC : O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
// BruteForce Solution : 
    int largestElement_1(int arr[], int n){
        int res =0;
        sort(arr, arr+n);   // sorting the array : 
        return arr[n-1];    // returning the last element of an array :
    }
    // TC : O(n*log(n))

// Better Solution : 
    int largestElement_2(int arr[], int n){
        int largest = arr[0];   // assuming the first element be the largest.
        for(int i=1;i<n;i++){
            // condition for checking the largest element in an array : 
            if(arr[i]> largest) largest = arr[i];
        }
        return largest;
    }
};

int main(void){
    int t;
    cin >> t;   // test case : 
    while(t--){
        int n;  
        cin >> n;   // size of an array :
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];     // input in array 
        Solution obj;
        cout << obj.largestElement_1(arr, n) << endl;     // calling the function : 
    }

    return 0;
}