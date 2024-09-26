/*

//  Subarray with 0 sum



//  Observations: 
        * We are given an array, we need to find the subarray, of atleast size 1 that has sum = 0.


// Example:

    Input:
        n = 5
        arr = {4,2,-3,1,6}
    Output: Yes
    Explanation: 2, -3, 1 is the subarray with sum 0.


    Input:
        n = 5
        arr = {4,2,0,1,6}
    Output: Yes
    Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.

// Intrusion:
    // Bruteforce Solution: 
        * We will select every element one by one & try to find the subarray that is equal to the given sum.
        * TC: O(n^2)  -> TLE



    // Hashing & Prefix Sum Approach:
        * Idea is to iterate throughout the array & for every element arr[i], calculate the sum of elements from 0 to i(This can simply be done as sum += arr[i]).
        * If The current sum has been seen before, then there must be a zero-sum subarray.
        * Hashing is used to store the sum value so that sum can be stored quickly and find out whether the current sum is seen before or not.
        * Example:

            arr[] = {1, 4, -2, -2, 5, -4, 3}

            Prefix sum: 1 5 3 1 6 2 5

            Consider all prefix sums, One can notice that there is a subarray with 0 sum when:
                Either a prefix sum repeats
                or, prefix sum becomes 0.

            Since, Prefix sum 1 repeats, we have a subarray with 0 sum.

                * Detail Observations:

                    range => [1, 4, -2, -2]
                            1 + 4 + (-2) + (-2)
                            -   --------------
                                these value = 0
                                so 1 will occur again.

                    For '0', we are saying if we have 0, same value will occur again, because x(prevSum) + 0(currVal) = x(currSum),


        * TC: O(n)


*/

#include<bits/stdc++.h>
#include<algorithm>
#include<unordered_set>
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
    // Bruteforce Solution: O(n^2)
    bool subArrayExists_Brute(int arr[], int n){
        for(int i=0;i<n;i++){
            int sum = arr[i];
            for(int j=i+1;j<n;j++){
                if(sum == 0) return 1;
                sum += arr[j];
            }
        }
        return 0;
    }

    // Hashing & Prefix Sum Approach:
    bool subArrayExists(int arr[], int n){
        int sum = 0;
        
        // Idea is to use unordered_set, as it's random which take O(1) for find, & do not allow duplicates value, so we can check while insertion of prefix sum in it.
        unordered_set<int> us;
        for(int i=0;i<n;i++){
            sum += arr[i];
            // If element is found, we will return true.
            if(us.find(sum) != us.end() || sum == 0){
                return 1;
            }
            // if element is not found, insert in set:
            else{
                us.insert(sum);
            }
        }

        return 0;   // else we will return false.
    }

};

int main(){
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++) cin>>arr[i];
	    Solution obj;
        if(obj.subArrayExists(arr, n)) cout << "Yes\n";
        else cout << "No\n";
	}
	return 0;
}