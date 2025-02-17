function is_bdn(x::Int)
    return all(c in ['0', '1'] for c in string(x))
end

function find_bdn_multiple(N::Int)
    m = 1
    while true
        candidate = m * N
        if is_bdn(candidate)
            return candidate
        end
        m += 1
    end
end

# Đọc số lượng test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    N = parse(Int, readline())  # Đọc giá trị N
    println(find_bdn_multiple(N))  # In ra số BDN nhỏ nhất là bội của N
end
