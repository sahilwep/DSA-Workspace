/*

// Rotate Array:

// Observation:
    * We are given array of size n, we need to left rotate the array of given d position..

// Key Observations: 
    * For given d position, we need to get the range in modulo..
    * if d is greater than the size, we need to get he modulo of that with n, in order to get the rounded value..

// Example: 
    Input: n = 5, d = 2 arr[] = {1,2,3,4,5}
    Output: 3 4 5 1 2
    Explanation: 1 2 3 4 5  when rotated by 2 elements, it becomes 3 4 5 1 2.
    
    Example Observations:

            * In case when d <= n
                Original array: 1 2 3 4 5,  d = 2
                    reverse 0 to d & d to n-1
                                2 1 5 4 3
                    reverse 0 to n-1
                                3 4 5 1 2

            * In case when d > n
                round the value of d: d = d % n
                Original array: 1 2 3 4 5,  d = 7
                    round = 7 % 5 => 2
                    reverse 0 to d & d to n-1
                                2 1 5 4 3
                    reverse o to n-1
                                3 4 5 1 2

        * In conclusion we can we have to round d with n, i.e (d = d % n)

*/


#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void rotateArr(int arr[], int d, int n){
        d = d % n;
        reverse(arr, arr+d);    // first reverse 0 to d elements
        reverse(arr+d, arr+n);  // reverse from d to n
        reverse(arr, arr+n);    // the reverse the whole array
    }
};

int main() {
    int t;
    cin >> t;

    while(t--){
        int n, d;
        cin >> n >> d;

        int arr[n];
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        Solution ob;
        ob.rotateArr(arr, d,n);

        for(int i =0;i<n;i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    return 0;
}