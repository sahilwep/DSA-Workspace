// Linear Search Maximum number, Find the maximum number in list.

#include <iostream>
using namespace std;

void maxNumber(int list[], int size){
    int max = list[0];
    for(int i = 0; i < size; i++){
        if(list[i] > max){
            max = list[i];
        }
    }
    cout << endl << "Max number in list : " << max;
}

int main(void){

    int list[] = {19, 83, 37, 3, 57, 1, 89, 99, 7};
    int size = sizeof(list)/sizeof(list[0]);

    maxNumber(list, size);

    return 0;
}