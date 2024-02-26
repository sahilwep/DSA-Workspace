#include <iostream>

void customInsertionSort(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i;

        if (i % 2 == 0) {
            while (j > 0 && arr[j - 2] < key) {
                arr[j] = arr[j - 2];
                j -= 2;
            }
        } else {
            while (j > 0 && arr[j - 2] > key) {
                arr[j] = arr[j - 2];
                j -= 2;
            }
        }

        arr[j] = key;
    }

    // Print the sorted array
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
}

int main() {
    int n;
    std::cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) std::cin >> arr[i];
    
    customInsertionSort(arr, n);

    return 0;
}
