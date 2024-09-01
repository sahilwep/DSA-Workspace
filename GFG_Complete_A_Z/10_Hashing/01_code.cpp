/*

// Introduction to Hashing: 
    * Used to implement dictionary, where we have key value pair.
    * It is also used to implement set where we have set of keys.


// Complexity: 
    * Average: O(1) -> Search, Insert, Delete



// Not useful for:
    * Finding closest value -> This Problem can be solved by AVL tree or Red Black tree.
    * Sorted Data   -> This Problem can be solved by AVL tree or Red Black tree.
    * Prefix Searching  -> Trie data structure can be useful in this case.



// Applications of Hashing: 
    * Dictionary
    * Database Indexing
    * Cryptography
    * Cache
    * Symbol Table in Compiler/Interpreter
    * Routers
    * Cache
    * Getting data from database & many more.

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> v(n);    // this will store the array element.

    for(int i=0;i<n;i++){
        cin >> v[i];
    }

    unordered_map<int, int> mp;
    for(int i=0;i<n;i++){
        mp[v[i]]++;
    }

    for(auto i : mp){
        cout << i.first << " " << i.second << endl;
    }

    return 0;
}