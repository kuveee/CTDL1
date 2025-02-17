def is_operator(c):
    return c in {'+', '-', '*', '/'}

def evaluate_prefix(prefix):
    values = []  # Sử dụng danh sách làm stack
    
    prefix = prefix[::-1]  # Đảo ngược chuỗi để duyệt từ phải sang trái
    
    for c in prefix:
        if c.isdigit():  # Nếu là số, đẩy vào stack
            values.append(int(c))
        elif is_operator(c):
            if len(values) < 2:
                return -99999  # Biểu thức không hợp lệ
            val1 = values.pop()
            val2 = values.pop()
            
            if c == '+':
                values.append(val2 + val1)
            elif c == '-':
                values.append(val2 - val1)
            elif c == '*':
                values.append(val2 * val1)
            elif c == '/':
                if val1 == 0:
                    return -99999  # Xử lý chia cho 0
                values.append(val2 // val1)  # Chia nguyên
    
    return values[0] if len(values) == 1 else -99999

def main():
    t = int(input().strip())  # Số lượng test cases
    
    for _ in range(t):
        prefix_expression = input().strip()
        result = evaluate_prefix(prefix_expression)
        print(result)

if __name__ == "__main__":
    main()
