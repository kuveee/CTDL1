# Hàm chuyển từ tiền tố sang trung tố
function prefix_to_infix(exp::String)
    stack = []   # Ngăn xếp dùng để lưu các biểu thức

    # Duyệt qua biểu thức từ phải sang trái
    for i in length(exp):-1:1
        char = exp[i]

        if isalpha(char)  # Nếu là ký tự toán hạng, đẩy vào ngăn xếp
            push!(stack, string(char))
        else  # Nếu là phép toán
            # Pop hai toán hạng từ ngăn xếp
            operand1 = pop!(stack)
            operand2 = pop!(stack)
            
            # Tạo biểu thức trung tố và đẩy vào ngăn xếp
            expr = "($operand1 $char $operand2)"
            push!(stack, expr)
        end
    end

    # Phần tử cuối cùng trong ngăn xếp là kết quả
    return stack[1]
end

# Đọc số bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    exp = readline()  # Đọc vào biểu thức tiền tố
    println(prefix_to_infix(exp))  # In kết quả trung tố
end
