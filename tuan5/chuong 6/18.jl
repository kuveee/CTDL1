function rotate(arr::Vector{Int})
    return [arr[4], arr[1], arr[2], arr[3]]
end

function bfs(start::Vector{Int}, target::Vector{Int})
    visited = Set()
    queue = [(start, 0)]  # Lưu trạng thái hiện tại và số bước
    visited += Tuple(start)

    while !isempty(queue)
        current, steps = popfirst!(queue)

        if current == target
            return steps
        end

        # Quay các miếng ghép
        for i in 1:2
            next_state = current
            next_state[i:i+3] = rotate(current[i:i+3])  # Quay miếng ghép thứ i
            if !(Tuple(next_state) in visited)
                push!(queue, (next_state, steps + 1))
                visited += Tuple(next_state)
            end
        end
    end
    return -1
end

# Ví dụ cách sử dụng:
start = [1, 2, 3, 4, 5, 6]
target = [4, 1, 2, 6, 5, 3]
println(bfs(start, target))  # Output: 2
