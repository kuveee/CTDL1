#include<iostream>
using namespace std;

// duyet tu 0 -> n-1 , moi lan loop : max = n  , check j and j+1 

void bublleSort(int arr[],int n) {
    for (int i=0;i<n-1;i++) { // vi phan tu cuoi the ss voi phan tu nao khac nen n-11
        bool swapped = false;  //gia tri nay de check xem co xay ra hoan doi khong , neu khong thi khong can sap xep nua 
        for(int j=0;j<n-i-1;j++) {  //sau moi lan thi gia tri lon nhat se o cuoi nen kh can xet den vi vay j<n-i-1
            if(arr[j]> arr[j+1]) {  //check j va j+11
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped) {
            break;
        }
    }
}


int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    bublleSort(arr,n);

    cout << "sorted sucess: " << "\n";
    for(int i = 0;i<n;i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

