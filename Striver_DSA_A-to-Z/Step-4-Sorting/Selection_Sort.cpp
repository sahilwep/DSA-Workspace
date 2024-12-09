/*

// Selection Sort


Approach:
    -> Select minimum, & place it in order....

The algorithm steps are as follows:

    First, we will select the range of the unsorted array using a loop (say i) that indicates the starting index of the range.
    The loop will run forward from 0 to n-1. The value i = 0 means the range is from 0 to n-1, and similarly, i = 1 means the range is from 1 to n-1, and so on.
    (Initially, the range will be the whole array starting from the first index.)
    Now, in each iteration, we will select the minimum element from the range of the unsorted array using an inner loop.
    After that, we will swap the minimum element with the first element of the selected range(in step 1). 
    Finally, after each iteration, we will find that the array is sorted up to the first index of the range. 

Note: Here, after each iteration, the array becomes sorted up to the first index of the range. That is why the starting index of the range increases by 1 after each iteration. This increment is achieved by the outer loop and the starting index is represented by variable i in the following code. And the inner loop(i.e. j) helps to find the minimum element of the range [i…..n-1].


// Complexity:
    * TC: O(n^2)
    * AS: O(1)


*/


#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


class Solution {
  public:
    // Function to perform selection sort on the given array.
    void selectionSort(vector<int> &arr) {
        int n = arr.size();
        
        for(int i = 0; i < n - 1; i++){
            int minElement = i;
            for(int j = i + 1; j < n; j++){
                if(arr[j] < arr[minElement]){ // if we get any minimum element
                    minElement = j;   // updating minimum index found so far
                }
            }
            // Now swap:
            swap(arr[minElement], arr[i]);    // swap minimum found element with current array element
        }
    }
};


int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution obj;
        obj.selectionSort(a);

        Array::print(a);
        cout << "~" << endl;
    }
}

// } Driver Code Ends