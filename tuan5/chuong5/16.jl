function largest_rectangle_area(H::Vector{Int})
    stack = []  # Ngăn xếp để lưu vị trí các cột
    max_area = 0
    n = length(H)
    
    for i in 1:n
        while !isempty(stack) && H[stack[end]] >= H[i]
            h = H[stack[end]]
            pop!(stack)
            w = i
            if !isempty(stack)
                w -= stack[end] + 1
            end
            max_area = max(max_area, h * w)
        end
        push!(stack, i)
    end
    
    while !isempty(stack)
        h = H[stack[end]]
        pop!(stack)
        w = n
        if !isempty(stack)
            w -= stack[end] + 1
        end
        max_area = max(max_area, h * w)
    end
    
    return max_area
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    N = parse(Int, readline())  # Đọc số cột
    H = parse.(Int, split(readline()))  # Đọc mảng chiều cao
    println(largest_rectangle_area(H))  # In kết quả diện tích lớn nhất
end
