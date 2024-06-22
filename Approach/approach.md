# Useful Approach used during problems solving:  

## Bruteforce Solution: 
* Try to solve every questions with bruteforce solution, solution that comes first in your mind, doesn't matter, it takes $O(n^2)$ or  $O(n*m)$ and it gives TLE, at-least you solutions should works on all the test-cases, because we can improve our bruteforce solution.

## Hashing: 
* Hashing is one of the important technique which is used variety of question regarding frequency.
* In hashing we are storing the frequency of every element.
* To use hashing we have many technique, it's all depends on our needs.
  
### Hashing elements using hash array or vector `int hash[n] = {0} or vector<int> vec(n, 0)` 
```cpp
void func(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;   // macros defined to take array input.

    // Initialization of hashing: 
    // size should be depends on max, value in an array..
    int hash[n] = {0}   // hash[] array declare with default value '0'
    vector<int> hash1(n, 0);    // hash1 vector define with default value '0'

    // Storing frequency: 
    for(int i=0;i<n;i++){
        hash[arr[i]]++;     // store the frequency of that element on specific "arr[i]" as index.
        hash1[arr[i]]++;    // same with vector...
    }

    // accessing elements of hash:
    for(int i=0;i<n;i++){
        cout << i << hash[i] << " ";    // here i is element of an array, & hash[i] is frequency of that element.
        // cout << i << hash1[i] << " ";   // same way we can print hash stored in vector.
    }
    el; // macros defined to break line.
}
```

### Hashing Using `std::map`

* map stores hash value in sorted fashion, & when we are using map, we don't need to take care of size while storing elements into map.
* Searching takes: $O(logn)$
* Insertion takes: $O(logn)$ + `Rebalance`
* For more information about Time complexity of others operations visit: [GFG Map v/s Unordered Map](https://www.geeksforgeeks.org/map-vs-unordered_map-c/)

```cpp
void func(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;   // macros defined to take array input.

    // Initialization of map:
    map<int, int> mp;

    // hashing: 
    for(int i=0;i<n;i++){
        mp[arr[i]]++;
    }

    // traversing in map:
    for(auto i=mp.begin();i!=mp.end();i++){
        cout << i->first << " " << i->second;   // first value will be number, & second value will be index.
    }
}
```

### Hashing Using `std::unordered_map`

* 
* Searching takes: 
  * Avg: $O(1)$ 
  * worst: $O(n)$
* Insertion takes: `same as search`

```cpp
void func(){
    int n;
    cin >> n;
    int arr[n];
    arrInp;   // macros defined to take array input.

    // Initialization of unordered_map:
    unordered_map<int, int> ump;

    // hashing: 
    for(int i=0;i<n;i++){
        ump[arr[i]]++;
    }

    // traversing in map:
    for(auto i=ump.begin();i!=ump.end();i++){
        cout << i->first << " " << i->second;   // first value will be number, & second value will be index.
    }
}
```


## Two-Pointers: 

* Two-pointers is one of the important technique, which used to improve time complexity.
* We maintain two pointers in & depending our needs, we move them..
* Example: Reversal of an array
```cpp
void reverse(int arr[], int n){
    int ptr1 = 0;
    int ptr2 = n-1;
    while(ptr1 < ptr2){
        swap(arr[ptr1++], arr[ptr2--]);
    }
}
```
* At every iteration we swap `ptr1` & `ptr2` located elements and increase `ptr1` and decrease `ptr2`.
* There are many others examples that can solve by two pointer approach & improve time complexity from $O(n^2$ to $O(n)$



## upper_bound()

* `upper_bound()`: It return an iterator pointing to first element in the range [first, last] that is grater value, or last if no element is found.
* The element in that range shall already be sorted or at-least partitioned with respect to value.
* `upper_bound()` function uses `binary-search` internally.
* `upper_bound()` return iterator:
  * if we subtract `v.begin()` means first iterator, then we will get the index.
  * or if we directly store the result into an iterator, we will get the value itself.

> Example: 
```plain
Input : 10 20 30 30 40 50
Output : upper_bound for element 30 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 45 is at index 4

Input : 10 20 30 40 50
Output : upper_bound for element 60 is at index 5
```
* Uses:

```cpp
int func(){
    vector<int> v = {10, 20, 30, 40, 50, 60}; // elements should be sorted
    
    int index = upper_bound(v.begin(), v.end(), 35) - v.begin();   // subtract v.begin() to iterator will give index

    vector<int>::iterator it = upper_bound(v.begin(), v.end(), 35);    // we can directly store iterator in an iterator type array
    
    cout << "Element " << *it << endl;   // use dereference to fetch the vlaue.
    cout << "Index " << index << endl;
    
}
```

* Useful in variety of question where we need searching..
