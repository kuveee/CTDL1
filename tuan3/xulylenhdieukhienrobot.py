from collections import deque

class RobotController:
    def __init__(self):
        self.command_queue = deque()

    def add_command(self, command):
        """Thêm lệnh điều khiển vào hàng đợi."""
        self.command_queue.append(command)
        print(f"Đã thêm lệnh: {command} vào hàng đợi.")

    def execute_next_command(self):
        """Lấy và thực thi lệnh tiếp theo từ hàng đợi."""
        if not self.command_queue:
            print("Hàng đợi rỗng, không có lệnh nào để thực thi.")
            return None

        command = self.command_queue.popleft()
        print(f"Đang thực thi lệnh: {command}")
        # Thực hiện các hành động tương ứng với lệnh ở đây
        # ...
        return command
    
    def is_empty(self):
      """kiểm tra hàng đợi rỗng hay không"""
      return len(self.command_queue) == 0

# Ví dụ sử dụng
controller = RobotController()  

# Thêm các lệnh điều khiển vào hàng đợi
controller.add_command("Tiến lên")
controller.add_command("Quay phải")
controller.add_command("Tiến lên")
controller.add_command("Lùi lại")

# Thực thi các lệnh
while not controller.is_empty():
    controller.execute_next_command()

controller.execute_next_command()