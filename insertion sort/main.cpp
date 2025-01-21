#include<iostream>
#include<chrono>  
using namespace std;


void insertion_Sort(int arr[], int n) {
    for(int i = 1; i < n; i++) { 
        int key = arr[i];
        int j = i - 1;  
        while(j >= 0 && arr[j] > key) { 
            arr[j + 1] = arr[j];  
            j--;
        }
        arr[j + 1] = key; 
    }
}

int main() {
    int arr[]  = {66, 8, 4, 1, 99, 2, 365, 68, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Before sorting: " << "\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

    
    auto start = chrono::high_resolution_clock::now();

    insertion_Sort(arr, n);

    
    auto end = chrono::high_resolution_clock::now();

    cout << "After sorting: " << "\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";

   
    chrono::duration<double> duration = end - start;
    cout << "Time taken for sorting: " << duration.count() << " seconds." << endl;

    return 0;
}
