function longest_valid_parentheses(P::String)
    stack = [-1]  # Ngăn xếp chứa vị trí các dấu ngoặc
    max_len = 0
    
    for i in 1:length(P)
        if P[i] == '('
            push!(stack, i)  # Thêm chỉ số dấu mở ngoặc vào ngăn xếp
        else
            pop!(stack)  # Xóa dấu mở ngoặc cuối cùng
            if isempty(stack)
                push!(stack, i)  # Nếu không có dấu mở ngoặc tương ứng, cập nhật chỉ số hiện tại
            else
                max_len = max(max_len, i - stack[end])  # Tính độ dài biểu thức đúng
            end
        end
    end
    
    return max_len
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    P = readline()  # Đọc biểu thức
    println(longest_valid_parentheses(P))  # In tổng độ dài lớn nhất của biểu thức đúng
end
