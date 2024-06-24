/*
// Trapping Rain Water:
    * We are given an array of non-negative integer.
    * Values represent in an array are hight of bars, so we have different bars of different size.
    * We have to compute how much bars of hight we can collect water.

    I/p: arr[] = {2, 0, 2}
    O/p: 2
    Explanation:        
      bar 2         |  W  |
      bar 1         |  W  |
      bar 0         _  _  _
      bar size      2  0  2
        * W = Water inside.
        * here we have space of 2 bars of water inside.



    I/p: arr[] = {3, 0, 1, 2, 5}
    O/p: 6
    Explanation:
      bar 5                     |
      bar 4                     |
      bar 3         |  W  W  W  |
      bar 2         |  W  W  |  |
      bar 1         |  W  |  |  |
      bar 0         _  _  _  _  _
      bar size      3  0  1  2  5
        * W = Water inside.
        * here we have space of 6 bars of water inside.


    I/p: arr[] = {1, 2, 3}      // increasing
    O/p: 0
    Explanation:        
      bar 3               |
      bar 2            |  |
      bar 1         |  |  |
      bar 0         _  _  _
      bar size      1  2  3 
        * W = Water inside.
        * here we have space of 0 bars of water inside.



    I/p: arr[] = {3, 2, 1}      // decreasing
    O/p: 0
    Explanation:        
      bar 3         |      
      bar 2         |  |  
      bar 1         |  |  |
      bar 0         _  _  _
      bar size      3  2  1 
        * W = Water inside.
        * here we have space of 0 bars of water inside.

// Naive Solution: 
    * For outer iteration of i, for every element: 
        * We find the left max element & 
        * We find the right max element.
        * At end of the finding we will subtract min(Lmax, Rmax) - arr[i]
    * TC : O(n^2)


// Efficient Solution: 
    * The idea is to precompute the leftmax & rightmax
    * Rather than to computing every time, we pre compute it to theta(n) times.
    * After precomputing, we did the same approach as we did in Naive solution, i.e (min(lmax[i], rmax[i]) - arr[i])
    * TC : O(n)
    * AS : O(n)

*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: TC = O(n)
int totalWater(int arr[], int n){
    // precompute Left Max:
    int res = 0;
    int lmax[n];
    lmax[0] = arr[0];   // assigning first lmax element as arr[0]
    // starting from 1 --to-->n-1
    for(int i=1;i<n;i++){   
        lmax[i] = max(arr[i], lmax[i-1]);   // comparing the array element with the previous stored element of lmax[] array.
    }

    // precompute Right Max:
    int rmax[n];
    rmax[n-1] = arr[n-1];   // assigning last rmax element as arr[n-1]
    for(int i=n-2;i>=0;i--){
        rmax[i] = max(arr[i], rmax[i+1]);   // we are getting the max of arr[i] & previous stored rmax[i+1] element, we are doing [i+1], because we are iteration our loop from (n-1 --> 0) i.e right to left.
    }

    // Processing of solution:
    // we start our loop from 1 --to--> n-1
    for(int i=1;i<n;i++){
        res = res + (min(lmax[i], rmax[i]) - arr[i]);   // we are getting the minimum value from the min(lmax[i], rmax[i]) & subtract arr[i] from them & store it in the res.
    }
    return res;
}


// Naive Solution: TC = O(n^2)
int totalWater_1(int arr[], int n){
    int res = 0;
    // we start from 1 --to--> n-2, Because last bar can't hold water itself alone.
    for(int i=1;i<n-1;i++){
        // finding the left max size of every arr[i]
        int lmax = arr[i];
        for(int j=0;j<i;j++){   // this start from 0, & goes value before i.
            lmax = max(lmax, arr[j]);   // using the max() function, to find the left side maximum bar.
        }

        // finding the right max size of every arr[i]
        int rmax = arr[i];
        for(int j=i+1;j<n;j++){
            rmax = max(rmax, arr[j]);   // storing the right side maximum value.
        }
        res = res + ( min(lmax, rmax) - arr[i]);    // we use the min() function, because min value of bar can hold water, & we are subtracting arr[i], to remove the bar space & storing in res.
    }
    return res;
}

int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << totalWater(arr, n);

    return 0;
}