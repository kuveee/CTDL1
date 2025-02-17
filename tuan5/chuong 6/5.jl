function min_operations(S::Int, T::Int)
    if S >= T
        return S - T
    end
    queue = [(S, 0)]
    visited = Set([S])
    
    while !isempty(queue)
        current, steps = popfirst!(queue)
        if current == T
            return steps
        end
        if !in(visited, current * 2)
            push!(queue, (current * 2, steps + 1))
            push!(visited, current * 2)
        end
        if !in(visited, current - 1) && current > 0
            push!(queue, (current - 1, steps + 1))
            push!(visited, current - 1)
        end
    end
end

# Đọc số lượng test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    S, T = split(readline()) |> x -> (parse(Int, x[1]), parse(Int, x[2]))  # Đọc S và T
    println(min_operations(S, T))  # In ra số bước ít nhất
end
