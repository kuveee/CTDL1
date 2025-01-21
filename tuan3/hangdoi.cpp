#include <iostream>

const int MAX_SIZE = 100; // Kích thước tối đa của hàng đợi

class Queue {
private:
    int arr[MAX_SIZE];
    int front;  // Chỉ số của phần tử đầu tiên
    int rear;   // Chỉ số của phần tử cuối cùng
    int count;  // Số lượng phần tử hiện tại

public:
    Queue() {
        front = 0;
        rear = -1;
        count = 0;
    }

    // Thêm phần tử vào cuối hàng đợi
    void enqueue(int data) {
        if (isFull()) {
            std::cout << "Hang doi day! Khong the them: " << data << std::endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE; // Xử lý tràn vòng (circular array)
        arr[rear] = data;
        count++;
    }

    // Xóa và trả về phần tử đầu tiên của hàng đợi
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Hang doi rong! Khong the lay ra." << std::endl;
            return -1; // Hoặc có thể throw exception
        }
        int data = arr[front];
        front = (front + 1) % MAX_SIZE; // Xử lý tràn vòng
        count--;
        return data;
    }

    // Kiểm tra hàng đợi có rỗng không
    bool isEmpty() {
        return count == 0;
    }

    // Kiểm tra hàng đợi có đầy không
    bool isFull() {
        return count == MAX_SIZE;
    }

    // Trả về phần tử đầu tiên của hàng đợi mà không xóa
    int peek() {
      if (isEmpty()){
        std::cout << "Hang doi rong!" << std::endl;
        return -1;
      }
      return arr[front];
    }

    // Trả về kích thước hiện tại của hàng đợi
    int size(){
      return count;
    }
};

int main() {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    std::cout << "Phan tu dau tien: " << q.peek() << std::endl;

    std::cout << "Lay ra: " << q.dequeue() << std::endl;
    std::cout << "Lay ra: " << q.dequeue() << std::endl;

    q.enqueue(40);
    q.enqueue(50);
    
    std::cout << "Kich thuoc hang doi: "<< q.size() << std::endl;

    while (!q.isEmpty()) {
        std::cout << "Lay ra: " << q.dequeue() << std::endl;
    }

    return 0;
}