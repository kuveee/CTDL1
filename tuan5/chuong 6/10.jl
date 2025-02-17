using DataStructures

function min_days_to_grow(grid::Array{Int, 2})
    rows, cols = size(grid)
    queue = Queue()
    days = 0
    directions = [(0, 1), (0, -1), (1, 0), (-1, 0)]  # Right, Left, Down, Up
    
    for i in 1:rows
        for j in 1:cols
            if grid[i, j] == 2
                enqueue!(queue, (i, j))
            end
        end
    end
    
    while !isempty(queue)
        size = length(queue)
        for _ in 1:size
            x, y = dequeue!(queue)
            for (dx, dy) in directions
                nx, ny = x + dx, y + dy
                if nx >= 1 && ny >= 1 && nx <= rows && ny <= cols && grid[nx, ny] == 1
                    grid[nx, ny] = 2
                    enqueue!(queue, (nx, ny))
                end
            end
        end
        days += 1
    end
    
    for i in 1:rows
        for j in 1:cols
            if grid[i, j] == 1
                return -1
            end
        end
    end
    return days - 1
end

# Example usage:
grid = [
    [2, 1, 0, 2, 1],
    [1, 0, 1, 2, 1],
    [1, 0, 0, 2, 1]
]
println(min_days_to_grow(grid))  # Output should be 6
