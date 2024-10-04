/*

//  K Sized Subarray Maximum

//  Observations: 
    * We are given an array and integer , find the maximum for each and every contigious subarray of size k.

// Example: 

    Input: k = 3, arr[] = [1, 2, 3, 1, 4, 5, 2, 3, 6]
    Output: [3, 3, 4, 5, 5, 5, 6] 
    Explanation: 
    1st contiguous subarray = [1 2 3] max = 3
    2nd contiguous subarray = [2 3 1] max = 3
    3rd contiguous subarray = [3 1 4] max = 4
    4th contiguous subarray = [1 4 5] max = 5
    5th contiguous subarray = [4 5 2] max = 5
    6th contiguous subarray = [5 2 3] max = 5
    7th contiguous subarray = [2 3 6] max = 6

    Input: k = 4, arr[] = [8, 5, 10, 7, 9, 4, 15, 12, 90, 13]
    Output: [10, 10, 10, 15, 15, 90, 90]
    Explanation: 
    1st contiguous subarray = [8 5 10 7], max = 10
    2nd contiguous subarray = [5 10 7 9], max = 10
    3rd contiguous subarray = [10 7 9 4], max = 10
    4th contiguous subarray = [7 9 4 15], max = 15
    5th contiguous subarray = [9 4 15 12], max = 15
    6th contiguous subarray = [4 15 12 90], max = 90
    7th contiguous subarray = {15 12 90 13}, max = 90


// Intrusion:
    // Deque Approach: 
        * Create a deque of capacity k, that store only useful element of current window of k elements.
        * An element is useful if it is in current window and is grater than all other elements on right side of it's current window.
        * Process all array elements one by one and maintain dq to contain useful elements of current window and these useful element are maintain in sorted order.
        * The element at front of the deque is the largest and element at rear/back of deque is the smallest of current window.
        // Algorithm Design: 
            * Create a deque that store useful element only.
            * Run a loop & insert the first k element in deque.
            * Before inserting the element, check if the element at the back of the deque is smaller that the current element,
            * If it is so remove the element form the back of the deque until all elements left in deque are grater than the current element.
            * Then insert the current element, at the back of the deque. 
            * Now, run a loop from k to the end of the array.
                * Print the front element of the deque,
                * Remove the element from the front of the deque if they are out of the current window.
                * Insert the next element in the deque. 
                    * Before inserting the element, check if the element at the back of the deque is smaller that the current element,
                    * if it is so remove the element from the back of the deque until all elements left in the deque are grater than the curent element.
                    * Then Insert the current element, at the back of the deque.
                * Print the maximum element of the last window.
    

*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

class Solution {
  public:
    // Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int k, vector<int> &arr) {
        vector<int> res;

        // Create a doubly ended queue, i.e deque -> this will store the index of array
        // The deque will store index of useful element in every window & it will maintain
        // decreasing order of values from front to rear -> and stored in decreasing order.
        deque<int> dq(k);

        // Process first k element of array:
        int i = 0;
        for(i;i<k;i++){

            // For every element, the previous smaller element  
            // are useless so, remove form the deque.
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                // Remove from rear:
                dq.pop_back();

            }
            // add element at rear of deque:
            dq.push_back(i);
        }

        // Process the rest of the element, i.e, from a[i] to a[n-1]:
        for(;i<arr.size();i++){

            // The element at the front is larger element of the previous window
            res.push_back(arr[dq.front()]);

            // Remove the element which are out of the window: -> i-k is the window size, if dq.front is less than that size, remove that..
            while(!dq.empty() && dq.front() <= i - k ){
                // remove from the front of the deque:
                dq.pop_front();
            }

            // Remove all the element smaller than the currently being added element (removing useless elements):
            while(!dq.empty() && arr[i] >= arr[dq.back()]){
                dq.pop_back();
            }

            // Add the current element at the rear of deque:
            dq.push_back(i);
        }   

        // Now adding the largest element from last window:
        res.push_back(arr[dq.front()]);


        return res;     // returning the result vector
    }
};

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> res = obj.max_of_subarrays(k, arr);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}