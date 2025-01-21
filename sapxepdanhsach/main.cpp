#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


struct Student {
    string name;
    int score;
};


void merge(vector<Student>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

   
    vector<Student> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

  
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
     
        if (leftArr[i].score < rightArr[j].score) {
            arr[k] = leftArr[i];
            i++;
        } else if (leftArr[i].score > rightArr[j].score) {
            arr[k] = rightArr[j];
            j++;
        } else {
   
            if (leftArr[i].name <= rightArr[j].name) {
                arr[k] = leftArr[i];
                i++;
            } else {
                arr[k] = rightArr[j];
                j++;
            }
        }
        k++;
    }

    
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }


    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}


void mergeSort(vector<Student>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

     
        merge(arr, left, mid, right);
    }
}


void printStudents(const vector<Student>& arr) {
    for (const auto& student : arr) {
        cout << student.name << ": " << student.score << endl;
    }
}

int main() {
    vector<Student> students = {
        {"Alice", 90},
        {"Bob", 90},
        {"Charlie", 85},
        {"David", 85},
        {"Eve", 95},
        {"Frank", 80}
    };

    cout << "Danh sAch hoc sinh ban dadau:" << endl;
    printStudents(students);

  
    mergeSort(students, 0, students.size() - 1);

    cout << "\nDanh sach hoc sinh sau khi sap xep:" << endl;
    printStudents(students);

    return 0;
}
