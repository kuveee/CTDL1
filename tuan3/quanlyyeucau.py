from collections import deque

class SensorRequestManager:
    def __init__(self):
        self.request_queue = deque()

    def add_request(self, sensor_id, data):
        """Thêm yêu cầu từ cảm biến vào hàng đợi."""
        self.request_queue.append((sensor_id, data))
        print(f"Đã thêm yêu cầu từ cảm biến {sensor_id}: {data} vào hàng đợi.")

    def process_next_request(self):
        """Xử lý yêu cầu tiếp theo từ hàng đợi."""
        if not self.request_queue:
            print("Hàng đợi rỗng, không có yêu cầu nào để xử lý.")
            return None

        sensor_id, data = self.request_queue.popleft()
        print(f"Đang xử lý yêu cầu từ cảm biến {sensor_id}: {data}")
        # Thực hiện các xử lý cần thiết với dữ liệu từ cảm biến ở đây
        # ...
        return sensor_id, data

    def is_empty(self):
        """Kiểm tra xem hàng đợi có rỗng không."""
        return len(self.request_queue) == 0

# Ví dụ sử dụng
manager = SensorRequestManager()

# Thêm yêu cầu từ các cảm biến
manager.add_request("Cảm biến A", 25)
manager.add_request("Cảm biến B", 18)
manager.add_request("Cảm biến C", 32)

# Xử lý các yêu cầu
manager.process_next_request()
manager.process_next_request()

# Thêm yêu cầu mới
manager.add_request("Cảm biến D", 22)

# Xử lý yêu cầu
manager.process_next_request()
manager.process_next_request()
manager.process_next_request()