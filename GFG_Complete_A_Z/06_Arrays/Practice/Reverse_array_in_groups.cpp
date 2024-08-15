/*

// Reverse array in groups

// Observations: 
    * we are given an array, & integer k
    * we have to reverse the array till kth position(index start from 1)
    * if k > array.size(), reverse entire array as per the question
    * If k is less than the size of array, we have to reverse every every range of k, till the k is exceed the range..

// Intrusion:
    * first we check the k range is smaller or equal to array.size(), if it does we reverse the whole array.
    * If k is lesser than the size of array, we have to swap every portions of k elements of an array:
        * we can use two pointer approach: 
            * first pointer = 0
            * second pointer = k
        * we reverse the portions of element that lies b/w these pointers..
        * After every iterations we increment the first & second pointer with k

// Time Complexity: O(n)
    * As we reverse the every kth element..
    * And we are doing this throughout the array..


// Note: 
    reverse() function first parameter is inclusive, & second parameter is exclusive..

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Method 1: using reverse function: 
    void reverseInGroups(vector<long long int> &arr, int k) {

        int n = arr.size();
        // as we are given if k is grater or equal array size, reverse entire array:
        if(k >= n){
            reverse(arr.begin(), arr.end());
        }
        // when k is smaller than array size:
        else{
            // we have to reverse every k position
            // we will use two pointer approach:
            int i = 0;  // first pointer will point the starting index
            int r = k;  // second pointer will point the end index
            // we are going till last pointer is less or equal to n, means array size
            while(r <= n){
                // as we know first parameter is inclusive, & second parameter is exclusive in reverse() function.
                reverse(arr.begin() + i, arr.begin() + r);
                i += k; // after every reverse, we change increment first pointer with k.
                r += k; // same thing we does with second pointer.
            }
            // at last we have to reverse the left over that not fit in range of i & r
            // first pointer will be 'i' & second pointer will be arr.end() position.
            reverse(arr.begin() + i , arr.end());
        }
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        vector<long long int> arr;
        string input;
        cin.ignore();
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        ob.reverseInGroups(arr, k);
        for (long long i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}