def has_redundant_parentheses(exp):
    stack = []
    
    for ch in exp:
        if ch == ')':  # Khi gặp dấu đóng ngoặc ')'
            top = stack.pop()
            is_redundant = True  # Giả định ban đầu là có dư thừa
            
            # Kiểm tra bên trong cặp dấu ngoặc có toán tử hay không
            while stack and top != '(':
                if top in "+-*/":
                    is_redundant = False  # Nếu có toán tử, không dư thừa
                top = stack.pop()
            
            if is_redundant:
                return True  # Nếu không có toán tử nào, tức là dấu ngoặc dư thừa
        else:
            stack.append(ch)  # Đẩy ký tự vào stack
    
    return False  # Nếu duyệt hết mà không phát hiện dư thừa thì hợp lệ

# Nhập số lượng test case
T = int(input())
for _ in range(T):
    exp = input().strip()
    print("No" if has_redundant_parentheses(exp) else "Yes")
