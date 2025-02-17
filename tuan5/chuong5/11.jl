function evaluate_postfix(exp::String)
    stack = []  # Ngăn xếp để lưu trữ các toán hạng
    for char in exp
        if isdigit(char)  # Nếu là số
            push!(stack, parse(Int, string(char)))
        else  # Nếu là phép toán
            operand2 = pop!(stack)
            operand1 = pop!(stack)
            result = 0
            if char == '+'
                result = operand1 + operand2
            elseif char == '-'
                result = operand1 - operand2
            elseif char == '*'
                result = operand1 * operand2
            elseif char == '/'
                result = div(operand1, operand2)  # Sử dụng phép chia nguyên
            end
            push!(stack, result)  # Đẩy kết quả vào ngăn xếp
        end
    end
    return stack[1]  # Phần tử duy nhất trong ngăn xếp là kết quả
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    exp = readline()  # Đọc biểu thức hậu tố
    println(evaluate_postfix(exp))  # In kết quả tính toán
end
