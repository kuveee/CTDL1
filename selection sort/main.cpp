#include<iostream>
using namespace std;

void swap(int &a,int &b) {
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(int arr[],int n) {
    for (int i = 0;i<n-1;i++) {    //lay gia tri min lam moc
        int min = i;
        for(int j = i+1;j<n;j++) { // duyet min+1 den cuoi mang
            if(arr[min] > arr[j]) {  //check va cap nhat min
                min = j;
            }
        }
        swap(arr[i],arr[min]);  // hoan doi gia tri tim duoc 
    }
}

int main() {
    int arr[] = {6,7,1,2,3,9,0,123,23,5,6,756};
    int n = sizeof(arr) / sizeof(arr[0]);
    selection_sort(arr,n);
    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}