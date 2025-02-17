#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    
    Node(int value) : data(value), next(nullptr) {} // Constructor
};


void insert(Node *&head, int data) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void deleteNode(Node *&head, int key) {
    if (!head) return; 

    Node *temp = head, *prev = nullptr;


    if (temp && temp->data == key) {
        head = temp->next;
        delete temp;
        return;
    }


    while (temp && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

 
    if (!temp) return;

    prev->next = temp->next;
    delete temp;
}

// Hàm hiển thị danh sách liên kết
void printList(Node *head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Giải phóng bộ nhớ của danh sách liên kết
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
