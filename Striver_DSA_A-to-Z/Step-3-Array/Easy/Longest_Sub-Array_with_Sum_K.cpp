/*

// Longest Sub-Array with Sum K

// Observations: 
    * Given an array containing n integer and an integer k.
	* Our task is to find the length of longest Sub-array with the sum of the elements equal to the given value k.
	* 

// Examples:

	Input :	arr[] = {10, 5, 2, 7, 1, 9}, k = 15
	Output : 4
		Explanation: The sub-array is {5, 2, 7, 1}.

	Input : arr[] = {-1, 2, 3}, k = 6
	Output : 0
		Explanation: There is no such sub-array with sum 6.


// Observations: 
    // Bruteforce: 
        * We will use nested loop approach & try to find the sub-array sum with maximum size.
        * We will iterate over & try to find the value, & sore it in maxSubarray
        * Example Observations:
                * Getting counter: 
                        j - i + 1 -> this computes the length of subarray given it's starting index i & ending index j
                        
                        j(current) - i(starting) + 1(because including both the end point)

                * Example: arr [10, 5, 2, 7, 1, 9]
                * Suppose we want to find the length of subarray starting index 2, & ending index 4
                    * Starting index: 2 -> 2(value)
                    * ending index: 4 -> 1(value)
                    * Compute: 
                        4 - 2  + 1 = 3 (size of subarray)

        * TC: O(n^2)    -> TLE

    // Efficient Approach: 
        * We can use hashing & prefix sum logic: 
            * We can use hashing & prefix sum logic to find the longest maxSum.
        * TC: O(n)
        * AS: O(n)

*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Efficient Approach: O(n)
    int lenOfLongSubarr(int arr[],  int n, int k){
        map<int, int> mp; // declare the map to hash the prefix sum
        int prefixSum = 0;
        int maxLen = 0;

        for(int i=0;i<n;i++){
            // calculating the prefix sum:
            prefixSum += arr[i];


            // Operations for finding the maxLength:
            // When prefixSum itself equal to k, we can set maxLen = i+1
            if(prefixSum == k){
                maxLen = i + 1;
            }
            // If (prefixSum - k) is found in hashmap
            else if(mp.find(prefixSum - k) != mp.end()){
                maxLen = max(maxLen, i - mp[prefixSum - k]);    // store the maximum length.
            }


            // Operations for storing the prefixSum int hashmap:
            // Store the prefixSum into hashmap if not already present
            if(mp.find(prefixSum) == mp.end()){
                mp[prefixSum] = i;  // Store the prefixSum in hashmap
            }
        }

        return maxLen;
    }

    // Bruteforce Approach: O(n^2)
    int lenOfLongSubarr_Brute(int arr[],  int n, int k){
        int maxSubarray = 0;
        for(int i=0;i<n;i++){
            int currSum = 0;
            for(int j=i;j<n;j++){
                currSum += arr[j];  // at every iteration we will sum up the value into currSum
                // if currSum == given value
                if(currSum == k){
                    // Updating the maxSubarray
                    /*
                        j - i + 1 -> this computes the length of subarray given it's starting index i & ending index j
                        
                        j(current) - i(starting) + 1(because including both the end point)
                    
                    */
                    maxSubarray = max(maxSubarray, j - i + 1);  // storing the maximum among maxSubarray previous & (j-i + 1)
                }
            }
        }

        return maxSubarray;
    } 
};



int main() {
	int t;
    cin>>t;
	while(t--){
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++) cin>>a[i];
        Solution ob;
        cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	}
	
	return 0;
}