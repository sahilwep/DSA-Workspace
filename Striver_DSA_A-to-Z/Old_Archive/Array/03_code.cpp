/*
// find the second largest element in array : 

// Bruteforce solution : 
    * sort the array
    * largest = arr[n-1]
    * iterate the loop from n-2 to 1 : 
        * if largest == arr[i]
            * don't do anything.
        * if largest != arr[i]
            * assign sLargest = arr[i]
            * break;

// Better approach : 
    * First pass : 
        * find the largest element in first pass..
        * In first half we found the largest element.
    * Second pass : 
        * After finding the largest element, we can iterate the loop from 0 to n-1
        * we can check the condition for, if (arr[element] != largest && arr[element] > slargest)
            * we can assign the slargest = arr[element].

// Optimal Solution : 
    * assign the largest = arr[0]
    * assign the slargest = -1
    * iterate the loop from 0 to n-1
    * check for the condition if arr[i] > largest : 
        * assign the slargest = largest
        * assign the largest  = arr[i]
    * check for the condition if arr[i]< largest, but arr[i] > slargest.
        * assign the slargest = arr[i] 
    
    * at the end of loop, return slargest.



// CONSTRAINS : 
    0 <= t <= 1000
    0 <= n <= 1000
    0 <= A <= 1000

// input : 
1
6
1 2 4 7 7 5
// output : 
5

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

// bruteforce approach : 
    int secondLargest_1(int arr[], int n){
        sort(arr, arr+n);   // sorting the array.
        int largest = arr[n-1]; // assigning the second largest.
        int slargest = -1;
        for(int i=n-2;i>=0;i--){
            // condition when largest is not equal to the arr[element]
            if(largest != arr[i]){
                slargest = arr[i];  // assigning the slargest
                break;
            }
        }
        return slargest;
    }
        // TC : O((n)*(n)log(n))        (iteration + sorting)

// better approach : 
    int secondLargest_2(int arr[], int n){
        // first pass : 
        int largest = -1;
        for(int i=0;i<n;i++){
            if(arr[i]>largest) largest = arr[i];
        }
        // second pass : 
        int slargest = -1;
        for(int i=0;i<n;i++){

            if(arr[i] > slargest && arr[i] != largest){
                slargest = arr[i];
            }
        }
        return slargest;
    }
        // TC :     O(n*n)  => O(2n)

// better approach : 
    int secondLargest_3(int arr[], int n){
        int largest = arr[0];   // assigning the largest as first element of an array.
        int slargest = -1;  
        for(int i=0;i<n;i++){
            if(arr[i]>largest){
                slargest = largest; // storing the previous largest in slargest.
                largest = arr[i];   // storing the new largest value.
            }
            // checking the condition, when the element is greater than slargest, but smaller than largest.
            else if(arr[i] < largest && arr[i] > slargest) slargest  = arr[i];
        }

        return slargest;
    }
        // TC : O(n)  

};

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        Solution obj;
        int res = obj.secondLargest_3(arr, n);
        (res == -1) ? cout << "All element is same! " << endl : cout << res << endl; 

    }

    return 0;
}