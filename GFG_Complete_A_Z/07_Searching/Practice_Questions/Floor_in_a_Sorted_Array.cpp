/*
//  Floor in a Sorted Array

// Observations: 
    * Given sorted array arr of size n, without duplicates values, & given integer x, 
    * Floor is defined as largest element k, such that k is smaller or equal than x, find the index of k(0 based indexing.)


// Examples

    Input: n = 7, x = 0 arr[] = {1,2,8,10,11,12,19}
    Output: -1
    Explanation: No element less than 0 is found. So output is "-1".

    Input: n = 7, x = 5 arr[] = {1,2,8,10,11,12,19}
    Output: 1
    Explanation: Largest Number less than 5 is 2 (i.e k = 2), whose index is 1(0-based indexing).

// Intrusion: 
    // Bruteforce Solution: 
        * We will use linear search to find that element.
        * Edge case: 
            * when element it'self less than the first element, return -1
            * If element is grater or equal to the x
                * check if it's equal to that x, return same index, else return one index before.
            * If element is not found throughout the array, return last index.
        * TC: O(n)



*/

#include<bits/stdc++.h>
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


class Solution {
public:
    // Bruteforce Solution: 
    int findFloor(vector<long long> &v, long long n, long long x) {
        // Edge case: when element itself is smaller than the first element:
        if(x < v[0]){
            return -1;
        }
        for(int i=0;i<n;i++){
            // if we found element that is grater or equal to x
            if(v[i] >= x){
                // if element it'self is equal return same index,
                if(v[i] == x){
                    return i;   // return same index
                }
                // else return one index before
                return i-1;
            }
        }
        return n-1; // if not found, return last index.
    }
};

int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long x;
        cin >> x;
        vector<long long> v;
        for (long long i = 0; i < n; i++) {
            long long temp;
            cin >> temp;
            v.push_back(temp);
        }
        Solution obj;
        cout << obj.findFloor(v, n, x) << endl;
    }

    return 0;
}