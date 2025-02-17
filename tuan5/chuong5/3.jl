function simplify_expression(P::String)
    # Chuỗi kết quả
    result = ""
    sign_stack = [1]  # Dùng để theo dõi dấu + hoặc -
    
    i = 1
    while i <= length(P)
        char = P[i]
        
        if char == '('
            # Kiểm tra phép toán trước dấu ngoặc
            if i > 1 && P[i-1] == '-'
                # Nếu trước ngoặc có dấu -, thì đảo ngược các dấu bên trong
                push!(sign_stack, -sign_stack[end])
            else
                # Nếu trước ngoặc là dấu + hoặc không có dấu gì, giữ nguyên
                push!(sign_stack, sign_stack[end])
            end
            
        elseif char == ')'
            # Khi gặp dấu đóng ngoặc, ta chỉ cần pop dấu phép toán
            pop!(sign_stack)
        
        elseif char == '+' || char == '-'
            # Cập nhật dấu phép toán, dấu này cần thay đổi theo dấu ngoặc trước đó
            if sign_stack[end] == -1 && char == '-'
                push!(result, '+')
            elseif sign_stack[end] == -1 && char == '+'
                push!(result, '-')
            else
                push!(result, char)
            end
            
        else
            # Thêm toán hạng vào kết quả
            push!(result, char)
        end
        
        i += 1
    end
    
    return String(result)
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    P = readline()  # Đọc vào biểu thức
    println(simplify_expression(P))  # In kết quả cho bộ test
end
