/*
# Hashing : It's a technique where, we store the frequency of number coming in the list.
    * for performing : 
        * We need to create hash[] array. of size of (array + 1)
        * Precompute or pre-storing the hash-array.
        * Fetching the values from the hash array.
    
// Limitation : 
    * we can't declare array with size 10^9
    * there are limitation : 
        * the max size we can declare of array size is : 10^6 inside main.
        * if we declare size 10^7, it will throw segmentation fault.
        * In global we can declare with size 10^7
        * for boolean inside main : (10^7)  
        * for boolean in global : (10^8)  

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void hash_func(int arr[], int n){
        // precomputation : 
        int hash[n+1] = {0};
        for(int i=0;i<n;i++){
            // Storing the frequency.
            hash[arr[i]] = hash[arr[i]] + 1;
        }
        // fetching : 
        int times;
        cin >> times;
        while(times--){
            int num;
            cin >> num;
            // fetching : 
            cout << hash[num] << endl;
        }


    }
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
        obj.hash_func(arr, n);
    }

    return 0;
}