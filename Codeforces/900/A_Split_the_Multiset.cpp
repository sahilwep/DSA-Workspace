
/*

//  A. Split the Multiset

// Observations: 
    * Multiset: a multiset is a set of numbers in which there can be equal elements, & the order of number doesn't matter
        Example: {2, 2, 4}
    * We are given a multiset, initially the multiset contains only one element n, i.e S = {n}, additionally we are given a positive integer k
    * In one operations we can select one positive integer u in S & remove one copy of u from S
    * Then insert no more than k positive integer into S, so that the sum of all positive integer is equal to u.
    * We have to find the minimum number of operations to make S contains n ones
    * In Conclusion we can say: 
        * we have a multiset given only one integer in it..
        * we have to select one integer from the multiset let say u..
        * We should remove u from the multiset..
        * After that we will insert an integer that is less than k, & it's sum will be u..
        * we have to find the minimum number of operations in which we can form the multiset with all the values 1's..
        * we can insert almost k element in the set..

// Example: our target is to make all the element in the multiset 1.
            S = {6}, k = 3
                    {3, 3}, remove 6, & insert 3, 3
                    {1, 1, 1, 3}, remove 3, & insert 1, 1, 1
                    {1, 1, 1, 1, 1, 1}, remove 3, & insert 1, 1, 1
            * We required minimum 3 operations..

            S = {5}, k = 2
                    {1, 4}, remove 5, & insert 1, 4
                    {1, 1, 3}, remove 4, & insert 1, 3
                    {1, 1, 1, 2}, remove 3, insert 1, 2
                    {1, 1, 1, 1, 1}, remove 2, insert 1, 1
            * We required minimum 4 operations..
        * We can observe that we are dividing the element into {1, n-1}


// Intrusion:
    * we can iterate till n is grater than 1
    * at every iteration, we will make n = n - (k - 1), & increment operations pointer that will count the number of operations...


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
    int n, k;
    cin >> n >> k;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    int cnt = 0;
    while(n > 1){
        n = n - (k - 1);    // every time we are removing the (k-1) from n.
        cnt++;
    }
    cout << cnt << endl;
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}