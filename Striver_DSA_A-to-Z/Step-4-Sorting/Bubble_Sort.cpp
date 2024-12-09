/*

// Bubble Sort:


Approach:
    -> at every iteration maximum will be at last.
The algorithm steps are as follows:

    First, we will select the range of the unsorted array. For that, we will run a loop(say i) that will signify the last index of the selected range. The loop will run backward from index n-1 to 0(where n = size of the array). The value i = n-1 means the range is from 0 to n-1, and similarly, i = n-2 means the range is from 0 to n-2, and so on.
    Within the loop, we will run another loop(say j, runs from 0 to i-1 though the range is from 0 to i) to push the maximum element to the last index of the selected range, by repeatedly swapping adjacent elements.
    Basically, we will swap adjacent elements(if arr[j] > arr[j+1]) until the maximum element of the range reaches the end.
    Thus, after each iteration, the last part of the array will become sorted. Like: after the first iteration, the array up to the last index will be sorted, and after the second iteration, the array up to the second last index will be sorted, and so on.
    After (n-1) iteration, the whole array will be sorted.

Note: Here, after each iteration, the array becomes sorted up to the last index of the range. That is why the last index of the range decreases by 1 after each iteration. This decrement is achieved by the outer loop and the last index is represented by variable i in the following code. And the inner loop(i.e. j) helps to push the maximum element of range [0….i] to the last index(i.e. index i).


*/

#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;


class Solution {
public:
    // Function to sort the array using bubble sort algorithm.
    void bubbleSort(vector<int>& arr) {
        int n = arr.size();
        
        for(int i = n - 1; i >= 0; i--){    // Start iteration from start, because at every iteration of i, maximum element is at last position.
            for(int j = 0 ; j <= i - 1; j++){ // now start from 0 to i range:
                if(arr[j] > arr[j+1]){  // if current element is grater than the next element:
                    swap(arr[j], arr[j+1]); // swap these two values.
                }
            }
        }
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

        ob.bubbleSort(arr);
        for (int e : arr) {
            cout << e << " ";
        }
        cout << endl;
    }
    return 0;
}