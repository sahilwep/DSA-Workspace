/*
// remove duplicate from a sorted array : 

    * arr[] { 1 1 2 2 2 3 3}        =>  {1 2 3}
    
// Bruteforce Solution : 
    * we can use set-ds, to perform this operation, because set only store the unique elements.
    // SETs :
        * set stores everything in ascending order,
        * set stores only unique values.
    * we can insert the all array element into the set.
    * then after inserting the unique value into set, we can reinsert the unique element,
    * to the array, by counting the index.
    * after that we can iterate the loop from 0 to (counted_index) & print the array.

// Optimized using 2-pointer approach.
    * we can start from 0 index with setting the i = 0
    iterate the loop from 1 to n : 
        * checking the condition : if (arr[i] != arr[j])
            * assign the arr[i+1] = arr[j]
            * increment i++;
    return i+1
    
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
// Bruteforce Solution : 
    void removeDuplicate_1(int arr[], int n){
        // first pass : insert unique element in set.
        set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);  // inserting the unique values into the set.
            // TC : O(nlogn)
        }
        // second pass : update the array : 
        int index = 0;
        for(auto it : st){
            arr[index] = it;    // assigning the unique elements to the array.
            index++;   // finding the number of unique elements.
            // TC : O(n)
        }
        // printing the array : 
        for(int i=0;i<index;i++) cout << arr[i] << " ";
    }
    // TC : O((n)*(n)log(n))
    // SC : O(n)    : because, we are using the set, so it can take n space in worst case, if all elements are unique..


// optimal Solution : Two pointers method 
    void removeDuplicate_2(int arr[], int n){
        int i = 0;  // first pointer = i
        for(int j=1;j<n;j++){   // second pointer = j
            if(arr[j] != arr[i]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        for(int j=0;j<i+1;j++) cout << arr[j] << " ";
    }
        // TC : O(n)
        // SC : O(1)
}; 

int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        Solution obj;
        obj.removeDuplicate_2(arr, n);
        cout << endl;
        
    }
    return 0;
}