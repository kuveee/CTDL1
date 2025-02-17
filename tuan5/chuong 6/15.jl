using Primes
using DataStructures

function is_prime(num::Int)
    return isprime(num)
end

function min_prime_transform(S::Int, T::Int)
    queue = Queue()
    visited = Set()
    enqueue!(queue, (S, 0))  # Number and steps count
    visited += S

    while !isempty(queue)
        current, steps = dequeue!(queue)

        if current == T
            return steps
        end

        for i in 1:4
            for d in 0:9
                new_number = convert_number(current, i, d)
                if new_number != current && is_prime(new_number) && !(new_number in visited)
                    enqueue!(queue, (new_number, steps + 1))
                    visited += new_number
                end
            end
        end
    end
    return -1
end

function convert_number(number::Int, pos::Int, digit::Int)
    num_str = string(number)
    return parse(Int, replace(num_str[pos], '0' => string(digit)))
end

# Example usage:
println(min_prime_transform(1033, 8179))  # Output: 6
println(min_prime_transform(1033, 8779))  # Output: 5
