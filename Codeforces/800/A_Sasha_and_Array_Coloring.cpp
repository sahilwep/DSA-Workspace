/*

// A. Sasha and Array Coloring

// Observations: 
    * we are given an array arr, containing n integer, we are asked to paint each element..
    * We can paint each element of array, and we can take as many color as we want.
    * each element should be painted exactly one color, & for each color there should be atleast one element of that color.
    * cost of one color value of max(s) - min(s), where s is sequence of element of that color.
    * the cost of whole coloring is sum of cost of all color.


// Intrusion: 
    * first we will sort the array,
    * We can use two pointer approach that will find the maximum sum..
    * When we have only one element we return 0.
    * For even size array, we can compute all the value..
    * For odd size array, one value left, as it's the maximum remaining..


// Complexity: 
    * TC: O(nlogn)


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


void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    // Case: when array has only one element: 
    if(v.size() == 1){
        cout << 0 << endl;
        return;
    }

    // // Sorting:
    sort(v.begin(), v.end());

    // // Computing the result: 
    int sum = 0;
    int p1 = 0;     //first pointer
    int p2 = n-1;   // second pointer
    
    while(p1 < n/2 || p2 > n/2){
        sum += v[p2] - v[p1];
        p1++;
        p2--;
    }

    cout << sum << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;

    while(t--){
        solve();
    }
    
    return 0;
}