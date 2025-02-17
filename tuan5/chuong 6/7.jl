using Graphs

function min_transform_steps(S::Vector{String}, s::String, t::String)
    g = SimpleGraph(length(S))
    for i in 1:length(S)
        for j in i+1:length(S)
            if sum(S[i][k] != S[j][k] for k in 1:length(S[i])) == 1
                add_edge!(g, i, j)
            end
        end
    end
    s_idx = findfirst(x -> x == s, S)
    t_idx = findfirst(x -> x == t, S)
    return bfs(g, s_idx, t_idx).nlevels - 1
end

# Example usage:
S = ["POON", "TOON", "PLEE", "SAME", "POIE", "PLEA", "PLIE", "POIN"]
println(min_transform_steps(S, "TOON", "PLEA"))  # Output should be 7
