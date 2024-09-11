/*

// Sort by Absolute Difference:

// Observations: 
    * we are given an array, we need to sort them according to the absolute difference with k.
    * element having minimum difference comes first, and so on.

// Example: 
    Input: k = 7, arr[] = [10, 5, 3, 9, 2]
    Output: [5, 9, 10, 3, 2]
        Explanation: Sorting the numbers according to the absolute difference with 7,
        we have array elements as 5, 9, 10, 3, 2.

    * Example Observations:
            7 - 10 = 3
            7 - 5 = 2
            7 - 3 = 4
            7 - 9 = 2
            7 - 2 = 5
        * If two or more element with same same difference value, we need to arrange them in a sequence as given array.




// Intrusion: 
    * Using Multimap:
        * Multimap is similar to map, but in addition with multiple element can have same key, also it is not required that key-value and mapped value pair have to be unique in this case.
        * One important point about multimap, it keeps all their keys in sorted order.
        * TC: O(nlogn)

    // Using "stable_sort()"
        * Simillar to std::sort(), but it keeps the relative order of element with equivalent value, it comes under <algorithm> header file.
            
            stable_sort() =>  void stable_sort( RandomIterator first, RandomIterator last, Compare comp ); 
                * first: first iterator
                * second: second iterator
                * comp: predict function that accept two arguments & return true if the two arguments are in the order and false otherwise.
                * Ref: https://www.geeksforgeeks.org/stable_sort-c-stl/

        * We will write our compare function which is of boolean type:
                
                stable_sort(arr, arr+n, [x](int a, int b){
                    if(abs(a - x) < abs(b - x)) return true;    // if (a-x) is lesser than (b-x), return true: else return false.
                    else return false;
                });


*/

#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

class Solution {
  public:
    // Using multimap:
    void sortABS_Multi(int k, vector<int> &arr) {
        // storing value in map: this will store the values in sorted fashion.
        multimap<int, int> mp;
        for(int i=0;i<arr.size();i++){
            mp.insert(make_pair(abs(arr[i] - k), arr[i]));  // storing key-value pair in multimap, by taking absolute difference of arr[i] & given k.
        }

        // Now Updating value from multimap to array:
        int idx = 0;
        for(auto i=mp.begin();i!=mp.end();i++){
            arr[idx++] = i->second;
        }
    }

    // // Using stable_sort():
    void sortABS(int k, vector<int> &arr) {
        // Using Stable sort:
        stable_sort(arr.begin(), arr.end(), [k](int a, int b){
            if(abs(k - a) < abs(k - b)) return 1;
            else return 0;
        });

    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> arr;
        int k;
        cin >> k;
        string input;
        getline(cin, input);
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) arr.push_back(number);
        Solution ob;
        ob.sortABS(k, arr);
        for (int& val : arr) cout << val << " ";
        cout << endl;
    }

    return 0;
}