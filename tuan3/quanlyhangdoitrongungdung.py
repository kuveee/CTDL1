from collections import deque

class RequestQueue:
    def __init__(self):
        self.queue = deque()

    def enqueue(self, request):
        """Thêm yêu cầu vào cuối hàng đợi."""
        self.queue.append(request)
        print(f"Đã thêm yêu cầu: {request} vào hàng đợi.")

    def dequeue(self):
        """Lấy và xử lý yêu cầu từ đầu hàng đợi."""
        if not self.queue:
            print("Hàng đợi rỗng, không có yêu cầu nào để xử lý.")
            return None

        request = self.queue.popleft()
        print(f"Đang xử lý yêu cầu: {request}")
        return request

    def is_empty(self):
        """Kiểm tra xem hàng đợi có rỗng không."""
        return len(self.queue) == 0

    def size(self):
      """Trả về kích thước hàng đợi"""
      return len(self.queue)

# Ví dụ sử dụng
request_queue = RequestQueue()

# Thêm các yêu cầu vào hàng đợi
request_queue.enqueue("Yêu cầu A")
request_queue.enqueue("Yêu cầu B")
request_queue.enqueue("Yêu cầu C")

print(f"Kích thước hàng đợi: {request_queue.size()}")

# Xử lý các yêu cầu
request_queue.dequeue()
request_queue.dequeue()

# Thêm yêu cầu mới
request_queue.enqueue("Yêu cầu D")

# Xử lý yêu cầu tiếp theo
request_queue.dequeue()
request_queue.dequeue()
request_queue.dequeue()