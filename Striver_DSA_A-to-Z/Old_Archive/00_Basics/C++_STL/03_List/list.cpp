/*
List : List can hold different data such as Numeric, character, logical etc.
    
    * List is double linked sequence that support both forward and backward traversal.
    * The time taken in the insertion and deletion in the beginning, end and middle is constant.  
    * It has non-contiguous memory and there is no pre allocation memory.
    * where as vector are placed in contiguous storage so they can be accessed and traversed using iterators.
    * List is not synchronized whereas vector is synchronized.
    * List does not have default size, whereas vector has not default size.
    * In list, each element requires extra space for the node which holds the element, including pointer to the next and previous element in the list, whereas in vector, each element only requires the space for itself only.
    * Insertion is cheaper no mater where in the list it occur. whereas in vector insertion is costly.


*/


#include <bits/stdc++.h>
using namespace std;

void explainList(){

    list<int> ls;   // { }
    ls.push_back(10);   // {10}
    ls.emplace_back(20);    // {10, 20}

    ls.push_front(40);  // {40, 10, 20}

    ls.emplace_front(12);   // {12, 40, 10, 20}

    for(auto it : ls) cout << it << " ";

    // rest function same as vector.
    // begin, end, rbegin, rend, clear, insert, size, swap.
}

int main(void){

    explainList();

    return 0;
}