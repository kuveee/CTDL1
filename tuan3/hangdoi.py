from collections import deque

class Queue:
    def __init__(self):
        self.queue = deque()

    # Thêm phần tử vào cuối hàng đợi
    def enqueue(self, item):
        self.queue.append(item)

    # Loại bỏ và trả về phần tử ở đầu hàng đợi
    def dequeue(self):
        if self.is_empty():
            raise IndexError("Dequeue from an empty queue")
        return self.queue.popleft()

    # Kiểm tra xem hàng đợi có rỗng không
    def is_empty(self):
        return len(self.queue) == 0

    # Lấy kích thước của hàng đợi
    def size(self):
        return len(self.queue)

    # Xem phần tử đầu tiên của hàng đợi mà không loại bỏ
    def peek(self):
        if self.is_empty():
            raise IndexError("Peek from an empty queue")
        return self.queue[0]

# Sử dụng hàng đợi
q = Queue()
q.enqueue(10)
q.enqueue(20)
q.enqueue(30)

print("Size of queue:", q.size())  # In ra kích thước hàng đợi
print("Front item:", q.peek())  # In ra phần tử đầu tiên

print("Dequeue:", q.dequeue())  # Xóa và in ra phần tử đầu tiên
print("Size of queue after dequeue:", q.size())  # In ra kích thước sau khi dequeue
