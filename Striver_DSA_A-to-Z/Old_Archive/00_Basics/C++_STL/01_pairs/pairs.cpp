/*
pair : pairs is the part of "utility library". 
* Pair is used to combine together two values that may be of different data type.


*/

#include <bits/stdc++.h>
using namespace std;

// Pairs
void explainPairs(){
    pair<int, int> p = {2,3};

    cout << endl << p.first << " " << p.second;

    // nested properties of pair.
    pair<int, pair<int , int>> p1= {1,{2,3}};

    cout << endl << p1.first << " " << p1.second.first << " " << p1.second.second;

    // declaring pair array.
    pair<int, int> arr[] = {{1,2}, {3, 4}, {5, 6}};

    cout << endl << arr[1].second;

    // storing different datatypes.
    pair<int, string> p3= {1, "sahil"};

    cout << endl << p3.first << " " << p3.second;
}

int main(void){

    explainPairs();

    return 0;
}