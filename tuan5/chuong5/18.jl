function find_next_higher_frequency(n::Int, A::Vector{Int})
    frequency = Dict{Int, Int}()
    next_higher_freq = fill(-1, n)
    
    for num in A
        frequency[num] = get(frequency, num, 0) + 1
    end
    
    stack = []  # Ngăn xếp chứa các phần tử
    
    for i in n:-1:1
        while !isempty(stack) && frequency[A[stack[end]]] <= frequency[A[i]]
            pop!(stack)
        end
        if !isempty(stack)
            next_higher_freq[i] = A[stack[end]]
        end
        push!(stack, i)
    end
    
    return next_higher_freq
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    n = parse(Int, readline())  # Đọc số phần tử
    A = parse.(Int, split(readline()))  # Đọc mảng A[]
    
    result = find_next_higher_frequency(n, A)
    println(join(result))
end
