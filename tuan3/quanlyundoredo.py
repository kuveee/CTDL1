class UndoRedoManager:
    def __init__(self):
        self.undo_stack = []
        self.redo_stack = []

    def do_action(self, action):
        """Thực hiện một hành động và thêm vào undo stack."""
        self.undo_stack.append(action)
        self.redo_stack.clear()  # Xóa redo stack khi có hành động mới
        print(f"Thực hiện hành động: {action}")
        print(f"  undo_stack: {self.undo_stack}")
        print(f"  redo_stack: {self.redo_stack}\n")

    def undo(self):
        """Hoàn tác hành động cuối cùng."""
        if not self.undo_stack:
            print("Không có hành động nào để hoàn tác.")
            print(f"  undo_stack: {self.undo_stack}")
            print(f"  redo_stack: {self.redo_stack}\n")
            return

        action = self.undo_stack.pop()
        self.redo_stack.append(action)
        print(f"Hoàn tác hành động: {action}")
        print(f"  undo_stack: {self.undo_stack}")
        print(f"  redo_stack: {self.redo_stack}\n")

    def redo(self):
        """Làm lại hành động đã hoàn tác."""
        if not self.redo_stack:
            print("Không có hành động nào để làm lại.")
            print(f"  undo_stack: {self.undo_stack}")
            print(f"  redo_stack: {self.redo_stack}\n")
            return

        action = self.redo_stack.pop()
        self.undo_stack.append(action)
        print(f"Làm lại hành động: {action}")
        print(f"  undo_stack: {self.undo_stack}")
        print(f"  redo_stack: {self.redo_stack}\n")


# Ví dụ sử dụng
manager = UndoRedoManager()

manager.do_action("Gõ 'Hello'")  # Hành động 1
manager.do_action("Gõ ' World'")  # Hành động 2
manager.undo()  # Hành động 3
manager.undo()  # Hành động 4
manager.redo()  # Hành động 5
manager.redo()
manager.undo()
manager.do_action("Gõ '!'")
manager.undo()
manager.undo()
manager.redo()