/*
//  B. Interesting drink



// Observations: 
    * drinks which he bought from n different shops from the city.
    * it is known that price of one bottle from i shop xith coin.
    * She wants to buy drink for q consecutive days, he known on ith days he will be able to spend mi-coind
    * Now, for each of the days, he wants to know how many different shops he go to purchase the drink.


// Input: 
    * first input will be n, shops, defining their price..
    * Second input will be (0 <= xi <= n), containing the price of each ith shop.
    * third input will be q, defining q consecutive days, he can spent.
    * for price input will be an array from (1 <= mi <= q), defining the price of mth days he will be able to spend.
// Output: 
    * Output will be an array containing the result of number of shop, he is eligible to purchase, simply we have to return the number of shop, form which he can purchase his drink..


// Intrusion: 
    // Bruteforce Solution: TLE
        * Idea is to take each query & then find that query within an array & count for how many arr[i], it satisfies..
        * This takes O(n*m) complexity, which gives TLE in worse case..

    // Efficient Solution: O(nlogn)
        * we will use upper_bound() function for this problem statement.
            * first we have to sort the shop's price & then we can use upper_bond() function.
            * upper_bond() -> It return iterator pointing to the first element in the range[first, last] that is grater than the value, or last value if no such element is found 
            * Example: 
                        Input : 10 20 30 30 40 50
                        Output : upper_bound for element 30 is at index 4

                        Input : 10 20 30 40 50
                        Output : upper_bound for element 45 is at index 4

                        Input : 10 20 30 40 50
                        Output : upper_bound for element 60 is at index 5 

        * Upper_bound: return next iterator pointing to first element in range, that is grater than the value, or last value if no such element is found
            * Syntax: upper_bound(arr, arr+n, k) - arr;
                * By subtracting arr from this iterator (upper_bound(arr, arr + n, k) - arr),
                * you get the index of this position relative to the start of the array arr.

        * Well explained Resource: https://www.geeksforgeeks.org/upper_bound-in-cpp/
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
#define SQ(a) (a)*(a);


// Bruteforce: This gives TLE: O(n*m)
int findingNumberOfShopHeIsEligible(int shop[], int n, int mi){
    // we have to return the numbers of shope he is eligible to purchase from n shop.
    int cnt = 0;
    for(int i=0;i<n;i++){
        if(shop[i] <= mi) cnt++;
    }
    return cnt;
}

void solve_(){
    int n, q, m;
    cin >> n;
    int shop[n];
    for(int i=0;i<n;i++) cin >> shop[i];
    cin >> q;
    int res[q];
    sort(shop, shop+n);
    for(int i=0;i<q;i++){
        cin >> m;
        int eligibleShops = findingNumberOfShopHeIsEligible(shop, n, m);
        res[i] = eligibleShops;
    }
    for(auto i : res) cout << i << endl;
}

// Accepted solution: O(nlogn) + O(logn) => O(nlogn)
void solve(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;
    int q;
    cin >> q;
    sort(arr, arr+n);   // used quick sort, which takes O(nlogn)
    int k;
    int ans;
    while(q--){
        cin >> k;
        ans = upper_bound(arr, arr+n, k) - arr; // takes (logn)
        cout << ans << endl;
    }
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}