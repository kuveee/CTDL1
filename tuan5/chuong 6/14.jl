function generate_lucky_numbers_desc(n::Int, current::String)
    if length(current) == n
        return [current]
    end
    numbers = []
    for digit in ['6', '8']
        push!(numbers, generate_lucky_numbers_desc(n, current * digit)...)
    end
    return numbers
end

function lucky_numbers_up_to_n_desc(T::Int, queries::Vector{Int})
    for n in queries
        result = []
        for i in 1:n
            append!(result, generate_lucky_numbers_desc(i, ""))
        end
        println(length(result))
        println(sort(result, rev=true))
    end
end

# Example usage:
T = 2
queries = [2, 3]
lucky_numbers_up_to_n_desc(T, queries)
