function stock_span(N::Int, A::Vector{Int})
    span = fill(0, N)
    stack = []
    
    for i in 1:N
        while !isempty(stack) && A[stack[end]] <= A[i]
            pop!(stack)
        end
        span[i] = isempty(stack) ? i + 1 : i - stack[end]
        push!(stack, i)
    end
    
    return span
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    N = parse(Int, readline())  # Đọc số ngày
    A = parse.(Int, split(readline()))  # Đọc giá chứng khoán
    println(join(stock_span(N, A)))  # In nhịp chứng khoán
end
