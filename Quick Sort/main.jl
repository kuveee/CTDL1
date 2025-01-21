
function partition(arr, low, high)
    pivot = arr[high]  
    i = low - 1 

    for j in low:high-1
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
        end
    end

    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1
end


function quick_sort(arr, low, high)
    if low < high
        pi = partition(arr, low, high)  

       
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)
    end
end


function print_array(arr)
    println(join(arr, " "))
end


arr = [10, 7, 8, 9, 1, 5]
println("Mảng ban đầu:")
print_array(arr)


quick_sort(arr, 1, length(arr))

println("Mảng đã được sắp xếp:")
print_array(arr)
