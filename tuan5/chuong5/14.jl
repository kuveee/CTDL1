function find_min_number(S::String)
    stack = []  # Ngăn xếp để lưu các số
    result = []
    
    # Duyệt qua chuỗi S
    for i in 1:length(S)+1
        push!(stack, i)
        
        if i == length(S) + 1 || S[i] == 'I'  # Nếu gặp I hoặc hết chuỗi
            while !isempty(stack)
                push!(result, pop!(stack))
            end
        end
    end
    
    return join(result)  # Trả về số nhỏ nhất dưới dạng chuỗi
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    S = readline()  # Đọc chuỗi S
    println(find_min_number(S))  # In kết quả
end
