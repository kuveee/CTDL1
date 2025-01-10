#include<iostream>

using namespace std;

void insertion_Sort(int arr[],int n) {
    for(int i = 1;i<n;i++) {//duyet tu idx 2 den end
        int key = arr[i];
        int j = i -1;  //check cac gia tri truoc key
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];  //tim kiem gia tri be hon key 
            j--;
        }
        arr[j+1] = key; 
    }
}
void insertion_Sort(int arr[],int n) {
    for(int i = 1;i<n;i++) {//duyet tu idx 2 den end
        int key = arr[i];
        int j = i -1;  //check cac gia tri truoc key
        while(j>=0 && arr[j] > key) {
            arr[j+1] = arr[j];  //tim kiem gia tri be hon key 
            j--;
        }
        arr[j+1] = key; 
    }
}



int main() {
    int arr[]  = {66,8,4,1,99,2,365,68,12};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "before sorted: "<< "\n";
    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
    insertion_Sort(arr,n);
    cout << "after sorted: "<< "\n";
    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    }

}