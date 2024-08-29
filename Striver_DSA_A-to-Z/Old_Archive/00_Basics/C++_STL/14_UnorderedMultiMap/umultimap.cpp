/*
// same as unordered map, but it can store duplicate keys.

*/

#include<bits/stdc++.h>
using namespace std;

void explainUnorderedMultiMap(){
    unordered_multimap<int, int> ummp;

    ummp.insert({1,21});
    ummp.insert({1,22});
    ummp.insert({2,23});
    ummp.insert({3,24});
    ummp.insert({3,26});
    ummp.insert({4,32});

    // it can store duplicate keys & in unordered way.
    for(auto it : ummp) cout << it.first << " " << it.second << endl;
    
}

int main(void){

    explainUnorderedMultiMap();

    return 0;
}