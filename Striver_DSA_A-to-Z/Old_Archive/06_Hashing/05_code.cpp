/*
// for solving the problem of hashing the 10^8 value, we will be using map.

// Hashing using map & Unordered map. 


        STL/Collection 
            |
        map & unordered map

// map : 
        arr[] = 1 2 3 1 3 2
              int    int
        map < key , value>
        
        * Key : number is the key.
        * value : frequency is the value.

// Observation** : 
        * In array hashing, we need to declare the hash of size(max element in array)
        * Whereas, in map, we will be required only that much element that are present in list.

        * example : 
            arr : 1 3 2 2 1 3 2 19

            * for array hash we need to declare a hash of size : 20, because max element is : 19
            * now, for map hash, we need only size : 4, because
                        *  map :    1 -> 2
                                    2 -> 4
                                    3 -> 2
                                    19 -> 1
                                    so, total size is : 4

    * This is where map is slightly better, because it takes less memory...
    * if we fetch the value mpp[4] -> 0, throw 0 because it is not in map.


// Note  : depending upon the size, we can define our map, datatype, their key, & value like : long, long long, etc..

// Note  : The map stored all values in sorted order.
// input : 
1
7
1 1 3 1 3 2 12
5
1
2
3
4
12

// output : 
3
1
2
0
1

// Additional Note : 
    * We can perform array input & precomputation in single loop, but doesn't makes much effect...
    * The time taken : is O(n), 
    * or if we perform both operation separate, then in this case : O(n + n) => O(2n) => O(n) i.e same. 

// Time Complexity  map : 

    * for storing & fetching : (log N) -> best, avg & worst case.
    
    Unordered Map : 
        * code_07 : visit 07_code.cpp 
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    void mapHashing(int arr[], int n){
        // precomputation : 
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }

        // Extra : iterate into the map : 
        // for(auto it : mp){
        //     cout << it.first << "=>" << it.second << endl;
        // }
        
        // fetching : 
        int times;
        cin >> times;
        while(times--){
            int num;
            cin >> num;
            // fetch :
            cout << mp[num] << endl;
        }
    }
    
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
        obj.mapHashing(arr, n);
    }
    return 0;
}