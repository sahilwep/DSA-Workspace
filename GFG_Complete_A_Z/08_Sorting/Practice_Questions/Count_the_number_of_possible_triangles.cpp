/*

// Count the number of possible triangles


// Observations:
    * We are given unsorted array, & we have to find the number of possible triangle that can be formed with three different element of an array, as length of three side of triangle.

// Example: 

    Input: 
        n = 3
        arr[] = {3, 5, 4}
    Output: 1
    Explanation: A triangle is possible with all the elements 5, 3 and 4.

    Input: 
        n = 5
        arr[] = {6, 4, 9, 7, 8}
    Output: 10
    Explanation: There are 10 triangles possible with the given elements like (6,4,9), (6,7,8),...
        
    * Possible Combinations: 
                    {6, 4, 9}
                    {6, 4, 7}
                    {6, 7, 8}
                    {6, 9, 7}
                    {6, 9, 8}
                    {6, 7, 8}
                    {4, 9, 7}
                    {4, 9, 8}
                    {4, 7, 8}
                    {9, 7, 8}

// Conditions for triangle:
    * For a condition of triangle, sum of two values(two sides) must be grater than the third value(third side).
    * Possible conditions: 
        sides: i, j, k
            i + j > k
            i + k > j
            j + K > i


// Intrusion: 
    // Using nested loop:
        * we will use tree nested loop to find the number of possible triangles, we will use a counter that will increment only when the condition of triangle will be hit.
        * TC: O(n^3) 

    // Using Sorting:
        * First sort the array,
        * then use two loop, the outer loop will fix the first side, & inner loop will fix the second side.
        * then find the farthest index of third side, whose length is less than the sum of these two sides.
        * So the range value of third side can be found. 
        * where it is guarantee that it's length is grater than other individual sides but less than the sum of both sides.



// Sorting Logic Working:
    // Triangle inequality theorem:
        * For the give sides of triangle, the sum of two side will always be grater than the third side:
            a + b > c
            a + c > b
            b + c > a
    
    // Algorithm Overview:
        * Array is sorted in non-decreasing order.
        * The code uses three nested loop to pick triplet(arr[i], arr[j], arr[k]), where (i < j < k)
        * It count how many triplets satisfies the conditions.

    // Example Walkthrough: 
        Consider an array: [4, 6, 3, 7]
        After sorting: [3, 4, 5, 7]
        Possible triangles:
            Using element 3, 4, 6 -> valid (since 3 + 4 > 6)
            Using element 3, 6, 7 -> valid (since 3 + 6 > 7)
            Using element 4, 6, 7 -> valid (since 4 + 6 > 7)

        Hence, the function would return 3 for this example.
        

// Constrains: 
    * Size of array:  3 <= n <= 10^3
    * Size of element: 1 <= arr[i] <= 10^3
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

class Solution{
public:
    // Using sorting:
    int findNumberOfTriangles(int arr[], int n){
        // array is sorted first, so checking triangle inequality will be straightforward
        sort(arr, arr+n);
        int cnt = 0;    // use to count the number of possible triangle.

        // Outer loop fix first element arr[i], this loop runs until n-3, because the last two element are needed for arr[j] & arr[k]
        for(int i=0;i<n-2;i++){
            // Initialized index of rightmost third element
            int k = i+2;

            // second loop will fix the second element arr[j], where j start from 'i+1' and runs until n-2
            for(int j=i+1;j<n-1;j++){

                // Finding Third element:
                // The third element arr[k] is found using while loop.
                // The loop continues increment k until k is less than n,
                // and the sum of arr[i] & arr[j] is no longer grater than arr[k].
                // The condition arr[i] + arr[j] > arr[k] holds for the triplet from a valid triangle.
                while(k < n && arr[i] + arr[j] > arr[k]){
                    k++;
                }

                // Counting the possible triangle:
                // cnt increment by "k - j - 1", which gives the number of valid triangle that can be formed with a fixed element arr[i] & arr[j]
                // the subtraction of 1, because k is incremented one extra time in while loop.
                if(k > j){
                    cnt += k - j - 1;
                }

            }
        }

        return cnt;
    }
    // Bruteforce Solution: TC -> O(n^3)
    int findNumberOfTriangles_Brute(int arr[], int n){
        int res = 0;
        for(int i=0;i<n;i++){
            // j = i + 1, to ignore the same value consider twice.
            for(int j=i+1;j<n;j++){
                // k = j + 1, to ignore the same value consider twice.
                for(int k=j+1;k<n;k++){
                    // If either of these three conditions are true then only increase the counter.
                    if(((arr[i] + arr[j]) > arr[k]) 
                    && ((arr[i] + arr[k]) > arr[j]) 
                    && ((arr[j] + arr[k]) > arr[i])){
                        res++;  // increment the counter.
                    }
                }
            }
        }

        return res;
    }
};

int main(){
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.findNumberOfTriangles(arr,n) <<endl;
    }
    return 0;
}

