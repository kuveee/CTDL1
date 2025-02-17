def count_bracket_reversals(s):
    open_brackets = 0
    close_brackets = 0  

    for c in s:
        if c == '(':
            open_brackets += 1  # Nếu là dấu mở, tăng biến đếm
        else:
            if open_brackets > 0:
                open_brackets -= 1  # Ghép với dấu '(' trước đó
            else:
                close_brackets += 1  # Dấu ')' không có cặp, cần sửa

    return (open_brackets + 1) // 2 + (close_brackets + 1) // 2  # Công thức tính số lần đổi

# Nhập số lượng test case
T = int(input())

for _ in range(T):
    s = input().strip()
    print(count_bracket_reversals(s))
