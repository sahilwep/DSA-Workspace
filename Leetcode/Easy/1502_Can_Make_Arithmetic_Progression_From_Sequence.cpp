/*

//  1502. Can Make Arithmetic Progression From Sequence


//  Problem Statement: 
    -> A sequence of numbers is called an arithmetic progression if the difference between any two consecutive elements is the same.
    -> Given an array of numbers arr, return true if the array can be rearranged to form an arithmetic progression. Otherwise, return false.

 
// Example: 
    Example 1:
        Input: arr = [3,5,1]
        Output: true
        Explanation: We can reorder the elements as [1,3,5] or [5,3,1] with differences 2 and -2 respectively, between each consecutive elements.

    Example 2:
        Input: arr = [1,2,4]
        Output: false
        Explanation: There is no way to reorder the elements to obtain an arithmetic progression.


// Observations: 
    -> Sort the given list
    -> Check if any two adjacent element is not equal thought.

    // Complexity: 
        -> TC: O(n*logn)
        -> SC: O(1)


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



void solve(){
    int n;
    
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}