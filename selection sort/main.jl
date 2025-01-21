function selection_sort!(arr)
    n = length(arr)
    for i in 1:n-1
        # Tìm vị trí phần tử nhỏ nhất trong phần chưa sắp xếp
        min_index = i
        for j in i+1:n
            if arr[j] < arr[min_index]
                min_index = j
            end
        end
        # Hoán đổi phần tử nhỏ nhất với phần tử đầu tiên của phần chưa sắp xếp
        arr[i], arr[min_index] = arr[min_index], arr[i]
    end
end

# Hàm in mảng
function print_array(arr)
    println(join(arr, " "))
end

# Ví dụ sử dụng
arr = [64, 25, 12, 22, 11]
println("Mảng ban đầu:")
print_array(arr)

selection_sort!(arr)

println("Mảng sau khi sắp xếp:")
print_array(arr)
