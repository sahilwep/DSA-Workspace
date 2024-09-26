/*

//  Sort an array according to the other

//  Observations:
    * We are given Two array A[] of size N & B[] of size M.
    * We have to sort first array A[], according to the second array B[]
    * We have to look on second array, & check element in first array, & sort them...
    * When the first array is exhausted, we have to sort remaining elements of first array.
    //  Note: If elements are repeated in the second array, consider their first Occurrence only.



// Example:
    Input:
        N = 11 
        M = 4
        A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
        A2[] = {2, 1, 8, 3}
    Output: 2 2 1 1 8 8 3 5 6 7 9
        Explanation: Array elements of A1[] are
        sorted according to A2[]. So 2 comes first
        then 1 comes, then comes 8, then finally 3
        comes, now we append remaining elements in
        sorted order.

    Input:
        N = 11 
        M = 4
        A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
        A2[] = {99, 22, 444, 56}
    Output: 1 1 2 2 3 5 6 7 8 8 9
        Explanation: No A1[] elements are in A2[]
        so we cannot sort A1[] according to A2[].
        Hence we sort the elements in non-decreasing 
        order.


// Intrusion:
    // Bruteforce Approach:
        * As we have given constrains that we may have duplicate values in second array, so first we will remove duplicates from the first array.
        * Then we will store the values in result(temp) array by comparing second array order..
        * After words we will check for leftover values.
            * First we will store the leftover values form the first array..
            * then after sorting we will store these into result array.


        * Example:

            Input:
                A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}
                A2[] = {2, 1, 8, 2, 1, 3}
            
            Output: 2 2 1 1 8 8 3 5 6 7 9
                
            Step 1: Remove Duplicates from A1[] =  {2 1 8 3}

            Step 2: Insert values of A1[] related to second array A2
                        {2 2 1 1 8 8 3}
            
            Step 3: Insert the left over Values from A1[]
                * Using map to find the left over values:
                        {5, 6, 7, 9}
                * Sort these values, in order to insert them into the result in sorted order.
                        {5, 6, 7, 9}

            Step 4: Now Insert leftover values into the result array.

        * TC:  O(mlogm + m×n + nlogn)   -> TLE
            * mlogm => Removing duplicates
            * mxn =>  Insertion of all the relative elements from second array into result
            * nlogn => Insertion of leftover.

    // Hashing Approach:
        * first we will remove duplicate form the second array, that will take O(m)
        * Then we will store the frequency of first array int map.
        * After that we will iterate in second array, & find the element in hashmap, if it's present, we will store that element into our result by number of times their frequency.
        * Then after we will store the leftover element from map into result.


        * Example:
            Input:
                A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8}    -> N
                A2[] = {2, 1, 8, 2, 1, 3}   -> M
            
            Output: 2 2 1 1 8 8 3 5 6 7 9

            * Step 1: Remove duplicates from the second array:
                A2[] = {2, 1, 8, 3}
            * Step 2: Store frequency of first array into map:
                map:
                    1 -> 2
                    2 -> 2
                    3 -> 1
                    5 -> 1
                    6 -> 1
                    7 -> 1
                    8 -> 2
                    9 -> 2

            * Step 3: Iterate in Second array & Store elements into result, & remove the stored element from the map.
            * Step 4: after that store the left element from the map to the result array.


        * TC: O(m*logn + n)



*/

#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef size_t s_t;  // use during string traversal
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a);
#define mod 1000000007

class Solution{
public:
    // Bruteforce Approach:  O(mlogm + m×n + nlogn) TLE 
    vector<int> sortA1ByA2_Brute(vector<int> a1, int n, vector<int> a2, int m){
        // Step 1: First Removing duplicates form the second array:
        vector<int> arr2 = removeDupOrder(a2);


        // Step 2: Insertion of all the relative elements from second array into result:
        vector<int> res;
        for(int i=0;i<arr2.size();i++){
            for(int j=0;j<n;j++){
                if(arr2[i] == a1[j]){
                    res.push_back(a1[j]);
                }
            }
        }


        // Step 3: Insertion of left Over from the first array:
        unordered_map<int, int> mp;
        // Store previous stored value from result into the map:
        for(auto i: res) mp[i]++;

        vector<int> leftOver;
        for(int i=0;i<n;i++){
            // If the element is not found in map, then insert these values into 
            if(mp.find(a1[i]) == mp.end()){
                leftOver.push_back(a1[i]);
            }
        }
        // Sorted the leftOver value, so that we can insert it in sorted fashion.
        sort(leftOver.begin(), leftOver.end());  

        // Step 4: Storing values into result:
        for(auto i: leftOver){
            res.push_back(i);   // insertion of values into result.
        }


        return res;

    } 
    // remove Duplicates: Using hashing to remove duplicate, & it should be in order.
    vector<int> removeDupOrder(vector<int> arr){
        // Using map to remove duplicate elements:
        map<int, int> mp;
        for(auto i: arr) mp[i]++;

        // Maintain order by chaining the frequency after every insertion.
        vector<int> res;
        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]] != -1){
                res.push_back(arr[i]);
                mp[arr[i]] = -1;
            }
        }

        return res;
    }

    // Hashing Approach:
    vector<int> sortA1ByA2(vector<int> a1, int n, vector<int> a2, int m){
        vector<int> res;    // result array

        // Step 1: Remove Duplicates from the Second array: O(m)
        vector<int> arr2;
        unordered_map<int, int> mp;
        for(int i=0;i<m;i++){
            if(mp.find(a2[i]) == mp.end()){
                arr2.push_back(a2[i]);
                mp[a2[i]]++;
            }
        }
        m = arr2.size();    // changing size of second array after removing duplicates.

        // Step 2: Storing the frequency of first array:    O(n)
        map<int, int> freq;
        for(int i=0;i<n;i++){
            freq[a1[i]]++;
        }

        // Step 3: Iterate in Second array & store element into result, & remove elements form the map: O(m*logn)
        for(int i=0;i<m;i++){
            // If element is found in map: insert values into map
            if(freq.find(arr2[i]) != freq.end()){
                int occur = freq[arr2[i]];
                int value = arr2[i];
                while(occur > 0){
                    res.push_back(value);
                    occur--;
                }

                // After Insertion, remove element from map:
                freq.erase(value);
            }
        }

        // Step 4: insert leftover elements from map into result: we have choosen map, so elements are already in sorted order: O(n)
        for(auto i: freq){
            int val = i.first;
            int occur = i.second;
            while(occur > 0){
                res.push_back(val);
                occur--;
            }
        }

        return res;
    }
};


int main(int argc, char *argv[]){
	int t;
	cin >> t;
	while(t--){
	    int n, m;
	    cin >> n >> m;
	    
	    vector<int> a1(n);
	    vector<int> a2(m);
	    
	    for(int i = 0;i<n;i++){
	        cin >> a1[i];
	    }
	    
	    for(int i = 0;i<m;i++){
	        cin >> a2[i];
	    }
	    
	    Solution ob;
	    a1 = ob.sortA1ByA2(a1, n, a2, m);

	    for (int i = 0; i < n; i++) cout<<a1[i]<<" ";
	    cout << endl;
	    
	}
	return 0; 
}