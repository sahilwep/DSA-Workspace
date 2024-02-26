// find maximum and minimum in 2d Array.

#include <iostream>
using namespace std;

void max_min_Number(int list[][3], int row_size, int col_size){
    int max = list[0][0];
    int min = list[0][0];
    for(int i = 0 ; i < row_size ; i++){
        for(int j = 0 ; j < col_size ; j++){
            if(list[i][j] < min){
                min = list[i][j];
            }
            if(list[i][j] > max){
                max = list[i][j];
            }
        }
    }
    cout << endl << "Max size : " << max << endl << "Min size : " << min;
}

int main(void){

    int list[][3] = {
        {-2, -1, 0},
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10, 11, 12},
        {13, 99, 101}
    };

    int row_size = sizeof(list)/sizeof(list[0]);
    int total_size = sizeof(list)/sizeof(list[0][0]);
    int col_size = total_size / row_size;

    max_min_Number(list, row_size, col_size);


    return 0;
}