// Linear search with minimum number, Find the min number in list.

#include <iostream>
using namespace std;

void minNumber(int list[], int size){
    int min = list[0];
    for(int i = 0 ; i < size ; i++){
        if(list[i] < min){
            min = list[i];
        }
    }
    cout << endl << "Min no is : " << min;
}


int main(void){

    int list[] = {19, 83, 37, 3, 57, 1, 89, 8, 7};
    int size  = sizeof(list)/sizeof(list[0]);

    minNumber(list, size);

    return 0;
}