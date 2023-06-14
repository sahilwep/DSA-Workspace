// Linear Search working with Strings;

#include <iostream>
using namespace std;

bool linearSearch(string name, int size, char target){
    for(int i = 0; i < size; i++){
        if(name[i] == target){
            return true;
        }
    }
    return false;
}


int main(void){
    string name = "Sahil";
    int size = name.size();
    char target = 'a';

    int result = linearSearch(name, size, target);
    if(result == 1){
        cout << endl << "Found.";
    }
    else{
        cout << endl << "Not Found.";
    }


    return 0;
}