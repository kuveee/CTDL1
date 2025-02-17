function valid_number(K::Int)
    digits = digits(K, 10)
    return all(digit -> digit <= 5, digits) && length(digits) == length(unique(digits))
end

function count_valid_numbers(L::Int, R::Int)
    count = 0
    for K in L:R
        if valid_number(K)
            count += 1
        end
    end
    return count
end

# Example usage:
println(count_valid_numbers(4, 13))  # Output should be 5
