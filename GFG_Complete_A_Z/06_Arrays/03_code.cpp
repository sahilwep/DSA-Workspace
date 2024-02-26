/*
// Vectors in cpp : 

* Problem with simple array is we always waste space with allocating extra space.

// Vector Advantages : 
    * Dynamic size
    * Rich Library function 
    * easy to know size
    * no need to pass size
    * can be returned from function
    * By default initalized with default size : we can initalized vector with all the values as false or true or 1 or 0 or any.
    * we can copy vector to other. 

*/

#include<bits/stdc++.h>
using namespace std;



int main(void){

    // create a vector with size 100, and with default value as 69.
    vector<int> v(100, 69);
    for(auto i : v) cout << i << " " << endl;

    vector<int> v1;  // create a vector.
    v1.push_back(20);
    v1.push_back(10);
    v1.push_back(5);
    for(auto i : v1) cout << i << " " << endl;




    return 0;
}