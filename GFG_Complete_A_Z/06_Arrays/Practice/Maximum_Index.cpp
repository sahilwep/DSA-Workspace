/*

// Maximum Index

// Observations: 
    * we are given an array that contains positive integer
    * Our task is to return the maximum of j-i, 
    * subjected to the constrains of arr[i] <= arr[j] & i <= j


// Intrusion: 
    // Bruteforce Solution: 
        * We can use nested loop,
            * outer loop will iterate from 0 to n-1
            * inner loop will iterate from n-1 to 0
        * At every iterations, we will compare the given condition,
              arr[i] <= arr[j] 
              j - i => should be maximum

        * TC: O(n^2)
    
    // Better Solution: 

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // bruteforce solution:
    int maxIndexDiff(vector<int>& arr){
        int n = arr.size();
        int maxDiff = 0;    // create a maxDiff that will contain the maximum difference..

        // iterate from 0 to n-1
        for(int i=0;i<n;i++){
            // iterate from n-1 to 0
            for(int j=n-1;j>=0;j--){
                // if left side element is smaller or equal to right side
                // and ( j - i ) > previous maxDiff result, then we can change the maxDiff
                if(arr[i] <= arr[j] && maxDiff < (j - i)){
                    maxDiff = j-i;
                }
            }
        }
        return maxDiff; // return the maxDiff
    }
    // Better Solution: 
    
};


int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        cout << ob.maxIndexDiff(nums) << endl;
    }

    return 0;
}