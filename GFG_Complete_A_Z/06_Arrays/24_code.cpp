/*
// Majority Element: 
    * Element in an array is called majority element, if it's appears more than n/2 times of size of an array.
    * Example : if size is 5 : majority element should appears 3 times.
    * Example : if size is 6 : majority element should appears 4 times.
    

    I/p : arr[] = {8, 3, 4, 8, 8}
    O/p : 0 or 3 or 4, (any index of 8) 

    I/p : arr[] = {3, 7, 4, 7, 7, 5}
    O/p : -1 (No majority value)

    I/p : arr[] = {20, 30, 40, 50, 50, 50, 50}
    O/p : 3 or 4 or 5 or 6 (any index of 40)

// Naive Solution: 
    * The idea is to use the nested loop, & then we use the counter for every element to count the value, & if it's being the grater the size of the array we return the index immediately else we return -1.
    * TC : O(n^2)
    * AS : O(1)

// Efficient Solution: 
    * For the efficient solution, e can use the Moor's Voting algorithm, It's works in two phases
    * First phase is to find out the candidate 
    * Second phase is to find out the how many times that candidate has appeared.
    * TC : O(n)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Efficient Solution: 
int majorityElement(int arr[], int n){
    int res = 0;    // Making the candidate as the first index of the array list.   
    int count = 1;  // initially counter as the 1
    for(int i=1;i<n;i++){
        // if the value of first pointer is same as the iterated second pointer.
        if(arr[res]==arr[i]){
            count++;        // increase the counter
        }
        else {
            count--;    // decrement the counter.
        }
        if(count == 0){
            res = i;    // make next res element as the candidate.
            count = 1;  // make again counter as 1, as to check how many times they appears.
        }
    }

    // after finding the candidate, we check how many times it's appears:
    count = 0;  // reseting counter.
    // finding the frequency of that candidate, as how many times he appeared.
    for(int i=0;i<n;i++){
        if(arr[i] == arr[res]){
            count++;
        }
    }
    // checking the condition for majority element: 
    if( count <= n/2) {
        return -1;
    } 
    return res;
}


// Naive Solution: 
int majorityElement_(int arr[], int n){
    int count = 1;  // making counter as 1
    for(int i=0;i<n;i++){
        int count = 1;  // assigning the counter as 1 for every i
        for(int j=i+1;j<n;j++){
            // condition when the element are found as equal.
            if(arr[i] == arr[j]){   
                count++;    // increase counter
            }
        }
        if(count > n/2) return i;   // as inner loop finish for each i, we check the counter value, as if it's greater than n/2 we return the index. 
    }
    return -1;  // else we return -1 for no such majority element.
}   

int main(void){

    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    cout << majorityElement(arr, n);

    return 0;
}