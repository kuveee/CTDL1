function smallest_multiple_of_9_and_0(N::Int)
    queue = ["9"]
    while !isempty(queue)
        num_str = popfirst!(queue)
        num = parse(Int, num_str)
        if num % N == 0
            return num_str
        end
        push!(queue, num_str * "0", num_str * "9")
    end
end

# Đọc số lượng test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    N = parse(Int, readline())  # Đọc giá trị N
    println(smallest_multiple_of_9_and_0(N))  # In ra số X nhỏ nhất chia hết cho N
end
