function print_binary_numbers(n::Int)
    for i in 1:n
        println(bin(i)[3:end])  # Lấy phần nhị phân từ vị trí thứ 3 (bỏ đi '0b')
    end
end

# Đọc số lượng test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    n = parse(Int, readline())  # Đọc giá trị n
    print_binary_numbers(n)  # In ra các số nhị phân từ 1 đến n
end
