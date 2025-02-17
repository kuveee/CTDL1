function find_next_greater_smaller(n::Int, A::Vector{Int})
    next_greater = fill(-1, n)  # Mảng kết quả cho phần tử lớn hơn
    next_smaller = fill(-1, n)  # Mảng kết quả cho phần tử nhỏ hơn
    
    greater_stack = []  # Ngăn xếp cho phần tử lớn hơn
    smaller_stack = []  # Ngăn xếp cho phần tử nhỏ hơn
    
    # Tính toán phần tử lớn hơn
    for i in n:-1:1
        while !isempty(greater_stack) && greater_stack[end] <= A[i]
            pop!(greater_stack)
        end
        if !isempty(greater_stack)
            next_greater[i] = greater_stack[end]
        end
        push!(greater_stack, A[i])
    end
    
    # Tính toán phần tử nhỏ hơn
    for i in n:-1:1
        while !isempty(smaller_stack) && smaller_stack[end] >= A[i]
            pop!(smaller_stack)
        end
        if !isempty(smaller_stack)
            next_smaller[i] = smaller_stack[end]
        end
        push!(smaller_stack, A[i])
    end
    
    return next_greater, next_smaller
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    n = parse(Int, readline())  # Đọc số phần tử trong mảng
    A = parse.(Int, split(readline()))  # Đọc mảng A[]
    
    next_greater, next_smaller = find_next_greater_smaller(n, A)
    for i in 1:n
        print(next_smaller[i], " ")
    end
    println()
end
