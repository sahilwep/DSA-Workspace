/*

// Intersection of two arrays

// Observations: 
    * We are given 2 array, we need to count the number of element that are in intersection point of both the array.

// Example

    Input:
    n = 5, m = 3
    a[] = {89, 24, 75, 11, 23}
    b[] = {89, 2, 4}
    Output: 1
        Explanation: 
        89 is the only element 
        in the intersection of two arrays.

    Input:
    n = 6, m = 5
    a[] = {1, 2, 3, 4, 5, 6}
    b[] = {3, 4, 5, 6, 7} 
    Output: 4
        Explanation: 
        3 4 5 and 6 are the elements 
        in the intersection of two arrays.

// Key Observations: 
    * We need to remove the duplicate value from both the array.
    * Because if we don't remove the duplicate values, it will recount the same counted values.
    * We can use set data-structure remove the duplicates.


// Intrusion: 
    // Approach 1: Bruteforce approach:
        * We can use nested loop to count the number of element that falls in intersection region.
        * We need to remove the duplicate values from both the array.
        * We have to take care of unique value.
        * TC: O(n*m)    -> TLE
        * AS: O(n + m)

    // Approach 2: Using Set data structure:
        * We can use set data structure to perform this operations.
        * First we have to remove the duplicate values from both the array.
        * We will use two set that stores the both the array elements.
        * once, it's done, we can simply iterate on one set, & find the values in other set by using find() function, if the values exist, we will increase counter.
        * TC: O(nlogn + mlogm)
        * AS: O(n+m)


*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Bruteforce solution:
    // function to remove the duplicate from the array: order is not maintained, as it's not needed in parent function.
    int removeDuplicate(int arr[], int n){
        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        int k = 0;
        for(auto i=mp.begin();i!=mp.end();i++){
            arr[k++] = i->first;
        }
        
        return mp.size();
    }
    int NumberofElementsInIntersection_Brute(int a[], int b[], int n, int m) {
        // Removing the duplicate values:
        n = removeDuplicate(a, n);  // this will return new size of n, if duplicate exist
        m = removeDuplicate(b, m);  // this will return new size of m, if duplicate exist
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i] == b[j]){
                    cnt++;
                    break;
                }
            }
        }

        return cnt;
    }

    // Approach 2: Using Set data structure:
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        // Insertion of first array into first set:
        set<int> s1;
        for(int i=0;i<n;i++){
            s1.insert(a[i]);
        }
        // Insertion of second array into the second set: 
        set<int> s2;
        for(int i=0;i<m;i++){
            s2.insert(b[i]);
        }
        // Iterating in first set & try to finding the values in second set.
        int cnt = 0;
        for(auto i : s1){
            // By using find() function we will find the values from second set, if it's contains.
            if(s2.find(i) != s2.end()){
                cnt++;
            }
        }

        return cnt;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}