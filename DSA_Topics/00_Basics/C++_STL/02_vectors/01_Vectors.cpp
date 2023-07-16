/*
// Vectors

    * Problems with array is, once we declare the array size, we can't change it.
    * Vectors is a container which is dynamic in nature. We can always increase size of a vector whenever we wish.
    * Vectors is a container only which store elements in a similar fashion as the array does.
    * Syntax :  
            vector<datatype> vectorName;
    * or we can say vectors are dynamic arrays.
    * Definition : Vector are dynamic array that can store elements of the same datatypes. The size of the vectors can change during runtime, whenever we add or delete an element. 
    
    * emplace_back  is faster than push_back :
        * push_back : this method is used to insert elements in a vector from the end of the container. First it create temporary object by calling a constructor.
            * As the flexibility in the size of vector is dynamic, the size of the container also increased by 1 after inserting any new element.
        * emplace_back  : This method is used instead of creating the object using parameterized constructor and allocating it into a different memory, then passing it to the copy constructors, which will insert it into the vector. 
            * This function can directly insert the object without calling the copy constructor. 
        
        * when we use push_back, it has one construction & one is moved into it's resulting place, and then destructed the moved one & then destructed the first one. 
        * when we use emplace_back, it only has one construction & one destructor.
    
        * Conclusion : emplace_back is generally better that the push_back since it construct the object in-place, potentially avoiding a copy operation. However, push_back is simpler to use and can be more appropriate in certain situation. 
    * NOTE : vector can store only homogenous datatype.

*/  

#include <bits/stdc++.h>
using namespace std;

// Vector 
void explainVector(){
    // deceleration of vector.
    vector<int> v;  // this create an empty container { }

    v.push_back(1);     // this will states that, it will create a empty container and insert 1 into it -> {1}
    v.emplace_back(2);  // is is simillar to push_back, it  


    // deceleration of vector of pair datatype : 
    vector<pair<int, int>> v1;
    v1.push_back({1, 2});   // we need {} curly, because in pair we use this..
    v1.emplace_back(1, 2);   // we can directly insert the elements..
    
    // deceleration of vector already filled...
    vector<int> v2(5, 100);     // container containing 5 instances of 100 define.  {100, 100, 100, 100, 100}
    vector<int> v3(5);   // container containing {0, 0, 0, 0, 0} is declared, depends on compiler.


    // copy the value of container from one to another.
    vector<int> v4(5, 20);
    vector<int> v5(v4);

    // accessing elements from a vector.
    vector<int> v6 = {123, 423, 423, 44, 8};    // we know that index start from 0, so
    cout << endl << v6.at(0) << " "<< v6[0];    // one way is to use indexing wise.s

    // using with iterator we can access the vector.
    vector<int>::iterator it = v6.begin();  // begin() will give the first address of the vector element.
    it++;   // now iterator is shifted 1 to next memory.
    cout << endl << *(it) << " ";   // this will give the element of the vector, because we are using dereferencing.
    it = it + 2;    // it's shifted to 2 from the last shift.
    cout << endl << *(it) << " ";   // this will give the element of the vector.

    vector<int>::iterator it_1 = v6.end();   // this will give the address after the last element of the vector, means if we have vector like {2,3,4} & we use end() then we will get the address of element i.e after the element 4.
    cout << endl << *it_1;
    it_1--; // subtracting 1, means we want 1 back element address.
    cout << endl << *it_1;  // this will give the 9    


    vector<int> v7 = {123, 423, 223, 44, 8};    // we know that index start from 0, so

    // vector<int>::iterator it_2 = v7.rend();     // this will point the address before the 0th index of vector.
    // vector<int>::iterator it_3 = v7.begin();    // this will point the address at last element. i.e : 8
    // cout << endl << *it_2;
    // cout << endl <<  *v7.rend(); // this is reverse iterator
    // cout << endl <<  *v7.rbegin();   // this is reverse iterator
    // cout << endl <<  *v7.begin();    // this is forward iterator
    // cout << endl <<  *v7.end();  // this is forward iterator.

    cout << endl << v7.back() << endl;   // this will give the last element.

    // printing vector using loop
    for(vector<int>::iterator it = v7.begin(); it < v7.end(); it++){
        // cout << *(it) << " ";
    }
    cout << endl;
    // an improved way : using auto : this will automatically determine the datatype according to data.
    for(auto it = v7.begin(); it != v7.end(); it++){
        // cout << *it << " ";
    }
    cout << endl;
    // improved shorted : 
    for(auto it : v7){
        // cout << it << " ";
    }
    // auto : means auto assignation. eg: auto a = "sahil", compiler will automatically assign a to string type.

    // Deletion in a vector : 
    vector<int> v8 = {123, 423, 223, 44, 8};    // we know that index start from 0, so
    v8.erase(v8.begin() + 1);
    for(auto it : v8) cout << it << " ";    // 423 will be erased.
    cout << endl;
    
    // erasing in a range :     (start, end)  : note start will be included whereas, end will be excluded.
    vector<int> v9 = {12, 24, 42, 46, 9, 92};   
    v9.erase(v9.begin()+2, v9.begin()+ 4); // from 0 we start, so 42 to 46, will be erased, 9 will not be erased. 
    for(auto it : v9) cout << it << " ";    
    cout << endl;


    // Insert function : 
    vector<int> v10 = {1,3};   
    v10.insert(v10.begin(), 100);   // this will insert element at 0 index. {100, 1, 3}
    v10.insert(v10.begin() + 1, 2, 10);  // this will insert at the position, then the number of element want to insert, then the element. this will be the elements.  {100, 10, 10, 1, 3}

    // copy one vector into another.
    vector<int> copy(2,20);     // {20, 20}
    v10.insert(v10.begin(), copy.begin(), copy.end());    // {20, 20, 100, 10, 10, 1, 3}

    for(auto it : v10) cout << it << " ";
    cout << endl;

    // finding the size
    cout << endl << v10.size();


    // removing element
    vector<int> v11 = {1,3}
    v11.push_back() // {1}

    // swap the vector.

    // v1 = > {10, 20}
    // v2 = > {90, 50}
    // v1.swap(v2);     // v1 => {90, 50}, v2 => {10, 20}

    // v.clear()    // clear the entire vector.

    // v11.empty()  // this will return in 0 & 1
}

int main(void){

    explainVector();

    return 0;
}