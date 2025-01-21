from collections import deque

class Robot:
    def __init__(self):
        self.history = deque()  # Sử dụng deque làm ngăn xếp lưu lịch sử hoạt động
        self.directions = {
            "tiến lên": "lùi lại",
            "lùi lại": "tiến lên",
            "quay trái": "quay phải",
            "quay phải": "quay trái"
        }

    def execute_command(self, command):
        """Thực hiện lệnh di chuyển và lưu vào lịch sử."""
        print(f"Robot thực hiện lệnh: {command}")
        self.history.append(command)
        

    def undo(self):
        """Hoàn tác lệnh di chuyển cuối cùng."""
        if not self.history:
            print("Không có lệnh nào để hoàn tác.")
            return

        last_command = self.history.pop()
        reverse_command = self.directions.get(last_command)

        if reverse_command:
            print(f"Hoàn tác lệnh: {last_command} -> Thực hiện: {reverse_command}")
        else:
            print(f"Không tìm thấy lệnh đảo ngược cho: {last_command}")
            

    def print_history(self):
      if not self.history:
        print("Lịch sử hoạt động trống")
        return
      print("Lịch sử hoạt động của Robot (mới nhất đầu tiên):")
      for command in self.history:
          print(command)


# Ví dụ sử dụng
robot = Robot()

robot.execute_command("tiến lên")
robot.execute_command("quay trái")
robot.execute_command("tiến lên")
robot.execute_command("lùi lại")

robot.print_history()

robot.undo()
robot.undo()
robot.undo()
robot.undo()
robot.undo()

robot.print_history()