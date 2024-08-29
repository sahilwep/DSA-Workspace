/*

// Second Largest
    * We are given an array, & We need to return, second largest if it exist.
    * else return -1, if there is no second largest element in an array.


// Observations: 
    * Sorting: 
        * We can sort the element, & compare the last & second largest element according to the questions, & return accordingly.
        * TC: (nlogn)

    * Using comparing with maintaining pointer:
        * We can maintain largest & secondLargest variable & compare with the every element in an array, & return the second largest if it's exist.
        * TC: O(n)

    * Edge Case: 
        * When we have only single element in an array, we need to return -1.
        * While iterating, if element is lesser than largest & grater than the second largest


*/


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Sorting -> O(n*logn)
    int print2largest_Sorting(vector<int> &arr) {
        int n = arr.size();
        if(arr.size() == 1) return -1;  // if array has only single element, return -1
        sort(arr.begin(), arr.end());
        int largest = arr[n-1];
        // finding the second largest, as it can be at any place in an array: 
        int secondLargest = -1;
        for(int i=n-2;i>=0;i--){
            if(arr[i] < largest){
                secondLargest = arr[i];
                break;
            }
        }

        return min(largest, secondLargest); // returning the minimum among two
    }
    // Approach 2: Maintaining largest & secondLargest pointer -> O(n)
    int print2largest(vector<int> &arr){
        int largest = arr[0];   // assuming element be the largest
        int secondLargest = -1;

        for(int i=1;i<arr.size();i++){
            if(arr[i] > largest){
                secondLargest = largest;
                largest = arr[i];
            }
            // Edge case:
            else if(arr[i] < largest && arr[i] > secondLargest){
                secondLargest = arr[i];
            }
        }
        
        return secondLargest;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.print2largest(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends