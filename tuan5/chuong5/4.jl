function generate_expressions(expr::String)
    results = Set()  # Sử dụng Set để lưu trữ các biểu thức duy nhất

    # Hàm kiểm tra xem biểu thức có dấu ngoặc hợp lệ hay không
    function valid_parentheses_expression(expr::String)
        return expr != "" && expr[1] == '(' && expr[end] == ')'
    end

    # Đệ quy để loại bỏ dấu ngoặc
    function remove_parentheses(expr::String)
        # Nếu biểu thức đã không còn dấu ngoặc, trả về biểu thức
        if !contains(expr, "(")
            push!(results, expr)
            return
        end
        
        # Duyệt qua tất cả các dấu ngoặc
        for i in 1:length(expr)
            if expr[i] == '('
                # Tìm cặp ngoặc đóng tương ứng
                count = 1
                for j in i+1:length(expr)
                    if expr[j] == '('
                        count += 1
                    elseif expr[j] == ')'
                        count -= 1
                    end
                    
                    # Nếu gặp dấu ngoặc đóng hợp lệ
                    if count == 0
                        # Loại bỏ cặp ngoặc và thử lại
                        new_expr = expr[1:i-1] * expr[i+1:j-1] * expr[j+1:end]
                        remove_parentheses(new_expr)  # Đệ quy với biểu thức mới
                        break
                    end
                end
            end
        end
    end

    # Bắt đầu xử lý từ biểu thức ban đầu
    remove_parentheses(expr)
    return sort(collect(results))  # Sắp xếp các biểu thức theo thứ tự từ điển
end

# Đọc vào biểu thức
input_expr = readline()

# Gọi hàm và in kết quả
results = generate_expressions(input_expr)
for res in results
    println(res)
end
