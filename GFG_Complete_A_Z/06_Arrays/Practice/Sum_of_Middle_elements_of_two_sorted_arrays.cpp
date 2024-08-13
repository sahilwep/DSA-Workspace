/*

// Sum of Middle elements of two sorted arrays

// Observations: 
    * we are given two array of odd size..
    * We need to merge both the array & return the two middle sum of elements, from the even size final array that we will merge..

*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int SumofMiddleElements(vector<int> &arr1, vector<int> &arr2) {

        // merging both the array into third array:
        int n = arr1.size() + arr2.size();
        vector<int> final(n);
        int i=0, j=0, k=0;
        while(i != arr1.size() && j != arr2.size()){
            if(arr1[i] <= arr2[j]){
                final[k++] = arr1[i++];
            }else{
                final[k++] = arr2[j++];
            }
        }
        
        // merging leftover: 
        while(i != arr1.size()){
            final[k++] = arr1[i++];
        }
        while(j != arr2.size()){
            final[k++] = arr2[j++];
        }
        
        // returning the middle from final array:
        int mid = final[n/2 - 1] + final[n/2];
        return mid;
    }
};


int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr, brr;
        string input1;
        getline(cin, input1);
        stringstream ss1(input1);
        int number1;
        while (ss1 >> number1) {
            arr.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream ss2(input2);
        int number2;
        while (ss2 >> number2) {
            brr.push_back(number2);
        }
        Solution ob;
        int res = ob.SumofMiddleElements(arr, brr);
        cout << res << endl;
    }
}