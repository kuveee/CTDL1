function normalize_expression(expr::String)
    stack = []  # Dùng stack để lưu trữ các phép toán
    result = ""  # Chuỗi kết quả sau khi chuẩn hóa

    for i in 1:length(expr)
        char = expr[i]

        if char == '('
            # Khi gặp dấu mở ngoặc, ta sẽ xử lý thêm dấu ngoặc tiếp theo
            push!(stack, result)
            result = ""  # Tạm thời lưu trữ phần bên trong ngoặc
        elseif char == ')'
            # Khi gặp dấu đóng ngoặc, ta quay lại phần đã lưu trữ trước đó
            prev_expr = pop!(stack)
            result = prev_expr * result
        else
            # Nếu là ký tự khác (một toán hạng hoặc phép toán), ta thêm vào kết quả
            result *= char
        end
    end

    return result
end

# Hàm chính so sánh hai biểu thức
function compare_expressions(P1::String, P2::String)
    # Chuẩn hóa cả hai biểu thức
    normalized_P1 = normalize_expression(P1)
    normalized_P2 = normalize_expression(P2)

    # So sánh hai biểu thức đã chuẩn hóa
    if normalized_P1 == normalized_P2
        return "YES"
    else
        return "NO"
    end
end

# Đọc vào số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    P1 = readline()  # Đọc vào biểu thức P1
    P2 = readline()  # Đọc vào biểu thức P2
    println(compare_expressions(P1, P2))  # In kết quả cho bộ test
end
