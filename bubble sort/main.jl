
function bubble_sort!(arr)
    n = length(arr)
    for i in 1:(n-1) 
        for j in 1:(n-i)  
            if arr[j] > arr[j+1]
                
                temp = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = temp
            end
        end
    end
end


arr = [5, 1, 4, 2, 8]
println("Before sorted: ", arr)


start_time = time() 
bubble_sort!(arr) 
end_time = time()  

println("After sorted: ", arr)


elapsed_time = end_time - start_time
println("Time taken for sorting: $elapsed_time seconds.")
