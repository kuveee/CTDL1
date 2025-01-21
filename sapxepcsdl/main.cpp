#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
using namespace std;


struct Record {
    string username;
    time_t login_date; 
};


void swap(Record& a, Record& b) {
    Record temp = a;
    a = b;
    b = temp;
}


int partition(vector<Record>& arr, int low, int high) {
    time_t pivot = arr[high].login_date;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].login_date > pivot) { 
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(vector<Record>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

      
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}


void printRecords(const vector<Record>& arr) {
    for (const auto& record : arr) {
        cout << "Username: " << record.username << ", Login Date: " << ctime(&record.login_date);
    }
}

int main() {
   
    vector<Record> records = {
        {"Alice", time(nullptr) - 86400}, 
        {"Bob", time(nullptr) - 172800},   
        {"Charlie", time(nullptr) - 432000}, 
        {"David", time(nullptr) - 2592000},  
        {"Eve", time(nullptr)}              
    };

    cout << "Danh sach ban dau:" << endl;
    printRecords(records);

  
    quickSort(records, 0, records.size() - 1);

    cout << "\nDanh sach sau khi sap xep:" << endl;
    printRecords(records);

    return 0;
}
