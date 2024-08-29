// Linear Search In range.

#include <iostream>
using namespace std;

bool linearSearch(int list[], int size, int target, int start, int end){
    if(list[size]== 0){
        return false;
    }
    for(int i = start ; i < end; i++){
        if(list[i] == target){
            return true;
        }
    }
    return false;
}

int main(void){

    int list[] = {12, 123, 1232, 45, 66, 18, 13, 7, 23, 83};
    int size = sizeof(list)/sizeof(list[0]);
    int target = 18;
    int start = 2, end = 6;

    int result = linearSearch(list, size, target, start, end);
    if(result == 1){
        cout << endl << "Found.";
    }
    else{
        cout << endl << "Not Found.";
    }

    return 0;
}