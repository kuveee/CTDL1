class Stack:
    def __init__(self):
        # Khởi tạo một danh sách trống để chứa các phần tử của stack
        self.stack = []

    def is_empty(self):
        # Kiểm tra xem stack có rỗng không
        return len(self.stack) == 0

    def push(self, item):
        # Thêm phần tử vào stack
        self.stack.append(item)

    def pop(self):
        # Lấy và loại bỏ phần tử ở trên cùng của stack
        if not self.is_empty():
            return self.stack.pop()
        else:
            print("Stack is empty!")
            return None

    def peek(self):
        # Lấy phần tử ở trên cùng mà không loại bỏ nó
        if not self.is_empty():
            return self.stack[-1]
        else:
            print("Stack is empty!")
            return None

    def size(self):
        # Trả về kích thước của stack
        return len(self.stack)

# Ví dụ sử dụng Stack
stack = Stack()

# Thêm phần tử vào stack
stack.push(10)
stack.push(20)
stack.push(30)

print("Top element is:", stack.peek())  # In ra phần tử trên cùng
print("Size of stack:", stack.size())   # In ra kích thước của stack

# Lấy phần tử từ stack
print("Popped element:", stack.pop())   # Lấy và loại bỏ phần tử trên cùng
print("Size of stack after pop:", stack.size())  # Kích thước stack sau khi pop
