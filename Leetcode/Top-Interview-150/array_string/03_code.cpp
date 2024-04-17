/*
//  26. Remove Duplicates from Sorted Array         https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/?envType=study-plan-v2&envId=top-interview-150


* We have to remove the duplicate value from sorted array...
* We have to return the size of new unique elements...

// Constraints:
    1 <= nums.length <= 3 * 10^4
    -100 <= nums[i] <= 100
    nums is sorted in non-decreasing order.

// Observation: 

    0 0 1 1 1 2 2 3 3 4  =>  0 1 2 3 4

    * We put one pointer let (k) at position 0th index, & we will start comparing the value with 1-->n
    * If the value are distinct, then we will insert them into array with incrementing the position k.
    * at the end we will return the new size of k

Note: ++k => k = k + 1 & then precess...
for every i: , (arr[k] != arr[i]) -> arr[++k] = arr[i]

        arr[] = 0 0 1 1 1 2 2 3 3 4
        arr[0] = 0

        i = 1: (0 != 0)     -> arr[0 0 1 1 1 2 2 3 3 4], k = 0
        i = 2: (0 != 1)     -> arr[0 1 1 1 1 2 2 3 3 4], k = 1
        i = 3: (1 != 1)     -> arr[0 1 1 1 1 2 2 3 3 4], k = 1
        i = 4: (1 != 1)     -> arr[0 1 1 1 1 2 2 3 3 4], k = 1
        i = 5: (1 != 2)     -> arr[0 1 2 1 1 2 2 3 3 4], k = 2
        i = 6: (2 != 2)     -> arr[0 1 2 1 1 2 2 3 3 4], k = 2
        i = 7: (2 != 3)     -> arr[0 1 2 3 1 2 2 3 3 4], k = 3
        i = 8: (3 != 3)     -> arr[0 1 2 3 1 2 2 3 3 4], k = 3
        i = 9: (3 != 4)     -> arr[0 1 2 3 4 2 2 3 3 4], k = 4

    * Now, we have to return k+1, for printing the 1 to k elements...


// TC : O(n)

*/ 

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define arrInp for(int i=0;i<n;i++) cin >> arr[i];
#define arrOut(k) for(int i=0;i<n;i++) cout << arr[i] <<  k;
#define el cout << endl;
#define SQ(a) (a)*(a)

int removeDuplicate(int arr[], int n){
    int k = 0;
    for(int i=1;i<n;i++){
        if(arr[k] != arr[i]){
            arr[++k] = arr[i];
        }
    }
    return k+1;
}

void solve(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    n = removeDuplicate(arr, n);
    arrOut(" ");
    el;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}