function prefix_to_postfix(exp::String)
    stack = []  # Ngăn xếp để lưu các toán hạng và biểu thức
    # Duyệt từ phải sang trái
    for i in length(exp):-1:1
        char = exp[i]

        if isalpha(char)  # Nếu là toán hạng (chữ cái)
            push!(stack, string(char))
        else  # Nếu là phép toán
            operand1 = pop!(stack)
            operand2 = pop!(stack)
            expr = operand1 * operand2 * string(char)  # Tạo biểu thức hậu tố
            push!(stack, expr)
        end
    end

    return stack[1]  # Phần tử cuối cùng trong ngăn xếp là kết quả
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    exp = readline()  # Đọc biểu thức tiền tố
    println(prefix_to_postfix(exp))  # In kết quả hậu tố
end
