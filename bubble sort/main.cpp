#include<iostream>
#include<chrono>  
using namespace std;


void bublleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {  
        bool swapped = false; 
        for (int j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) { 
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;  
        }
    }
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

   
    auto start = chrono::high_resolution_clock::now();

    bublleSort(arr, n);

   
    auto end = chrono::high_resolution_clock::now();

    
    chrono::duration<double> duration = end - start;
    
    cout << "Sorted successfully: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    cout << "Time taken for sorting: " << duration.count() << " seconds." << endl;

    return 0;
}
