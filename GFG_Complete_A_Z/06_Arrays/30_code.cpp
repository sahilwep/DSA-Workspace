/*
// Maximum Appearing element in Range: 
    
    I/p : left = [1, 2, 5, 15]
          right = [5, 8, 7, 18]
    
    O/p : 5
    Explanation: [[1,2, 3, 4, 5], [2, 3, 4, 5, 6, 7, 8], [5, 6, 7], [15, 16, 17, 18]]
                              -             -             -
    * Here maximum appearing element is "5"

    I/p : left = [1, 2,]
          right = [5, 4]
    O/p : 2
    Explanation: [[1, 2, 3, 4, 5], [2, 3, 4]]

// Constrains: 
    0 <= left[i], right[i] < 100
    0 <= i < 10^5

// Bruteforce Solution: First solution comes in my mind is..
    * We can store the range into an array or vector...
    * We can hashmap the range...
    * Then we can get the frequency of most occurring element range from hashmap..
    * TC : as the constrains for element is <100,
    * AS : O(n*m)...
    * TC : O(n*m), which is very high for long range & long index values...

// Naive Solution: 
    * It traverses to every range, & then traverses for every element for every range,
    * and, for every element it increases the frequency by 1, 
    * and, then traverses to frequency array & finds out the index which has the maximum value, & return the index.
    * This solution is very similar to bruteforce that comes in my mind....
    * TC : O(n*max)



// Efficient Solution: 
    * Working...

*/

#include<bits/stdc++.h>
using namespace std;


// Naive Solution: 
int maxAppear(int l[], int r[], int n){
    int freq[100] = {0};    // creating frequency array of size 100, with default value '0'
    for(int i=0;i<n;i++){
        for(int j=l[i];j<=r[i];j++){
            freq[j] += 1;   // storing the frequency...
        }
    }
    int res = 0;
    for(int i=1;i<100;i++){
        if(freq[i] > freq[res]){
            res = i;    // storing the frequency..
        }
    }
    return res;
}

// Bruteforce Solution: 
int maxAppear_(int l[], int r[], int n){
    vector<int> v;
    int k = 0;
    // storing the range into a vector : O(n*m)
    for(int i=0;i<n;i++){
        int start = l[i];
        int end = r[i];
        for(int j = start; j<=end;j++){
            v.push_back(j);
        }
    }
    // getting the max element : we can iterate to right side of array, as it contains end range : O(n)
    int max = r[0];
    for(int i=0;i<n;i++){
        if( r[i] > max){
            max = r[i];
        }
    }
    // storing the values into hashmap, to get the frequency of the range : O(max)
    int hash[max+1] = {0};  // create a hash array with default value 0
    for(int i=0;i<v.size();i++){
        // cout << v[i] << endl;
        hash[v[i]] += 1;    // increment the frequency, with v[i] elements. 
    }
    int maxFeq = hash[0];
    int res = 0;    // this is the index
    for(int i=0;i<max+1;i++){
        if(hash[i] > maxFeq){
            maxFeq = hash[i];
            res = i;    // storing the index..
        }
    }
    return res;
}


int main(void){
    int n;
    cin >> n;
    int l[n],  r[n];

    for(int i=0;i<n;i++) cin >> l[i];
    for(int i=0;i<n;i++) cin >> r[i];

    cout << maxAppear(l, r, n);

    return 0;
}