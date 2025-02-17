def find_matching_parentheses(expression):
    """Tìm các cặp dấu ngoặc tương ứng trong biểu thức"""
    stack = []
    pairs = []

    for i, char in enumerate(expression):
        if char == '(':
            stack.append(i)
        elif char == ')':
            if stack:
                open_index = stack.pop()
                pairs.append((open_index, i))
    
    return pairs

def generate_expressions(current_expression, result_set):
    """Đệ quy để tạo ra các biểu thức bằng cách xóa các cặp dấu ngoặc"""
    result_set.add(current_expression)  # Thêm biểu thức hiện tại vào tập kết quả

    pairs = find_matching_parentheses(current_expression)  # Tính toán lại cặp ngoặc ở mỗi bước

    if not pairs:
        return

    for open_index, close_index in pairs:
        expression_without_pair = current_expression[:close_index] + current_expression[close_index+1:]
        expression_without_pair = expression_without_pair[:open_index] + expression_without_pair[open_index+1:]

        generate_expressions(expression_without_pair, result_set)

if __name__ == "__main__":
    input_expression = input().strip()  # Đọc biểu thức đầu vào

    result_expressions = set()
    generate_expressions(input_expression, result_expressions)

    for expr in sorted(result_expressions):  # Sắp xếp để kết quả nhất quán
        print(expr)
