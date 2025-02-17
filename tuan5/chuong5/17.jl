function longest_valid_parentheses(S::String)
    stack = [-1]  # Ngăn xếp chứa các chỉ số
    max_len = 0
    
    for i in 1:length(S)
        if S[i] == '('
            push!(stack, i)
        else
            pop!(stack)
            if isempty(stack)
                push!(stack, i)
            else
                max_len = max(max_len, i - stack[end])
            end
        end
    end
    
    return max_len
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    S = readline()  # Đọc chuỗi S
    println(longest_valid_parentheses(S))  # In kết quả chiều dài dãy ngoặc đúng dài nhất
end
