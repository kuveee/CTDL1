#include <iostream>
using namespace std;

class Stack {
private:
    int *arr;
    int top;
    int capacity;

public:
    // Constructor
    Stack(int size) {
        arr = new int[size];
        capacity = size;
        top = -1;
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Kiểm tra stack có rỗng không
    bool isEmpty() {
        return top == -1;
    }

    // Kiểm tra stack có đầy không
    bool isFull() {
        return top == capacity - 1;
    }

    // Thêm phần tử vào stack
    void push(int x) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = x;
    }

    // Lấy và loại bỏ phần tử trên cùng
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return -1;  // Trả về giá trị lỗi
        }
        return arr[top--];
    }

    // Lấy phần tử trên cùng mà không loại bỏ
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;  // Trả về giá trị lỗi
        }
        return arr[top];
    }

    // Lấy kích thước của stack
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s(5);  // Tạo stack với dung lượng 5

    // Thêm phần tử vào stack
    s.push(10);
    s.push(20);
    s.push(30);

    // Lấy phần tử trên cùng mà không xóa
    cout << "Top element is: " << s.peek() << endl;

    // Loại bỏ phần tử trên cùng
    cout << "Popped element: " << s.pop() << endl;

    // Kiểm tra kích thước của stack
    cout << "Size of stack: " << s.size() << endl;

    return 0;
}
