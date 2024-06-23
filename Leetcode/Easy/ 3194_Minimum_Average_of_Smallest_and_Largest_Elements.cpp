/*
//   3194. Minimum Average of Smallest and Largest Elements



Example 1:
Input: nums = [7,8,3,4,15,13,4,1]
Output: 5.5

    Explanation:
    step 	    nums 	            averages
    0 	[7,8,3,4,15,13,4,1] 	      []
    1 	[7,8,3,4,13,4]             	  [8]
    2 	[7,8,4,4] 	                  [8,8]
    3 	[7,4] 	                      [8,8,6]
    4 	[] 	                          [8,8,6,5.5]
    The smallest element of averages, 5.5, is returned.


Example 2:
Input: nums = [1,9,8,3,10,5]
Output: 5.5

    Explanation:
    step 	nums           	averages
    0 	[1,9,8,3,10,5] 	       []
    1 	[9,8,3,5] 	           [5.5]
    2 	[8,5] 	               [5.5,6]
    3 	[] 	                   [5.5,6,6.5]


Example 3:
Input: nums = [1,2,3,7,8,9]
Output: 5.0

    Explanation:
    step 	nums 	    averages
    0 	[1,2,3,7,8,9] 	  []
    1 	[2,3,7,8] 	      [5]
    2 	[3,7]             [5,5]
    3 	[] 	              [5,5,5]


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

class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        // first we have to find all the average
        sort(nums.begin(), nums.end());
        int ptr1 = 0;
        int ptr2 = nums.size()-1;
        double avg = 51.00;
        while(ptr1 < ptr2){
            double temp = (double(nums[ptr1]) + double(nums[ptr2]))/2.0;
            avg = min(avg, temp);
            ptr1++;
            ptr2--;
        }
        return avg;
    }
};

void solve(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i=0;i<n;i++) cin >> nums[i];
    Solution obj;
    cout << setprecision(1) << fixed << obj.minimumAverage(nums) << endl;
    
}


int main(){
    int t = 1;     // Change the testcase according to question...
    cin >> t;
    
    while(t--){
        solve();
    }
    
    return 0;
}