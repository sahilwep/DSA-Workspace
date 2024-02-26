/*
//  Unordered Map :
    * everything as similar to map, but it is not sorted.
    * it store values in random manner.
    * it store only unique keys.

*/

#include <bits/stdc++.h>
using namespace std;

void explainUnorderedMap(){

    unordered_map<int, int> ump;
    ump.insert({1,12});
    ump.insert({1,13}); // this will not store.
    ump.insert({2,14});
    ump.insert({3,24});

    for(auto it : ump) cout << it.first << " " << it.second << endl;


}

int main(void){

    explainUnorderedMap();

    return 0;
}