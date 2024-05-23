/*
//  Remove duplicate from sorted array II               https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150

* Given an integer array nums sorted in non-decreasing order, 
* remove some duplicates in-place such that each unique element appears at most twice. 
* The relative order of the elements should be kept the same.


// Approach: 
    * We can compare two consecutive elements, and if it's not unique then we make counter = 1, else if it's same we increase the counter..
    * At most if counter is less or equal 2 we will insert the element else if counter is grater than 2, we skip..

// Observation: 
    arr[] : 0 0 1 1 1 2 2 3 3 4
    k = 1, count = 1;

        i = x : if(arr[i] != arr[i-1])-> count = 1 ; else count++ ; if(count <= 2)-> (arr[k++] = arr[i])

        i = 1 : skip ; count = 2 ; arr[1] = arr[1]       => arr[] = 0 0 1 1 1 2 2 3 3 4,  k = 2, count = 2
        i = 2 : count = 1 ;skip ; arr[2] = arr[2]        => arr[] = 0 0 1 1 1 2 2 3 3 4,  k = 3, count = 1
        i = 3 : skip ; count = 2 ; arr[3] = arr[3]       => arr[] = 0 0 1 1 1 2 2 3 3 4,  k = 4, count = 2
        i = 4 : skip ; count = 3 ; skip                  => arr[] = 0 0 1 1 1 2 2 3 3 4,  k = 4, count = 3
        i = 5 : count = 1 ; skip  ; arr[4] = arr[5]      => arr[] = 0 0 1 1 2 2 2 3 3 4,  k = 5, count = 1
        i = 6 : skip ; cout = 2  ; arr[5] = arr[6]       => arr[] = 0 0 1 1 2 2 2 3 3 4,  k = 6, count = 2
        i = 7 : count = 1 ; skip ; arr[6] = arr[7]       => arr[] = 0 0 1 1 2 2 3 3 3 4,  k = 7, count = 1
        i = 8 : skip ; count = 2 ; arr[7] = arr[8]       => arr[] = 0 0 1 1 2 2 3 3 3 4,  k = 8, count = 2
        i = 9 : count = 1 ; skip ; arr[8] = arr[9]       => arr[] = 0 0 1 1 2 2 3 3 4 4,  k = 9, count = 1

            * at the end we return k; 


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
 
int removeDuplicate(vector<int> &arr){
    int k = 1;  // first index to insert elements..
    int count = 1;  // this counter will count how many times we will need same element
    for(int i=1;i<arr.size();i++){
        if(arr[i] != arr[i-1]){
            count = 1;  // if there is unique element, make counter as 1
        }
        else {
            count++;    // if we get the same consecutive element, increase counter
        }
        // if counter is less or equal to 2, will will insert element..
        if(count <= 2){
            arr[k] = arr[i];
            k++;    // increase counter...
        }
    }
    return k;
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        int k;
        cin >> k;
        arr[i] = k;
    }
    n = removeDuplicate(arr);
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}