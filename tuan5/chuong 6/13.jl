function generate_lucky_numbers(n::Int, current::String)
    if length(current) == n
        return [current]
    end
    numbers = []
    for digit in ['6', '8']
        push!(numbers, generate_lucky_numbers(n, current * digit)...)
    end
    return numbers
end

function lucky_numbers_up_to_n(T::Int, queries::Vector{Int})
    for n in queries
        result = []
        for i in 1:n
            append!(result, generate_lucky_numbers(i, ""))
        end
        println(length(result))
        println(sort(result))
    end
end

# Example usage:
T = 2
queries = [6, 97]
lucky_numbers_up_to_n(T, queries)
