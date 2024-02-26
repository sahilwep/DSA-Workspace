/*
// left rotate array by D place

        arr[]    1  2   3   4   5   6   7       
                                            d = 2
  final array :  3   4   5   6   7  1   2     
                                            d = 7
  final array :  1  2   3   4   5   6   7       
    // If we rotate this with the 7 it will come back to the original place.

    for d = 9,
        7 + 2
        // we can say : we will have to do 2 rotation.
    for 15 
        7 + 7 + 1
        // we can say we will have to do 1 rotation.

    // so we can say, multiple of 7 will always bring back to the original place.
    // the remaining what we have to do...

    so, the rotation will always be, 
        d = d % n
    eg: d=20,
        20 % 7 => 6, we will have to do only 6 rotation...`
    // original array : 1 2 3 4 5 6 7
        (1 2 3 4 5 6) will go last, & 7 will come at first.
    // result array : 7 1 2 3 4 5 6

// Bruteforce :

    * array : 1 2 3 4 5 6 7
      index : 0 1 2 3 4 5 6

    * if d = 3
        temp[] = { 1 2 3 }
    * shifting : 
        3--> 0(index)
        4--> 1(index)
        5--> 2(index)
        6--> 3(index)
        7--> 3(index)
        * So we can say : (i-d) index...
        for(i = d; i<n; i++){
            a[i-d] = a[i];  // shifting 
        }
        final array : 4 5 6 7
    * after we put the temp...
    * if we have array with size 7, & we are shifting with 3, the last 3 place will only be occupied.
        * so start from (n - d)
         j = 0
         for(i = n-d; i<n;i++){
            a[i] = temp[j];
            j++
         }

         or without j 

         * we can subtract with base value, i.e : (n-d)

         for(i = n-d; i<n;i++){
            a[i] = temp[  i - (n-d) ];
            
         }


// Optimized : 
    * first step rounding the d,
    
                        n = 7,  d = 3
        arr[ ]  =   1 2 3 4 5 6 7
                    ^ ^ ^
        final :     4 5 6 7 1 2 3
                            ^ ^ ^
                * 1,2,3 will move at the last..

        //  for the array : 1 2 3 4 5 6 7
        * If we reverse d place, it's looks like : 3 2 1
            * & final array :   3 2 1 4 5 6 7
        * if we reverse rest array expect, d : 7 6 5 4
            * & final array :   3 2 1 7 6 5 4
        * At last if we reverse the whole array, final array be like : 4 5 6 7 1 2 3
        * By doing this we can rotate array by D places..
        
        //  pseudo code :
                rev(a, a+d)     TC : O(d)
                rev(a+d, a+n)   TC : O(n-d)
                rev(a, a+n)     TC : O(n)

                TC : O(d) + O(n-d) + O(n)   => O(2n)
                SC : O(1)

// input : 
1 
7
1 2 3 4 5 6 7
3
// output : 
4 5 6 7 1 2 3 

*/


#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
// Bruteforce : 
    void leftRotateD_Place(int arr[], int n, int d){
        d = d % n;  // to get rounded figure of d
        int temp[d];
        // assigning the values into temp.
        for(int i=0;i<d;i++){
            temp[i] = arr[i];
        }
        // shifting
        for(int i=d;i<n;i++){
            arr[i-d] = arr[i];
        }
        // re-assigning.
        for(int i=n-d;i<n;i++){
            arr[i] = temp[i - (n-d)];
        }
    }
// Optimal :
    void leftRotateD_place_1(int arr[], int n, int d){
        d = d % n;    // rounding the d 

        rev(arr, 0, d-1); // reverse the d elements
        rev(arr, d, n-1); // reverse the rest element, except d
        rev(arr, 0, n-1); // reverse the whole array : 

        // reverse(arr, arr+d);    // first reverse the first d element.
        // reverse(arr+d, arr+n);  // second reverse the left element.
        // reverse(arr, arr+n);    // reverse the whole array.

    }

// reverse function : 
    void rev(int arr[], int start, int end){
        while (start<=end){
            // swapping : 
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            // using two pointer..
            start++;
            end--;
        }
    }
};


int main(void){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int arr[n];
        for(int i=0;i<n;i++) cin >> arr[i];
        int d;
        cin >> d;
        Solution obj;
        obj.leftRotateD_place_1(arr, n, d);
        for(auto i:arr) cout << i << " ";
        cout << endl;
    }
    return 0;
}