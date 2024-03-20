/*
// Leaders in an array:
    * element is called leader if it is grater than all element on right side of it.
    * constrains : the leaders are in sorted order.


    I/p : arr[] = {7, 10, 4, 3, 6, 5, 2}
    O/p : 10 6 5 2

    I/p : arr[] = {10, 20, 30}
    O/p : 30

    I/p : arr[] = {30, 20, 10}
    O/p : 30 20 10


// efficient solution(my mind) : 
    * we will start iterating from the right side.
    * the rightmost element will always be the leader,
    * our first leader will be the last element on right-side,
    * We start comparing with that element by iterating left side, if any element found grater than that element then we will say it's leader.
    * at end we just print all the element which we store in leaders array.
    * TC : O(n)
    * AS : O(n)

// Naive solution(GFG) : 
    * we will use nested loop: 
    * we will start iterating from start to end in outer iteration(let say i): 
        * inside the outer loop, we set flag = false,
        * start the inner iteration(let say j) : 
            * inside the inner iteration if any element is grater or equal then, we set our flag as false, (arr[i] <= arr[j]) -> set flag=false.
        * After coming out loop if our flag set as false, we say the leader leader element is found.
    
    * TC : O(n^2)
    * AS : O(1)

*/

#include<bits/stdc++.h>
using namespace std;

// Naive solution(GFG): 
void leadersArray_1(int arr[], int n) {
    for(int i=0;i<n;i++) {
        bool flag = false;
        for(int j=i+1;j<n;j++) {
            if(arr[i] <= arr[j]) {
                flag = true;
                break;
            }
        }
        if(flag == false) {
            cout << arr[i] << " ";
        }
    }
}

// Efficient solution (my mind): TC : O(n), AS : O(n)s
void leadersArray(int arr[], int n){
    vector<int> leaders; // creating n size of array to store the leaders
    int last_elem = arr[n-1];   // last element
    leaders.push_back(last_elem);   // inserting last element in an array.

    for(int i=n-2;i>=0;i--){
        if(arr[i] > last_elem) {
            last_elem = arr[i];
            leaders.insert(leaders.begin(), arr[i]);
        }
    }
    for(auto i : leaders) cout << i << " ";
}

int main(void) {
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];

    leadersArray(arr, n);

}