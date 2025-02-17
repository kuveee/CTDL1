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

function lucky_numbers_up_to_n(n::Int)
    result = []
    for i in 1:n
        append!(result, generate_lucky_numbers(i, ""))
    end
    return reverse(result)
end

# Example usage:
println(lucky_numbers_up_to_n(2))  # Output should be [88, 86, 68, 66, 8, 6]
