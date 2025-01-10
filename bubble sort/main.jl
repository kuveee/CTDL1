function bubble_sort!(arr)
    n = length(arr)
    for i in 1:(n-1)  # Lặp qua các phần tử, từ đầu đến trước phần cuối
        for j in 1:(n-i)  # So sánh từng cặp phần tử liên tiếp
            if arr[j] > arr[j+1]
                # Hoán đổi nếu phần tử trước lớn hơn phần tử sau
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
            end
        end
    end
end

# Sử dụng
arr = [5, 1, 4, 2, 8]
println("Before sorted: ", arr)

bubble_sort!(arr)
println("After sorted: ", arr)
