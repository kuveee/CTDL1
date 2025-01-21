# Khởi tạo một stack rỗng
my_stack = String[]  # Hoặc Vector{String}()

# Thêm phần tử vào stack (push)
push!(my_stack, "Hello")
push!(my_stack, "World")
push!(my_stack, "!")

println("Stack hiện tại: ", my_stack)

# Lấy phần tử ra khỏi stack (pop)
last_element = pop!(my_stack)
println("Phần tử lấy ra: ", last_element)

println("Stack sau khi pop: ", my_stack)

# Kiểm tra stack có rỗng không
println("Stack có rỗng không? ", isempty(my_stack))

# Lấy phần tử trên đỉnh stack mà không xóa (peek)
top_element = last(my_stack) 
println("Phần tử trên đỉnh stack: ", top_element)