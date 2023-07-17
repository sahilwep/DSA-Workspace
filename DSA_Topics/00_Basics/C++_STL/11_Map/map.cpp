/*
// Map : Map are associative container that store in a mapped fashion.
    * each element has a key value and a mapped value. 
    * No two mapped values can have same key values.
    * Map is a data-structure that stores in : 
        * KEY
        * VALUES
    * example : In a class "john", can be named as multiple person, but they can be identified with unique key i.e roll no so,
    * john => 31
    * john => 32
    * john => 33
    * So, here john is values, & 31, 31, are keys.
    * Keys are unique.
    * Key can be of any datatype, like int, double, pair..
    * similarly values can be of any type.
    
    * SYNTAX : 
        map<key, value> mapName;

    * NOTE : Map Stores unique keys in sorted order.
*/


#include <bits/stdc++.h>
using namespace std;

void explainMap(){

    map<int, int> mpp;

    map<int, pair<int, int>> mpp_1;
    
    map<pair<int, int>, int> mpp_2;

    mpp[1] = 2; // this mean {1:2}, 1 is key, & 2 is value.

    mpp.emplace(3, 1);    // this mean {3, 1}, 3 is key, & 1 is value.

    mpp.insert({2,4});  // this mean {2, 4}, 2 is key, & 4 is value.

    // for mpp_2 : key is pair & value is int
    mpp_2[{2,3}] = 10;  // this mean {2,3 : 10} 2,3 is key, & 10 is value.

    // for mpp
    for(auto itt : mpp) cout << itt.first << " : " << itt.second << endl;
    /*  
        print
            1 : 2
            2 : 4
            3 : 1
          key   value
    */    
    cout << endl;
    // for mpp_2
    for(auto itt : mpp_2) cout << itt.first.first << " " << itt.first.second << " : " << itt.second  <<  endl;
    /*
        print
            2 3 : 10   
            key   value
    */

    map<int, int> mpp_3 = {{1, 22}, {2, 23}, {3, 24}, {4, 25}};
    //  key                 1        2         3        4
    cout << endl << mpp_3[1];   // give the value at key 1  // map[key]
    cout << endl << mpp_3[3];   // give the value at key 3
    cout << endl << mpp_3[5];  // give the value at key 5, if there is no value, return 0 or null, if something doesn't exist give 0

    // know the iterator, that where the key 3 lies.
    // we can use find() function.
    auto iter = mpp_3.find(3);
    cout << endl << "key " << iter->first << " : " << iter->second << " value"; 

    auto iter_1 = mpp_3.find(5);    // if 5 is not ther it point mpp_3.end() value
    cout << endl <<  iter_1->first << " " << iter_1->second;    // return 5 0

    auto iter_2 = mpp_3.lower_bound(2);
    cout << endl << "Lower bound : "  << (iter_2)->first << " " << iter_2->second;
    auto iter_3 = mpp_3.upper_bound(3);
    cout << endl << "Upper Bound : " << iter_3->first << " " << iter_3->second ;

    // erase, swap, size, empty, are same as above.
}

int main(void){

    explainMap();

    return 0;
}