function decode_string(s::String)
    stack = []  # Ngăn xếp để lưu các xâu con và số lần lặp
    num = 0  # Số lần lặp lại
    current_str = ""  # Xâu con hiện tại
    
    for c in s
        if c == '['
            push!(stack, (current_str, num))  # Lưu xâu con và số lần lặp
            current_str = ""  # Làm mới xâu con
            num = 0  # Làm mới số lần lặp
        elseif c == ']'
            prev_str, repeat_times = pop!(stack)  # Lấy xâu con và số lần lặp
            current_str = prev_str * repeat_times * current_str  # Giải mã xâu con
        elseif isdigit(c)
            num = num * 10 + parse(Int, string(c))  # Tính số lần lặp
        else
            current_str *= c  # Thêm ký tự vào xâu con hiện tại
        end
    end
    
    return current_str
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    str = readline()  # Đọc xâu mã hóa
    println(decode_string(str))  # In kết quả giải mã
end
