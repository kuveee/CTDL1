#include <iostream>
#include <ctime>  
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  
        }
    }
    swap(arr[i + 1], arr[high]);  
    return (i + 1);  
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  

      
        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high);
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arrSize = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorted: ";
    printArray(arr, arrSize);

 
    clock_t start_time = clock();

  
    quickSort(arr, 0, arrSize - 1);

    
    clock_t end_time = clock();

    cout << "After sorted: ";
    printArray(arr, arrSize);

   
    double elapsed_time = double(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Time taken for sorting: " << elapsed_time << " seconds." << endl;

    return 0;
}
