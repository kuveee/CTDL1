#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {} // Constructor
};


void insert(Node *&head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;

    if (head != nullptr) {
        head->prev = newNode;
    }
    head = newNode;
}


void deleteNode(Node *&head, int key) {
    if (!head) return; 

    Node *temp = head;

 
    if (temp->data == key) {
        head = temp->next;
        if (head) 
            head->prev = nullptr;
        delete temp;
        return;
    }

    // Tìm nút có giá trị cần xóa
    while (temp && temp->data != key) {
        temp = temp->next;
    }

    if (!temp) return; // Không tìm thấy

    // Cập nhật liên kết của nút trước và sau
    if (temp->prev) 
        temp->prev->next = temp->next;
    if (temp->next) 
        temp->next->prev = temp->prev;

    delete temp;
}

// Hiển thị danh sách liên kết đôi
void printList(Node *head) {
    while (head) {
        cout << head->data << " <-> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Giải phóng bộ nhớ của danh sách liên kết đôi
void freeList(Node *&head) {
    while (head) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);

    cout << "Danh sách sau khi chèn: ";
    printList(head);

    deleteNode(head, 20);
    cout << "Danh sách sau khi xóa 20: ";
    printList(head);

    freeList(head); // Giải phóng bộ nhớ

    return 0;
}
