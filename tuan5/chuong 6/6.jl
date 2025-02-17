function min_operations_to_one(N::Int)
    operations = 0
    while N > 1
        found = false
        for i in 2:floor(Int, sqrt(N))
            if N % i == 0
                N = maximum([i, N ÷ i])
                operations += 1
                found = true
                break
            end
        end
        if !found
            N -= 1
            operations += 1
        end
    end
    return operations
end

# Example usage:
println(min_operations_to_one(17)) # Output should be 4
