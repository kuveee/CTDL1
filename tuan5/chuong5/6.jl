# Hàm để xác định độ ưu tiên của các phép toán
function precedence(op)
    if op == "^"
        return 3
    elseif op == "*" || op == "/"
        return 2
    elseif op == "+" || op == "-"
        return 1
    else
        return 0
    end
end

# Hàm chuyển từ dạng trung tố sang hậu tố
function infix_to_postfix(exp::String)
    stack = []   # Ngăn xếp dùng để lưu các phép toán
    result = ""  # Chuỗi kết quả hậu tố

    for char in exp
        if isalpha(char)  # Nếu là ký tự toán hạng, thêm vào kết quả
            result *= char
        elseif char == "("  # Nếu là dấu mở ngoặc, đẩy vào ngăn xếp
            push!(stack, char)
        elseif char == ")"  # Nếu là dấu đóng ngoặc
            # Pop các phép toán từ ngăn xếp cho đến khi gặp dấu mở ngoặc
            while !isempty(stack) && stack[end] != "("
                result *= pop!(stack)
            end
            pop!(stack)  # Bỏ dấu mở ngoặc
        else  # Nếu là phép toán
            # Pop các phép toán có độ ưu tiên cao hơn hoặc bằng và thêm vào kết quả
            while !isempty(stack) && precedence(stack[end]) >= precedence(char)
                result *= pop!(stack)
            end
            push!(stack, char)  # Đẩy phép toán hiện tại vào ngăn xếp
        end
    end

    # Pop tất cả các phép toán còn lại trong ngăn xếp vào kết quả
    while !isempty(stack)
        result *= pop!(stack)
    end

    return result
end

# Đọc số bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    exp = readline()  # Đọc vào biểu thức
    println(infix_to_postfix(exp))  # In kết quả hậu tố
end
