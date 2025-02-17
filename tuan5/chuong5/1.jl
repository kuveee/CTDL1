function check_redundant_parentheses(expression::String)
    stack = String[]  # Sử dụng một ngăn xếp (stack) để theo dõi các dấu ngoặc
    for char in expression
        if char == '('
            push!(stack, '(')  # Đẩy dấu '(' vào ngăn xếp
        elseif char == ')'
            if !isempty(stack) && stack[end] == '('
                pop!(stack)  # Nếu gặp dấu ')', kiểm tra xem có dấu '(' để tạo thành cặp
                if !isempty(stack) && stack[end] == '('
                    return "Redundant parentheses found"  # Dấu ngoặc dư thừa nếu nó không có tác dụng
                end
            else
                push!(stack, ')')  # Nếu không có dấu '(', thì đẩy dấu ')'
            end
        end
    end
    return "No redundant parentheses"
end

# Đọc vào số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    exp = readline()  # Đọc vào biểu thức
    println(check_redundant_parentheses(exp))  # Kiểm tra và in kết quả
end
