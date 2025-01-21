function insertion_sort!(arr)
    n = length(arr)  
    for i in 2:n 
        key = arr[i]  
        j = i - 1  

        while j >= 1 && arr[j] > key
            arr[j + 1] = arr[j] 
            j -= 1  
        end

        arr[j + 1] = key  
    end
end

arr = [5, 6, 9, 1, 2, 3, 25, 62, 78, 90]
println("Mảng ban đầu: ", arr)


start_time = time()  
insertion_sort!(arr)  
end_time = time() 

println("Mảng sau khi sắp xếp: ", arr)


elapsed_time = end_time - start_time
println("Thời gian thực thi: $elapsed_time giây.")
