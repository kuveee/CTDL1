function count_parentheses_to_flip(S::String)
    open_count = 0  # Đếm số lượng dấu mở '(' dư thừa
    flip_count = 0  # Đếm số lượng dấu cần đổi

    for char in S
        if char == '('
            open_count += 1  # Dấu mở cần được khớp
        else  # char == ')'
            if open_count > 0
                open_count -= 1  # Dấu đóng khớp với dấu mở trước đó
            else
                flip_count += 1  # Dấu đóng không có dấu mở tương ứng, cần đổi thành dấu mở
            end
        end
    end

    # Sau khi duyệt xong, còn lại số dấu mở dư trong ngăn xếp
    flip_count += open_count  # Những dấu mở dư cần đổi thành dấu đóng
    return flip_count
end

# Đọc số lượng bộ test
T = parse(Int, readline())

# Xử lý từng bộ test
for _ in 1:T
    S = readline()  # Đọc vào xâu S
    println(count_parentheses_to_flip(S))  # In kết quả cho bộ test
end
