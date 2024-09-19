/*

// Count only Repeated

// Observations: 
    * We are given an array of n positive integer, where elements are consecutively sorted.
    * Also there is single element that is repeating x(any integer) number of times.
    * Now task is to find the element which is repeated and number of times it is repeated.
    * NOTE: if there is no repeating element return {-1, -1}


// Examples

    Input: n = 5, arr[] = {1,2,3,3,4}
    Output: 3 2
    Explanation: In the given array, 3 is occurring two times.

    Input: n = 5, arr[] = {2,3,4,5,5}
    Output: 5 2
    Explanation: In the given array, 5 is occurring two times.

    Input: n = 3, arr[] = {1,2,3}
    Output: -1 -1
    Explanation: In the given array, there's no repeating element, and thus the given Output.

// Intrusion: 
    // Bruteforce Approach:
        * We can select each element one by one & count the number of occurrence, whenever we have repeated element, we will return that number & count.
        * O(n^2) -> TLE
    
    // Hashing Approach: 
        * Store the frequency of each element, then pick the element that is repeated..
        * TC: O(n)
        * AS: O(n)


    // Searching Method:
        * We need to find two things:
            To find the number of times the element repeats:
                Suppose there is no repeated element for given, then the least element will be at arr[0] and highest element will be the arr[n-1].
                Now each time an element is repeated the highest element will decrease by 1 each time.
                Based on this idea since the array is sorted and max-different of two adjacent element is 1, then:

            Count the unique elements = arr[n-1] - arr[0]
            Therefore, the length of repeated element = n - count of unique elements = n - (arr[n-1] - arr[0])

            To find value of repeated element:
                To find the repeated value, we can use Binary Search

        * In Simple Word: 
            * Condition 0: if two consecutive elements are same, we have found the duplicate element.
            * Condition 1: arr[mid] >= mid + arr[0]
                * The key insight here is that, in a sorted array without duplicates, every element at index i should satisfy arr[i] == i + arr[0].
                * If arr[mid] >= mid + arr[0], then no repeating element exists in the left half (start..mid). Thus, shift the search window to the right (start = mid + 1).
            * Condition 2: arr[mid] < mid + arr[0]
                * If arr[mid] < mid + arr[0], there is a repetition in the left half, so the search window is adjusted to focus on that part by setting end = mid.
            * Extracting the Result:
                * After the binary search completes, start will point to the repeating element in the array. So p.first = arr[start] assigns the repeating element to the result.
                * To compute how many times the element repeats:
                    * The range of unique elements should be (arr[n-1] - arr[0] + 1). However, the actual number of unique elements is less by n - (arr[n - 1] - arr[0]). This difference gives us the count of repetitions, which is assigned to p.second.

        * TC: O(logn), if we exclude the count.
        * TC: O(n)


*/

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution{
public:
    // Bruteforce Approach: O(n^2) -> TLE
    pair<long, long> findRepeating_Brute(long *arr, int n){
        int num = -1;
        int cnt = -1;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=i;j<n;j++){
                if(arr[i] == arr[j]) count++;
            }
            if(count > 1){
                cnt = count;
                num = arr[i];
                break;
            }
        }

        pair<long, long> p;
        p.first = num;
        p.second = cnt;

        return p;
    }

    // Hashing Approach: O(n)
    pair<long, long> findRepeating_Hashing(long *arr, int n){
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++) mp[arr[i]]++;

        pair<long, long> p;
        for(auto i: mp){
            if(i.second > 1){
                p.first = i.first;
                p.second = i.second;
                return p;
            }
        }

        p.first = -1;
        p.second = -1;
        return p;
    }
    // Binary Search: O(logn)
    pair<long, long> findRepeating(long *arr, int n){

        pair<long, long> p;
        if(n == 0){
            p.first = -1;
            p.second = -1;
            return p;
        }
        
        // Binary Search:
        int start = 0;
        int end = n-1;
        long repeating_Element = -1;

        while(start < end){
            int mid = (start + end)/2;

            // If the element at mid is equal to the next element, we have found the repetitions
            if(arr[mid] == arr[mid+1]){
                repeating_Element = arr[mid];
                break;
            }
            
            // Standard Binary Search Conditions:
            // if arr[mid] = mid + arr[0], there is no repeating element in range [start..mid]
            if(arr[mid] >= mid + arr[0]){
                start = mid + 1;
            }
            // if arr[mid] <  mid + arr[0], there is repeating element in range [start..mid]
            else{
                end = mid;
            }
        }

        if(repeating_Element == -1){
            p.first = -1;
            p.second = -1;
            return p;
        }

        // Count the no of occurrence:
        int cnt = 0; 
        for(int i=0;i<n;i++){
            if(arr[i] == repeating_Element) cnt++;
        }

        p.first = repeating_Element;
        p.second = cnt;

        return p;
    }
};

int main() {
	int t;
	cin >> t;
	
	while(t--){
	    int n;
	    cin >> n;
	    long arr[n];
	    
	    for(int i = 0;i<n;i++){
	        cin >> arr[i];
	    }
	    Solution obj;
	    pair<long, long> ans = obj.findRepeating(arr,n);
	    cout << ans.first << " " << ans.second << endl;   
	}	
}