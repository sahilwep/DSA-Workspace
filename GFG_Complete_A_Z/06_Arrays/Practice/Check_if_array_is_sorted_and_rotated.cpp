/*

// Check if array is sorted and rotated

// Observations: 
    * we are given array of size n, we have to check if the array is sorted(non-increasing or non-decreasing) and rotated counter clockwise.
    * Note the input array may be sorted in increasing or decreasing order, then rotated
    * A sorted array is considered as sorted and rotated, i.e there should be atleast one rotations..
    // Example: 
        Input:  N = 4   arr[] = {3,4,1,2}
        Output: Yes
        Explanation: The array is sorted 
            (1, 2, 3, 4) and rotated twice 
            (3, 4, 1, 2).

// Key Observations: 
    * As we know, a sorted array of n elements (which can be obtained duplicates) follows the property where the previous element is smaller or equal to the current element.
    * So, if we rotate it by some point(Clockwise or Counter-Clockwise), there exist a pivotal point where the previous element is grater than the current element.
    * If there exist at-most one occurrence of pivot, then we can say array is rotated & sorted.
    * In Conclusion we can say, if our array is sorted rotated once, we can have our value true, else false.

// Intrusion: 
    * We can check the array for sorted ascending & descending order..
    * If our ascending & descending order function checker will return the counter 1,
    * We can say that array is sorted & rotated...
    * If any of the counter is not equal to 1, we can't say array is sorted & rotated...

// TC: O(n)
// AS: O(1)

*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    // Solution that Comes in my mind first: 
    // function to check for array is descending, & rotated
    int isDescending(int arr[], int n){
        int cnt = 0;
        for(int i=1;i<n;i++){
            // if previous element is lesser than the current element
            if(arr[i-1] < arr[i]){
                cnt++;  // increase the counter
            }
        }
        return cnt;
    }
    // function to check for array is ascending, & rotated
    int isAscending(int arr[], int n){
        int cnt = 0;
        for(int i=1;i<n;i++){
            if(arr[i-1] > arr[i]){
                cnt++;
            }
        }
        return cnt;
    }
    bool checkRotatedAndSorted(int arr[], int n){
        int isAsc = isAscending(arr, n);
        int isDes = isDescending(arr, n);
        // if we get any of these one or both one, we can say array is sorted & rotated
        if(isAsc == 1 || isDes == 1){
            return 1;
        }
        return 0;
    }

    // Same Solution in simple way:
    bool checkRotatedAndSorted_(int arr[], int num){
        int incCnt = 0; // to check if the array is sorted in increasing order
        int decCnt = 0; // to check if the array is sorted in decreasing order

        // check if the array is sorted in increasing order and rotated
        for(int i=0;i<num;i++){
            if(arr[i] > arr[(i + 1) % num]){
                incCnt++;
            }
        }

        // check if the array is sorted in decreasing order and rotated
        for(int i=0;i<num;i++){
            if(arr[i] < arr[(i + 1) % num]){
                decCnt++;
            }
        }
        
        // for a sorted & rotated array, there should be exactly one point of rotations
        if(incCnt == 1 || decCnt == 1){
            return true;
        }
        return false;
    }
};

int main(){
    int T;
    cin>> T;

    while (T--){
        int num;
        cin>>num;
        int arr[num];

        for(int i = 0; i<num; ++i)  cin>>arr[i];

        bool flag = false;
        Solution ob;

        flag = ob.checkRotatedAndSorted(arr, num);

        if(!flag) cout << "No"<<endl;
        else cout << "Yes"<<endl;
    }

    return 0;
}