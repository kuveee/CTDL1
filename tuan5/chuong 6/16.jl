function min_steps_in_matrix(M::Int, N::Int, matrix::Array{Int, 2})
    queue = Queue()
    enqueue!(queue, (1, 1, 0))  # Position (i, j) and steps
    visited = Set()

    while !isempty(queue)
        i, j, steps = dequeue!(queue)
        
        if i == M && j == N
            return steps
        end

        visited += (i, j)

        for (di, dj) in [(0, 1), (1, 0)]
            ni, nj = i + di * matrix[i, j], j + dj * matrix[i, j]
            if ni >= 1 && ni <= M && nj >= 1 && nj <= N && !(ni, nj in visited)
                enqueue!(queue, (ni, nj, steps + 1))
            end
        end
    end
    return -1
end

# Example usage:
matrix = [
    [2, 1, 2],
    [1, 1, 1],
    [1, 1, 1]
]
println(min_steps_in_matrix(3, 3, matrix))  # Output: 2
