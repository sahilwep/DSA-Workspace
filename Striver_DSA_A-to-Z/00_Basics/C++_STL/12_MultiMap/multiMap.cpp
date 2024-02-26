/*
// Multimap 
    * same as map, difference is we can store duplicate keys.
    * stored duplicate keys in sorted manner.
*/


#include<bits/stdc++.h>
using namespace std;

void explainMultiMap(){

    multimap<int, int> mst;

    mst.insert({1,2});
    mst.emplace(3, 1);    // this mean {3, 1}, 3 is key, & 1 is value.
    mst.insert({3,5});  // this mean {3, 5}, 3 is key, & 5 is value.
    mst.insert({3,2});  // this mean {3, 2}, 3 is key, & 2 is value.
    mst.insert({2,5});  
    // keys may be duplicate but, every keys are in order.
    for(auto it : mst) cout << it.first << " " << it.second << endl;

    // rest of them are same as map.

}

int main(void){

    explainMultiMap();

    return 0;
}
