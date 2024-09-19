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
    Explanation: In the given array, 3 is occuring two times.

    Input: n = 5, arr[] = {2,3,4,5,5}
    Output: 5 2
    Explanation: In the given array, 5 is occuring two times.

    Input: n = 3, arr[] = {1,2,3}
    Output: -1 -1
    Explanation: In the given array, there's no repeating element, and thus the given Output.

// Intrusion: 
    // Bruteforce Approach:
        * We can select each element one by one & count the number of occurrence, whenever we have repeated element, we will return that number & count.
        * O(n^2) -> TLE
    


*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    // Bruteforce Approach: O(n^2) -> TLE
    pair<long, long> findRepeating(long *arr, int n){
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