// Bubble Sort.

#include <iostream>
using namespace std;

void sort(int list[], int size){
    for(int i = 0; i < size -1; i++){
        for(int j = 0; j < size -1; j++){
            if(list[j] > list[j+1]){
                int temp = list[j];
                list[j] = list[j+1];
                list[j+1] = temp; 
            }
        }
    }
}

void print(int list[], int size){
    cout << endl << "Array list : ";
    for(int i = 0 ; i < size; i++){
        cout << list[i] << " ";
    }
}

int main(void){

    int list[] = {11, 10, 9, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4};
    int size = sizeof(list)/sizeof(list[0]);
    
    sort(list, size);
    print(list, size);

    return 0;
}