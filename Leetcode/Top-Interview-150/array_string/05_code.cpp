 /*
 //  169. Majority Element                  https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

    * The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

// Bruteforce Solution: 
    * We can use nested loop to compare the frequency, as if anytime the frequency of any element is more than n/2, we return that element..

    * TC : O(n^2)
    * AS : O(1)

// Using Sorting: 
    * Sort all the element...
    * If all the element is sorted, means we can directly return the n/2 element...
    * If the element is majority, then it defiantly appears at (n/2) position, because indexing start from 0th position..
    * so this will always return the majority element, if the majority candidate exist, 
    * If frequency of all the element is same, it return any of them...
    * But anyways, the constrains here is there must be (n/2 + 1) element exist, as it has to be majority element...

    * TC : O(nlogn)
    * AS : O(1)

// Using HashMap: 
    * We can use unordered_map to store the element frequency...
    * Then we compare the frequency of element occurring more than n/2 times...
    * If there is such element has frequency has more than n/2 times, we return that element..

    * TC : O(n)
    * AS : O(n)

// Efficient Approach : 
    * We can use Moore voting algorithm: 
        * This works on the constrains, the element should be appears more than n/2 times in an array.
        * Steps : 
            * first step is to find the most occurring element..
            * Second step to count the number of occurrence of that element in list.
            * compare if that element is occur less than n/2 times, return -1 : else return that element.

    * TC : O(n)
    * AS : O(1)


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
 #define SQ(a) (a)*(a)
 
// Bruteforce Solution: 
int majorityElement_B(vector<int> &arr){
    int n = arr.size();
    int count;
    for(int i=0;i<n;i++){
        int count = 0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
        }
        if(count > n/2){
            return arr[i];
        }
    }
    return 0;
}

// Using Sorting: 
int majorityElement_S(vector<int> &arr){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    return arr[n/2];
}


// Using HashMap: 
int majorityElement_H(vector<int> &arr){
    int n = arr.size();
    unordered_map<int, int> m;

    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }

    n = n/2;    // making the size as half, we we know that the maximum element should appear more than n/2 times.
    for(auto i : m){
        // comparing frequency, as if it's more than size, we return element.
        if( i.second > n){
            return i.first;
        }
    }
    return 0;
}

// Efficient Approach: 
int majorityElement(vector<int>& arr) {
    // first step to find the most occurring elements
    int n = arr.size();
    int res = 0;    //position 
    int count = 1;  //setting the counter 1, at starting.
    for(int i=0;i<n;i++){
        // Condition to increase frequency, if element has occurring..
        if(arr[i] == arr[res]){
            count++;    
        }
        else {
            count--;    // else decreasing the counter...
        }
        // Changing the (arr[res])-> element that we are comparing...
        if(count == 0){
            res = i;    // making the candidate as new current (arr[i])->element.
            count = 1;  // reseting the counter..
        }
    }
    // Second step is to finding the frequency of that element.
    count = 0;  // resiting the counter
    for(int i=0;i<n;i++){
        if(arr[i] == arr[res]){
            count++;
        }
    }
    // Checking the condition if that element is less than or equal n/2, we return -1
    if(count <= n/2){
        return 0;
    }
    return arr[res];    // returning the most occurring element..
}


void solve(){
   int n;
   cin >> n;
   vector<int> arr(n);
   for(int i=0;i<n;i++){
       int k;
       cin >> k;
       arr[i] = k;
   }
   cout << majorityElement(arr);
   el;
}


int main(){
    int t;     // Change the testcase according to question...
    cin >> t;
    while(t--){
        solve();
    }
    
    return 0;
}