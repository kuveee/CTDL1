function count_bdn_less_than_n(n::Int)
    count = 0
    queue = ["1"]
    
    while !isempty(queue)
        num_str = popfirst!(queue)
        num = parse(Int, num_str)
        if num < n
            count += 1
            push!(queue, num_str * "0", num_str * "1")
        end
    end
    
    return count
end

# Đọc số lượng test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    N = parse(Int, readline())  # Đọc giá trị N
    println(count_bdn_less_than_n(N))  # In ra số lượng số BDN nhỏ hơn N
end
