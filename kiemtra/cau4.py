def levenshtein(source, target):
    # Khởi tạo ma trận D với kích thước (m+1) x (n+1)
    m, n = len(source), len(target)
    D = [[0] * (n + 1) for _ in range(m + 1)]
    
    # Khởi tạo hàng và cột đầu tiên
    for i in range(m + 1):
        D[i][0] = i
    for j in range(n + 1):
        D[0][j] = j

    # Điền ma trận D
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if source[i - 1] == target[j - 1]:
                cost = 0  # Không thay đổi khi các ký tự giống nhau
            else:
                cost = 1  # Chi phí thay thế khi các ký tự khác nhau
            
            # Chọn phép biến đổi có chi phí thấp nhất: xóa, thêm, thay thế
            D[i][j] = min(D[i - 1][j] + 1,    # Xóa
                           D[i][j - 1] + 1,    # Thêm
                           D[i - 1][j - 1] + cost)  # Thay thế

    # Khoảng cách Levenshtein là giá trị tại D[m][n]
    return D[m][n]

# Test ví dụ với chuỗi 'yu' và 'you'
source = "yu"
target = "you"
print("Khoảng cách Levenshtein:", levenshtein(source, target))
