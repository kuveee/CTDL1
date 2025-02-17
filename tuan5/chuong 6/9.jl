using LightGraphs
using GraphPlot

function min_steps_to_target(grid::Array{Char,2}, a::Int, b::Int, c::Int, d::Int)
    N, M = size(grid)
    g = SimpleGraph(N*M)
    for i in 1:N
        for j in 1:M
            idx = (i-1)*M + j
            if grid[i, j] == '.'
                if i > 1 && grid[i-1, j] == '.'
                    add_edge!(g, idx, (i-2)*M + j)
                end
                if i < N && grid[i+1, j] == '.'
                    add_edge!(g, idx, i*M + j)
                end
                if j > 1 && grid[i, j-1] == '.'
                    add_edge!(g, idx, (i-1)*M + j-1)
                end
                if j < M && grid[i, j+1] == '.'
                    add_edge!(g, idx, (i-1)*M + j+1)
                end
            end
        end
    end
    start_idx = (a-1)*M + b
    end_idx = (c-1)*M + d
    return bfs(g, start_idx, end_idx).nlevels - 1
end

# Example usage:
grid = [
    ".X.",
    ".X.",
    "..."
]
println(min_steps_to_target(grid, 1, 1, 1, 3))  # Output should be 3
