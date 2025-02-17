function evaluate_prefix(exp::String)
    stack = []  # Ngăn xếp để lưu trữ các toán hạng
    for i in length(exp):-1:1  # Duyệt từ phải sang trái
        char = exp[i]
        
        if isdigit(char)  # Nếu là số
            push!(stack, parse(Int, string(char)))
        else  # Nếu là phép toán
            operand1 = pop!(stack)
            operand2 = pop!(stack)
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
    exp = readline()  # Đọc biểu thức tiền tố
    println(evaluate_prefix(exp))  # In kết quả tính toán
end
