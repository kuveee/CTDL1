function postfix_to_infix(exp::String)
    stack = []  # Ngăn xếp để lưu các toán hạng và biểu thức
    # Duyệt từ trái sang phải
    for i in 1:length(exp)
        char = exp[i]

        if isalpha(char)  # Nếu là toán hạng (chữ cái)
            push!(stack, string(char))
        else  # Nếu là phép toán
            operand2 = pop!(stack)
            operand1 = pop!(stack)
            expr = "($operand1$char$operand2)"  # Tạo biểu thức trung tố
            push!(stack, expr)
        end
    end

    return stack[1]  # Phần tử cuối cùng trong ngăn xếp là kết quả
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    exp = readline()  # Đọc biểu thức hậu tố
    println(postfix_to_infix(exp))  # In kết quả trung tố
end
