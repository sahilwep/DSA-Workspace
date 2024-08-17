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
    
    // Efficient Solution: 
        * We will use two array leftMin & rightMax that will help us to find the maximum difference..
        * We will maintain leftMin & rightMax array that contains minimum element from left to right, & maximum element from right to left
            // Example: 
                34 8 10 3 2 80 30 33 1

                    leftMin = 34 8 8 3 2 2 2 2 1    -> i
                    rightMax = 80 80 80 80 80 80 33 33 1    -> j

        * Traverse leftMin[] & rightMax to find the maximum of (j - i)
                    i = 0, j = 0, maxDiff = 0
                    if(leftMin[i] <= rightMax[j])
                        store maxDiff -> j -1
                        j++
                    else
                        i++
        * Example Observations: 

                34 8 10 3 2 80 30 33 1

                    leftMin = 34 8 8 3 2 2 2 2 1    -> i
                    Idx       0  1 2 3 4 5 6 7 8

                    rightMax = 80 80 80 80 80 80 33 33 1    -> j
                    Idx        0  1  2  3  4  5  6  7  8

                    (leftMin[i] <= rightMax[j]) i = 0, j = 0, maxDiff = 0, j++
                    (leftMin[i] <= rightMax[j]) i = 0, j = 1, maxDiff = 1, j++
                    (leftMin[i] <= rightMax[j]) i = 0, j = 2, maxDiff = 2, j++
                    (leftMin[i] <= rightMax[j]) i = 0, j = 3, maxDiff = 3, j++
                    (leftMin[i] <= rightMax[j]) i = 0, j = 4, maxDiff = 4, j++
                    (leftMin[i] <= rightMax[j]) i = 0, j = 5, maxDiff = 5, j++
                    (leftMin[i] > rightMax[j]) i = 0, j = 6, maxDiff = 5, i++
                    (leftMin[i] > rightMax[j]) i = 1, j = 6, maxDiff = 5, i++
                    ...
                    ...
                    ...
                    At last we will have maximum difference 5

        * These pointer approach will help us to find the maximum difference..
        * Because we are iterating these pointer according to our condition & need..
        * TC: O(n)
        * AS: O(n)

    
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // bruteforce solution:
    int maxIndexDiff_Brute(vector<int>& arr){
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

    // Efficient Solution: 
    int maxIndexDiff(vector<int> arr){
        int n = arr.size();
        if( n <= 1) return 0;

        vector<int> leftMin(n);
        vector<int> rightMax(n);
        
        // fill leftmin[] such that leftmin[i] contain minimum value from left arr[0] to arr[i]
        leftMin[0] = arr[0];
        for(int i=1;i<n;i++){
            leftMin[i] = min(leftMin[i-1], arr[i]);
        }

        // fill rightMas[] such that rightmax[i] contains maximum value from right  arr[0] to arr[i]
        rightMax[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--){
            rightMax[i] = max(rightMax[i+1], arr[i]);
        }

        // Traverse leftMin[] & rightMax[] to find the maximum of (j - i)
        int i = 0, j = 0, maxDiff = 0;  // we will use two pointer that will help us to find the maxDifference
        while(i < n && j < n){
            // if leftMin element is less or grater than the rightMax, we will increase rightMax pointer till we get the maximum difference..
            if(leftMin[i] <= rightMax[j]){
                maxDiff = max((j - i), maxDiff);
                j++;    // increase rightMax pointer
            }
            // if leftMin[i] value is maximum than the rightMax[i], we increment the leftMin pointer..
            else{
                i++;
            }
        }

        return maxDiff;
    }
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