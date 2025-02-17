def solve_expression(expression, sign_multiplier):
    output_expression = ""  # Chuỗi kết quả sau khi loại bỏ ngoặc
    i = 0

    while i < len(expression):
        char_at_i = expression[i]

        if char_at_i.isalpha():
            # Nếu là toán hạng (ký tự chữ cái), thêm trực tiếp vào kết quả
            output_expression += char_at_i
        elif char_at_i == '+':
            # Nếu là dấu '+', thêm '+' hoặc '-' vào kết quả tùy thuộc vào sign_multiplier
            output_expression += '+' if sign_multiplier == 1 else '-'
        elif char_at_i == '-':
            # Nếu là dấu '-', thêm '-' hoặc '+' vào kết quả tùy thuộc vào sign_multiplier
            output_expression += '-' if sign_multiplier == 1 else '+'
        elif char_at_i == '(':
            # Nếu là dấu '(', bắt đầu xử lý biểu thức con bên trong ngoặc
            start_index = i
            balance = 1
            i += 1  # Bắt đầu từ vị trí sau dấu '('

            while balance > 0:
                if expression[i] == '(':
                    balance += 1  # Nếu gặp '(', tăng balance
                elif expression[i] == ')':
                    balance -= 1  # Nếu gặp ')', giảm balance
                i += 1  # Tiếp tục duyệt

            end_index = i - 1  # Vị trí dấu ')' đóng ngoặc
            substring_inside = expression[start_index + 1:end_index]  # Lấy chuỗi con bên trong ngoặc
            inner_result = solve_expression(substring_inside, -sign_multiplier)  # Đệ quy để xử lý biểu thức con
            output_expression += inner_result  # Thêm kết quả của biểu thức con vào kết quả chung
            i -= 1  # Điều chỉnh i để vòng lặp tiếp tục đúng vị trí sau dấu ')' đã xử lý
        # Không cần xử lý ')' ở mức này vì nó đã được xử lý trong đoạn trên
        i += 1

    return output_expression

# Đọc số lượng test case
t = int(input())

for _ in range(t):
    p = input().strip()  # Đọc biểu thức đầu vào
    print(solve_expression(p, 1))  # Gọi hàm giải biểu thức với hệ số dấu ban đầu là 1
